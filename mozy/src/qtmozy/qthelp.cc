
/*========================================================================
 *                                                                        *
 *  Distributed by Whiteley Research Inc., Sunnyvale, California, USA     *
 *                       http://wrcad.com                                 *
 *  Copyright (C) 2017 Whiteley Research Inc., all rights reserved.       *
 *  Author: Stephen R. Whiteley, except as indicated.                     *
 *                                                                        *
 *  As fully as possible recognizing licensing terms and conditions       *
 *  imposed by earlier work from which this work was derived, if any,     *
 *  this work is released under the Apache License, Version 2.0 (the      *
 *  "License").  You may not use this file except in compliance with      *
 *  the License, and compliance with inherited licenses which are         *
 *  specified in a sub-header below this one if applicable.  A copy       *
 *  of the License is provided with this distribution, or you may         *
 *  obtain a copy of the License at                                       *
 *                                                                        *
 *        http://www.apache.org/licenses/LICENSE-2.0                      *
 *                                                                        *
 *  See the License for the specific language governing permissions       *
 *  and limitations under the License.                                    *
 *                                                                        *
 *   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,      *
 *   EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES      *
 *   OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-        *
 *   INFRINGEMENT.  IN NO EVENT SHALL WHITELEY RESEARCH INCORPORATED      *
 *   OR STEPHEN R. WHITELEY BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER     *
 *   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,      *
 *   ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE       *
 *   USE OR OTHER DEALINGS IN THE SOFTWARE.                               *
 *                                                                        *
 *========================================================================*
 *               XicTools Integrated Circuit Design System                *
 *                                                                        *
 * Qt MOZY help viewer.
 *                                                                        *
 *========================================================================*
 $Id:$
 *========================================================================*/

#include "qthelp.h"
#include "qtviewer.h"
#include "qtinterf/qtfile.h"
#include "qtinterf/qtfont.h"
#include "qtinterf/qtinput.h"
#include "qtinterf/qtlist.h"
#include "queue_timer.h"

#include "help/help_startup.h"
#include "help/help_cache.h"
#include "help/help_topic.h"
#include "httpget/transact.h"
#include "miscutil/pathlist.h"
#include "miscutil/filestat.h"

#include <QApplication>
#include <QLayout>
#include <QMenu>
#include <QMenuBar>
#include <QToolBar>
#include <QToolButton>
#include <QStatusBar>
#include <QResizeEvent>
#include <QScrollBar>
#include <QActionGroup>

#include <fcntl.h>
#include <sys/stat.h>
#include <errno.h>
#include <unistd.h>


/*=======================================================================
 =
 =  HTML Viewer for WWW and Help System
 =
 =======================================================================*/

// Help keywords used in this file
//  helpsys

// Architecture note
// Each QThelpDlg has a corresponding "root_topic" topic struct
// linked into HLP()->context()->TopList.  In these topics, the
// context field points back to the QThelpDlg.  Each new page
// displayed in the QThelpDlg window has a corresponding topic struct
// linked from lastborn in the root_topic, and has the cur_topic field
// set to point to the topic.  Topics linked to lastborn do not have
// the context field set.

static queue_timer QueueTimer;
QueueLoop &HLPcontext::hcxImageQueueLoop = QueueTimer;

// Initiate queue processing.
//
void
queue_timer::start()
{
    if (!timer) {
        timer = new QTimer(0);
        timer->setInterval(50);
        connect(timer, SIGNAL(timeout()), this, SLOT(run_queue_slot()));
    }
    timer->start();
}


// Suspend queue processing.  Have to do this while downloading or QT
// will block in the Transaction event loop.
//
void
queue_timer::suspend()
{
    if (timer)
        timer->stop();
}


// Resume queue processing.
//
void
queue_timer::resume()
{
    if (timer)
        timer->start();
}


// Process the queue until empty.
//
void
queue_timer::run_queue_slot()
{
    if (!HLP()->context()->processList()) {
        delete timer;
        timer = 0;
    }
}


//-----------------------------------------------------------------------------
// Local classes

namespace qtinterf
{
    class action_item : public QAction
    {
    public:
        action_item(HLPbookMark *b, QObject *prnt) : QAction(prnt)
        {
            ai_bookmark = b;
            QString qs = QString(b->title);
            qs.truncate(32);
            setText(qs);
        }

        ~action_item()
        {
            ai_bookmark =
                HLP()->context()->bookmarkUpdate(0, ai_bookmark->url);
            delete ai_bookmark;
        }

        void setBookmark(HLPbookMark *b) { ai_bookmark = b; }
        HLPbookMark *bookmark() { return (ai_bookmark); }

    private:
        HLPbookMark *ai_bookmark;
    };
}


//-----------------------------------------------------------------------------
// Local declarations

// XPM 
static const char * const forward_xpm[] = {
"16 16 4 1",
" 	c none",
".	c #0000dd",
"x	c #0000ee",
"+  c #0000ff",
"                ",
"    .+          ",
"    .x+         ",
"    .xx+        ",
"    .xxx+       ",
"    .xxxx+      ",
"    .xxxxx+     ",
"    .xxxxxx.    ",
"    .xxxxx.     ",
"    .xxxx.      ",
"    .xxx.       ",
"    .xx.        ",
"    .x.         ",
"    ..          ",
"                ",
"                "};

// XPM 
static const char * const backward_xpm[] = {
"16 16 4 1",
" 	c none",
".	c #0000dd",
"x	c #0000ee",
"+  c #0000ff",
"                ",
"          +.    ",
"         +x.    ",
"        +xx.    ",
"       +xxx.    ",
"      +xxxx.    ",
"     +xxxxx.    ",
"    .xxxxxx.    ",
"     .xxxxx.    ",
"      .xxxx.    ",
"       .xxx.    ",
"        .xx.    ",
"         .x.    ",
"          ..    ",
"                ",
"                "};

// XPM
static const char * const stop_xpm[] = {
"16 16 4 1",
" 	c none",
".	c red",
"x  c pink",
"+  c black",
"                ",
"     xxxxxx     ",
"    x......x    ",
"   x........x   ",
"  x..........x  ",
" x............x ",
" x............x ",
" x............x ",
" x............x ",
" x............x ",
" x............x ",
"  x..........x  ",
"   x........x   ",
"    x......x    ",
"     xxxxxx     ",
"                "};

//-----------------------------------------------------------------------------
// Exports

// Top level help popup call, takes care of accessing the database. 
// Return false if the topic is not found
//
bool
QTbag::PopUpHelp(const char *wordin)
{
    if (!HLP()->get_path(0)) {
        PopUpErr(MODE_ON, "Error: no path to database.");
        HLP()->context()->quitHelp();
        return (false);
    }
    char buf[256];
    buf[0] = 0;
    char *word = buf;
    if (wordin) {
        strcpy(buf, wordin);
        char *s = buf + strlen(buf) - 1;
        while (*s == ' ')
            *s-- = '\0';
    }

    HLPtopic *top = 0;
    if (HLP()->context()->resolveKeyword(word, &top, 0, 0, 0, false, true))
        return (false);
    if (!top) {
        if (word && *word)
            snprintf(buf, 256, "Error: No such topic: %s\n", word);
        else
            snprintf(buf, 256, "Error: no top level topic\n");
        PopUpErr(MODE_ON, buf);
        return (false);
    }
    top->show_in_window();
    return (true);
}


HelpWidget *
HelpWidget::get_widget(HLPtopic *top)
{
    if (!top)
        return (0);
    return (dynamic_cast<QThelpDlg*>(HLPtopic::get_parent(top)->context()));
}


HelpWidget *
HelpWidget::new_widget(GRwbag **ptr, int, int)
{
    QWidget *parent = 0;
    if (GRpkg::self()->MainWbag()) {
        QTbag *wb = dynamic_cast<QTbag*>(GRpkg::self()->MainWbag());
        if (wb)
            parent = wb->Shell();
    }

    QThelpDlg *w = new QThelpDlg(true, parent);
    if (ptr)
        *ptr = w;
    w->show();
    return (w);
}


//-----------------------------------------------------------------------------
// Constructor/destrucor

namespace {
    void sens_set(QTbag *wp, bool set, int)
    {
        QThelpDlg *w = dynamic_cast<QThelpDlg*>(wp);
        if (w)
            w->menu_sens_set(set);
    }
}


#ifdef __APPLE__
#define USE_QTOOLBAR
#endif


QThelpDlg::QThelpDlg(bool has_menu, QWidget *prnt) : QDialog(prnt),
    QTbag()
{
    // If has_menu is false, the widget will not have the menu or the
    // status bar visible.

    wb_shell = this;
    h_params = 0;
    h_root_topic = 0;
    h_cur_topic = 0;
    h_stop_btn_pressed = false;
    h_is_frame = !has_menu;
    h_cache_list = 0;
    h_frame_array = 0;
    h_frame_array_size = 0;
    h_frame_parent = 0;
    h_frame_name = 0;

    wb_sens_set = ::sens_set;

    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(2, 2, 2, 2);
    vbox->setSpacing(2);
#ifdef USE_QTOOLBAR
    QToolBar *menubar = new QToolBar();
    vbox->addWidget(menubar);
    menubar->setMaximumHeight(24);
#else
    QMenuBar *menubar = new QMenuBar();
    vbox->setMenuBar(menubar);
#endif
    if (!has_menu)
        menubar->hide();
    else {
        int xx = 0, yy = 0;
        if (prnt) {
            QRect r = prnt->geometry();
            xx = r.left();
            yy = r.top();
        }
        xx += 50;
        yy += 50;
        setWindowFlags(Qt::Dialog);
        move(xx, yy);
    }

    h_viewer = new QTviewer(HLP_DEF_WIDTH, HLP_DEF_HEIGHT, this, this);
    vbox->addWidget(h_viewer);
    h_status_bar = new QStatusBar(this);
    vbox->addWidget(h_status_bar);
    if (!has_menu)
        h_status_bar->hide();

    if (!h_is_frame)
        h_params = new HLPparams(HLP()->no_file_fonts());

    h_viewer->freeze();

    h_Backward = menubar->addAction(tr("back"),
        this, SLOT(backward_slot()));
    h_Backward->setIcon(QIcon(QPixmap(backward_xpm)));

    h_Forward = menubar->addAction(tr("forw"),
        this, SLOT(forward_slot()));
    h_Forward->setIcon(QIcon(QPixmap(forward_xpm)));

    h_Stop = menubar->addAction(tr("stop"),
        this, SLOT(stop_slot()));
    h_Stop->setIcon(QIcon(QPixmap(stop_xpm)));

#ifdef USE_QTOOLBAR
    QAction *a = menubar->addAction(tr("&File"));
    h_main_menus[0] = new QMenu();
    a->setMenu(h_main_menus[0]);
    QToolButton *tb = dynamic_cast<QToolButton*>(menubar->widgetForAction(a));
    if (tb)
        tb->setPopupMode(QToolButton::InstantPopup);
#else
    h_main_menus[0] = menubar->addMenu(tr("&File"));
#endif
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    h_Open = h_main_menus[0]->addAction(tr("&Open"), Qt::CTRL|Qt::Key_O,
        this, SLOT(open_slot()));
    h_OpenFile = h_main_menus[0]->addAction(tr("Open &File"),
        Qt::CTRL|Qt::Key_F, this, SLOT(open_file_slot()));
    h_Save = h_main_menus[0]->addAction(tr("&Save"), Qt::CTRL|Qt::Key_S,
        this, SLOT(save_slot()));
    h_Print = h_main_menus[0]->addAction(tr("&Print"), Qt::CTRL|Qt::Key_P,
        this, SLOT(print_slot()));
    h_Reload = h_main_menus[0]->addAction(tr("&Reload"), Qt::CTRL|Qt::Key_R,
        this, SLOT(reload_slot()));
    h_main_menus[0]->addSeparator();
    h_Quit = h_main_menus[0]->addAction(tr("&Quit"), Qt::CTRL|Qt::Key_Q,
        this, SLOT(quit_slot()));
#else
    h_Open = h_main_menus[0]->addAction(tr("&Open"), this,
        SLOT(open_slot()), Qt::CTRL|Qt::Key_O);
    h_OpenFile = h_main_menus[0]->addAction(tr("Open &File"), this,
        SLOT(open_file_slot()),  Qt::CTRL|Qt::Key_F);
    h_Save = h_main_menus[0]->addAction(tr("&Save"), this,
        SLOT(save_slot()), Qt::CTRL|Qt::Key_S);
    h_Print = h_main_menus[0]->addAction(tr("&Print"), this,
        SLOT(print_slot()), Qt::CTRL|Qt::Key_P);
    h_Reload = h_main_menus[0]->addAction(tr("&Reload"), this,
        SLOT(reload_slot()), Qt::CTRL|Qt::Key_R);
    h_main_menus[0]->addSeparator();
    h_Quit = h_main_menus[0]->addAction(tr("&Quit"), this,
        SLOT(quit_slot()), Qt::CTRL|Qt::Key_Q);
#endif

#ifdef USE_QTOOLBAR
    a = menubar->addAction(tr("&Options"));
    h_main_menus[1] = new QMenu();
    a->setMenu(h_main_menus[1]);
    tb = dynamic_cast<QToolButton*>(menubar->widgetForAction(a));
    if (tb)
        tb->setPopupMode(QToolButton::InstantPopup);
#else
    h_main_menus[1] = menubar->addMenu(tr("&Options"));
#endif
    h_Search = h_main_menus[1]->addAction(tr("S&earch"),
        this, SLOT(search_slot()));
    h_FindText = h_main_menus[1]->addAction(tr("Find Text"),
        this, SLOT(find_slot()));
    h_SetFont = h_main_menus[1]->addAction(tr("Set &Font"));
    h_SetFont->setCheckable(true);
    connect(h_SetFont, SIGNAL(toggled(bool)),
        this, SLOT(set_font_slot(bool)));
    h_DontCache = h_main_menus[1]->addAction(tr("&Don't Cache"));
    h_DontCache->setCheckable(true);
    connect(h_DontCache, SIGNAL(toggled(bool)),
        this, SLOT(dont_cache_slot(bool)));
    h_DontCache->setChecked(h_params->NoCache);
    h_ClearCache = h_main_menus[1]->addAction(tr("&Clear Cache"),
        this, SLOT(clear_cache_slot()));
    h_ReloadCache = h_main_menus[1]->addAction(tr("&Reload Cache"),
        this, SLOT(reload_cache_slot()));
    h_ShowCache = h_main_menus[1]->addAction(tr("Show Cache"),
        this, SLOT(show_cache_slot()));
    h_main_menus[1]->addSeparator();
    h_NoCookies = h_main_menus[1]->addAction(tr("No Cookies"));
    h_NoCookies->setCheckable(true);
    connect(h_NoCookies, SIGNAL(toggled(bool)),
        this, SLOT(no_cookies_slot(bool)));
    h_NoCookies->setChecked(h_params->NoCookies);

    QActionGroup *ag = new QActionGroup(this);
    h_NoImages = h_main_menus[1]->addAction(tr("No Images"));
    h_NoImages->setCheckable(true);
    connect(h_NoImages, SIGNAL(toggled(bool)),
        this, SLOT(no_images_slot(bool)));
    ag->addAction(h_NoImages);
    h_SyncImages = h_main_menus[1]->addAction(tr("Sync Images"));
    h_SyncImages->setCheckable(true);
    connect(h_SyncImages, SIGNAL(toggled(bool)),
        this, SLOT(sync_images_slot(bool)));
    ag->addAction(h_SyncImages);
    h_DelayedImages =
        h_main_menus[1]->addAction(tr("Delayed Images"));
    h_DelayedImages->setCheckable(true);
    connect(h_DelayedImages, SIGNAL(toggled(bool)),
        this, SLOT(delayed_images_slot(bool)));
    ag->addAction(h_DelayedImages);
    h_ProgressiveImages =
        h_main_menus[1]->addAction(tr("Progressive Images"));
    h_ProgressiveImages->setCheckable(true);
    connect(h_ProgressiveImages, SIGNAL(toggled(bool)),
        this, SLOT(progressive_images_slot(bool)));
    ag->addAction(h_ProgressiveImages);
    if (h_params->LoadMode == HLPparams::LoadProgressive)
        h_ProgressiveImages->setChecked(true);
    else if (h_params->LoadMode == HLPparams::LoadDelayed)
        h_DelayedImages->setChecked(true);
    else if (h_params->LoadMode == HLPparams::LoadSync)
        h_SyncImages->setChecked(true);
    else
        h_NoImages->setChecked(true);

    h_main_menus[1]->addSeparator();

    ag = new QActionGroup(this);
    h_AnchorPlain = h_main_menus[1]->addAction(tr("Anchor Plain"));
    h_AnchorPlain->setCheckable(true);
    connect(h_AnchorPlain, SIGNAL(toggled(bool)),
        this, SLOT(anchor_plain_slot(bool)));
    ag->addAction(h_AnchorPlain);
    h_AnchorButtons =
        h_main_menus[1]->addAction(tr("Anchor Buttons"));
    h_AnchorButtons->setCheckable(true);
    connect(h_AnchorButtons, SIGNAL(toggled(bool)),
        this, SLOT(anchor_buttons_slot(bool)));
    ag->addAction(h_AnchorButtons);
    h_AnchorUnderline =
        h_main_menus[1]->addAction(tr("Anchor Underline"));
    h_AnchorUnderline->setCheckable(true);
    connect(h_AnchorUnderline, SIGNAL(toggled(bool)),
        this, SLOT(anchor_underline_slot(bool)));
    ag->addAction(h_AnchorUnderline);
    if (h_params->AnchorButtons)
        h_AnchorButtons->setChecked(true);
    else if (h_params->AnchorUnderlined)
        h_AnchorUnderline->setChecked(true);
    else
        h_AnchorPlain->setChecked(true);

    h_AnchorHighlight =
        h_main_menus[1]->addAction(tr("Anchor Highlight"));
    h_AnchorHighlight->setCheckable(true);
    connect(h_AnchorHighlight, SIGNAL(toggled(bool)),
        this, SLOT(anchor_highlight_slot(bool)));
    h_AnchorHighlight->setChecked(h_params->AnchorHighlight);
    h_BadHTML = h_main_menus[1]->addAction(tr("Bad HTML Warnings"));
    h_BadHTML->setCheckable(true);
    connect(h_BadHTML, SIGNAL(toggled(bool)),
        this, SLOT(bad_html_slot(bool)));
    h_BadHTML->setChecked(h_params->BadHTMLwarnings);
    h_FreezeAnimations =
        h_main_menus[1]->addAction(tr("Freeze Animations"));
    h_FreezeAnimations->setCheckable(true);
    connect(h_FreezeAnimations, SIGNAL(toggled(bool)),
        this, SLOT(freeze_animations_slot(bool)));
    h_FreezeAnimations->setChecked(h_params->FreezeAnimations);
    h_LogTransactions =
        h_main_menus[1]->addAction(tr("Log Transactions"));
    h_LogTransactions->setCheckable(true);
    connect(h_LogTransactions, SIGNAL(toggled(bool)),
        this, SLOT(log_transactions_slot(bool)));
    h_LogTransactions->setChecked(h_params->PrintTransact);

#ifdef USE_QTOOLBAR
    a = menubar->addAction(tr("&Bookmarks"));
    h_main_menus[2] = new QMenu();
    a->setMenu(h_main_menus[2]);
    tb = dynamic_cast<QToolButton*>(menubar->widgetForAction(a));
    if (tb)
        tb->setPopupMode(QToolButton::InstantPopup);
#else
    h_main_menus[2] = menubar->addMenu(tr("&Bookmarks"));
#endif
    h_AddBookmark = h_main_menus[2]->addAction(tr("Add"),
        this, SLOT(add_slot()));
    h_DeleteBookmark = h_main_menus[2]->addAction(tr("Delete"),
        this, SLOT(delete_slot()));
    h_DeleteBookmark->setCheckable(true);
    h_main_menus[2]->addSeparator();

    menubar->addSeparator();
#ifdef USE_QTOOLBAR
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    menubar->addAction(tr("Help"), Qt::CTRL|Qt::Key_H, this, SLOT(help_slot()));
#else
    a = menubar->addAction(tr("&Help"), this, SLOT(help_slot()));
    a->setShortcut(QKeySequence("Ctrl+H"));
#endif
#else
    h_main_menus[3] = menubar->addMenu(tr("&Help"));
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    h_Help = h_main_menus[3]->addAction(tr("&Help"), Qt::CTRL|Qt::Key_H,
        this, SLOT(help_slot()));
#else
    h_Help = h_main_menus[3]->addAction(tr("&Help"), this,
        SLOT(help_slot()), Qt::CTRL|Qt::Key_H);
#endif
#endif

    h_viewer->thaw();

    HLP()->context()->readBookmarks();
    for (HLPbookMark *b = HLP()->context()->bookmarks(); b; b = b->next) {
        QString qs = QString(b->title);
        qs.truncate(32);
        h_main_menus[2]->addAction(
            new action_item(b, h_main_menus[2]));
    }
    connect(h_main_menus[2], SIGNAL(triggered(QAction*)), this,
        SLOT(bookmark_slot(QAction*)));

    h_Backward->setEnabled(false);
    h_Forward->setEnabled(false);
    h_Stop->setEnabled(false);
}


QThelpDlg::~QThelpDlg()
{
    HLP()->context()->quitHelp();
    FC.unregisterCallback(h_viewer, FNT_MOZY);
    FC.unregisterCallback(h_viewer, FNT_MOZY_FIXED);
    halt_images();
    HLP()->context()->removeTopic(h_root_topic);
    if (!h_is_frame)
        delete h_params;

    if (h_frame_array) {
        for (int i = 0; i < h_frame_array_size; i++)
            delete h_frame_array[i];
        delete [] h_frame_array;
    }
    delete [] h_frame_name;
}


void
QThelpDlg::menu_sens_set(bool set)
{
    h_Search->setEnabled(set);
    h_Save->setEnabled(set);
    h_Open->setEnabled(set);
    h_FindText->setEnabled(set);
}


//-----------------------------------------------------------------------------
// ViewWidget and HelpWidget virtual function overrides

void
QThelpDlg::freeze()
{
    h_viewer->freeze();
}


void
QThelpDlg::thaw()
{
    h_viewer->thaw();
}


// Set a pointer to the Transaction struct.
//
void
QThelpDlg::set_transaction(Transaction *t, const char *cookiedir)
{
    h_viewer->set_transaction(t, cookiedir);
    if (t) {
        t->set_timeout(h_params->Timeout);
        t->set_retries(h_params->Retries);
        t->set_http_port(h_params->HTTP_Port);
        t->set_ftp_port(h_params->FTP_Port);
        t->set_http_debug(h_params->DebugMode);
        if (h_params->PrintTransact)
            t->set_logfile("stderr");
        if (cookiedir && !h_params->NoCookies) {
            int len = strlen(cookiedir) + 20;
            char *cf = new char [len];
            snprintf(cf, len,  "%s/%s", cookiedir, "cookies");
            t->set_cookiefile(cf);
            delete [] cf;
        }
    }
}


// Return a pointer to the transaction struct.
//
Transaction *
QThelpDlg::get_transaction()
{
    return (h_viewer->get_transaction());
}


// Check if the transfer should be aborted, return true if so.
//
bool
QThelpDlg::check_halt_processing(bool run_events)
{
    if (run_events) {
        qApp->processEvents(QEventLoop::AllEvents);
        if (!h_Stop->isEnabled() && h_stop_btn_pressed)
            return (true);
    }
    else if (h_stop_btn_pressed)
        return (true);
    return (false);
}


// Enable/disable halt button sensitivity.
//
void
QThelpDlg::set_halt_proc_sens(bool set)
{
    h_Stop->setEnabled(set);
}


// Write text on the status line.
//
void
QThelpDlg::set_status_line(const char *msg)
{
    if (h_frame_parent)
        h_frame_parent->set_status_line(msg);
    else
        h_status_bar->showMessage(QString(msg));
}


htmImageInfo *
QThelpDlg::new_image_info(const char *url, bool progressive)
{
    return (h_viewer->new_image_info(url, progressive));
}


bool
QThelpDlg::call_plc(const char *url)
{
    return (h_viewer->call_plc(url));
}


htmImageInfo *
QThelpDlg::image_procedure(const char *url)
{
    return (h_viewer->image_procedure(url));
}


void
QThelpDlg::image_replace(htmImageInfo *image, htmImageInfo *new_image)
{
    h_viewer->image_replace(image, new_image);
}


bool
QThelpDlg::is_body_image(const char *url)
{
    if (HLP()->context()->isImageInList(this))
        return (false);
    return (h_viewer->is_body_image(url));
}


const char *
QThelpDlg::get_url()
{
    return (h_cur_topic ? h_cur_topic->keyword() : 0);
}


bool
QThelpDlg::no_url_cache()
{
    return (h_params->NoCache);
}


int
QThelpDlg::image_load_mode()
{
    return (h_params->LoadMode);
}


int
QThelpDlg::image_debug_mode()
{
    return (h_params->LocalImageTest);
}


GRwbag *
QThelpDlg::get_widget_bag()
{
    return (this);
}


//
// HelpWidget overrides
//

// Link and display the new topic.
//
void
QThelpDlg::link_new(HLPtopic *top)
{
    HLP()->context()->linkNewTopic(top);
    h_root_topic = top;
    h_cur_topic = top;
    reuse(0, false);
}


// Strip HTML tokens out of the window title
//
static void
strip_html(char *buf)
{
    char tbuf[256];
    strcpy(tbuf, buf);
    char *d = buf;
    for (char *s = tbuf; *s; s++) {
        if (*s == '<' && (*(s+1) == '/' || isalpha(*(s+1)))) {
            while (*s && *s != '>')
                s++;
            continue;
        }
        *d++ = *s;
    }
    *d = 0;
}


// Reuse the current display to show and possible link in newtop.
//
void
QThelpDlg::reuse(HLPtopic *newtop, bool newlink)
{
    if (h_root_topic->lastborn()) {
        // in the forward/back operations, the new topic is stitched in
        // as lastborn, and the scroll update is handled elsewhere
        if (h_root_topic->lastborn() != newtop)
            h_root_topic->lastborn()->set_topline(get_scroll_pos());
    }
    else if (newtop)
        h_root_topic->set_topline(get_scroll_pos());

    if (!newtop)
        newtop = h_root_topic;

    char *anchor = 0;
    newtop->set_show_plain(HLP()->context()->isPlain(newtop->keyword()));
    if (newtop != h_root_topic) {
        h_root_topic->set_text(newtop->get_text());
        newtop->clear_text();
    }
    else
        h_root_topic->get_text();
    h_cur_topic = newtop;
    const char *t = HLP()->context()->findAnchorRef(newtop->keyword());
    if (t)
        anchor = lstring::copy(t);
    if (newlink && newtop != h_root_topic) {
        newtop->set_sibling(h_root_topic->lastborn());
        h_root_topic->set_lastborn(newtop);
        newtop->set_parent(h_root_topic);
        h_Backward->setEnabled(true);
    }
    redisplay();
    if (anchor)
        set_scroll_pos(h_viewer->anchor_pos_by_name(anchor));
    else
        set_scroll_pos(newtop->get_topline());
    delete [] anchor;
    set_status_line(newtop->keyword());

    t = newtop->title();
    if (!t || !*t)
        t = h_viewer->get_title();
    if (!t || !*t)
        t = "Whiteley Research Inc.";
    char buf[256];
    snprintf(buf, 256, "%s -- %s", HLP()->get_name(), t);
    strip_html(buf);
    setWindowTitle(QString(buf));
    setAttribute(Qt::WA_DeleteOnClose);
    QueueTimer.start();
}


// Halt any current display activity and redisplay.
//
void
QThelpDlg::redisplay()
{
    Transaction *t = h_viewer->get_transaction();
    if (t) {
        // still downloading previous page, abort
        t->set_abort();
        h_viewer->set_transaction(0, 0);
    }
    halt_images();

    HLPtopic *top = h_root_topic->lastborn();
    if (!top)
        top = h_root_topic;

    if (top->show_plain() || !top->is_html())
        h_viewer->set_mime_type("text/plain");
    else
        h_viewer->set_mime_type("text/html");
    h_viewer->set_source(h_root_topic->get_cur_text());
}


HLPtopic *
QThelpDlg::get_topic()
{
    return (h_cur_topic);
}


// Unset the halt flag, which will be set if an abort is needed.
//
void
QThelpDlg::unset_halt_flag()
{
    h_stop_btn_pressed = false;
}


void
QThelpDlg::halt_images()
{
    stop_image_download();
    HLP()->context()->flushImages(this);
}


void
QThelpDlg::show_cache(int mode)
{
    if (mode == MODE_OFF) {
        if (h_cache_list)
            h_cache_list->popdown();
        return;
    }
    if (mode == MODE_UPD) {
        if (h_cache_list) {
            stringlist *s0 = HLP()->context()->listCache();
            h_cache_list->update(s0, "Cache Entries", 0);
            stringlist::destroy(s0);
        }
        return;
    }
    if (h_cache_list)
        return;
    stringlist *s0 = HLP()->context()->listCache();
    h_cache_list = PopUpList(s0, "Cache Entries", 0, 0, 0, false, false);
    stringlist::destroy(s0);
    if (h_cache_list) {
        h_cache_list->register_usrptr((void**)&h_cache_list);
        QTlistDlg *list = dynamic_cast<QTlistDlg*>(h_cache_list);
        if (list)
            connect(list, SIGNAL(action_call(const char*, void*)),
                this, SLOT(cache_choice_slot(const char*)));
    }
}


//-----------------------------------------------------------------------------
// htmDataInterface methods

// All QTviewer "signals" are dispatched from here.
//
void
QThelpDlg::emit_signal(SignalID id, void *payload)
{
    switch (id) {
    case S_ARM:
        // emit arm_slot(static_cast<htmCallbackInfo*>(payload));
        break;
    case S_ACTIVATE:
        newtopic_slot(static_cast<htmAnchorCallbackStruct*>(payload));
        break;
    case S_ANCHOR_TRACK:
        anchor_track_slot(static_cast<htmAnchorCallbackStruct*>(payload));
        break;
    case S_ANCHOR_VISITED:
        // anchor_visited_slot(static_cast<htmVisitedCallbackStruct*>(payload));
        break;
    case S_DOCUMENT:
        // document_slot(static_cast<htmDocumentCallbackStruct*>(payload));
        break;
    case S_LINK:
        // link_slot(static_cast<htmLinkCallbackStruct*>(payload));
        break;
    case S_FRAME:
        frame_slot(static_cast<htmFrameCallbackStruct*>(payload));
        break;
    case S_FORM:
        form_slot(static_cast<htmFormCallbackStruct*>(payload));
        break;
    case S_IMAGEMAP:
        // imagemap_slot(static_cast<htmImagemapCallbackStruct*>(payload));
        break;
    case S_HTML_EVENT:
        // html_event_slot(static_cast<htmEventCallbackStruct*>(payload));
        break;
    default:
        break;
    }
}


void *
QThelpDlg::event_proc(const char*)
{
    return (0);
}


void
QThelpDlg::panic_callback(const char*)
{
}


// Called by the widget to resolve image references.
//
htmImageInfo *
QThelpDlg::image_resolve(const char *fname)
{
    if (!fname)
        return (0);
    return (HLP()->context()->imageResolve(fname, this));
}


// This is the "get_data" callback for progressive image loading.
//
int
QThelpDlg::get_image_data(htmPLCStream *stream, void *buffer)
{
    HLPimageList *im = (HLPimageList*)stream->user_data;
    return (HLP()->context()->getImageData(im, stream, buffer));
}


// This is the "end_data" callback for progressive image loading.
//
void
QThelpDlg::end_image_data(htmPLCStream *stream, void*, int type, bool)
{
    if (type == PLC_IMAGE) {
        HLPimageList *im = (HLPimageList*)stream->user_data;
        HLP()->context()->inactivateImages(im);
    }
}


// This returns the client area that can be used for display frames. 
// We use the entire widget width, and the height between the menu and
// status bar.
//
void
QThelpDlg::frame_rendering_area(htmRect *rct)
{
    QRect r1 = h_viewer->frameGeometry();
    QRect r2 = h_status_bar->frameGeometry();
    QSize qs = size();

    rct->x = 0;
    rct->y = r1.top();
    rct->width = qs.width();
    rct->height = r2.top() - r1.top();
}


// If this is a frame, return the frame name.
// Otherwise return -1.
//
const char *
QThelpDlg::get_frame_name()
{
    return (h_frame_name);
}


// Return the keyword and title from the current topic, if possible.
//
void
QThelpDlg::get_topic_keys(char **pkw, char **ptitle)
{
    if (pkw)
        *pkw = 0;
    if (ptitle)
        *ptitle = 0;
    HLPtopic *t = h_cur_topic;
    if (t) {
        if (pkw)
            *pkw = lstring::copy(t->keyword());
        if (ptitle) {
            const char *title = t->title();
            if (title)
                *ptitle = lstring::copy(title);
        }
    }
}


// Ensure that the bounding box passed is visible.
//
void
QThelpDlg::scroll_visible(int l, int t, int r, int b)
{
/*XXX
    const int slop = 20;
    int spy = htmlview->get_scroll_pos(false);
    int spx = htmlview->get_scroll_pos(true);
    htmRect r;
    htmlview->client_area(&r);
    if (y < spy + slop || y > spy + (int)r.height - slop) {
        y -= slop;
        if (y < 0)
            y = 0;
        htmlview->set_scroll_pos(y, false);
    }
    if (x < spx || x > spx + (int)r.width)
        htmlview->set_scroll_pos(x, true);
*/
(void)l;
(void)t;
(void)r;
(void)b;
}


//-----------------------------------------------------------------------------
// QTbag functions

char *
QThelpDlg::GetPostscriptText(int font_family, const char *url,
    const char *title, bool use_headers, bool a4)
{
    return (h_viewer->get_postscript_text(font_family, url, title,
        use_headers, a4));
}


char *
QThelpDlg::GetPlainText()
{
    return (h_viewer->get_plain_text());
}


char *
QThelpDlg::GetHtmlText()
{
    return (h_viewer->get_html_text());
}


//-----------------------------------------------------------------------------
// Misc.

// scrollbar setting
int
QThelpDlg::get_scroll_pos(bool horiz)
{
    QScrollBar *sb;
    if (horiz)
        sb = h_viewer->horizontalScrollBar();
    else
        sb = h_viewer->verticalScrollBar();
    if (!sb)
        return (0);
    return (sb->value());
}


void
QThelpDlg::set_scroll_pos(int posn, bool horiz)
{
    QScrollBar *sb;
    if (horiz)
        sb = h_viewer->horizontalScrollBar();
    else
        sb = h_viewer->verticalScrollBar();
    if (!sb)
        return;
    sb->setValue(posn);
}


//-----------------------------------------------------------------------------
// Slots

void
QThelpDlg::backward_slot()
{
    HLPtopic *top = h_root_topic;
    if (top && top->lastborn()) {
        HLPtopic *last = top->lastborn();
        top->set_lastborn(last->sibling());
        last->set_sibling(top->next());
        top->set_next(last);
        last->set_topline(get_scroll_pos());
        top->reuse(top->lastborn(), false);

        h_Backward->setEnabled(top->lastborn());
        h_Forward->setEnabled(true);
   }
}


void
QThelpDlg::forward_slot()
{
    HLPtopic *top = h_root_topic;
    if (top && top->next()) {
        HLPtopic *next = top->next();
        top->set_next(next->sibling());
        next->set_sibling(top->lastborn());
        top->set_lastborn(next);
        if (next->sibling())
            next->sibling()->set_topline(get_scroll_pos());
        else
            top->set_topline(get_scroll_pos());
        top->reuse(top->lastborn(), false);

        h_Forward->setEnabled(top->next());
        h_Backward->setEnabled(true);
    }
}


void
QThelpDlg::stop_slot()
{
    stop_image_download();
    h_Stop->setEnabled(false);
    h_stop_btn_pressed = true;
}


void
QThelpDlg::open_slot()
{
    PopUpInput("Enter keyword, file name, or URL", "", "Open", 0, 0);
    connect(wb_input, SIGNAL(action_call(const char*, void*)), this,
        SLOT(do_open_slot(const char*, void*)));
}


void
QThelpDlg::open_file_slot()
{
    GRfilePopup *fs = PopUpFileSelector(fsSEL, GRloc(), 0, 0, 0, 0);
    QTfileDlg *fsel = dynamic_cast<QTfileDlg*>(fs);
    if (fsel)
        connect(fsel, SIGNAL(file_selected(const char*, void*)),
            this, SLOT(do_open_slot(const char*, void*)));
}


void
QThelpDlg::save_slot()
{
    PopUpInput(0, "", "Save", 0, 0);
    connect(wb_input, SIGNAL(action_call(const char*, void*)), this,
        SLOT(do_save_slot(const char*, void*)));
}


// for hardcopies
static HCcb hlpHCcb =
{
    0,            // hcsetup
    0,            // hcgo
    0,            // hcframe
    0,            // format
    0,            // drvrmask
    HClegNone,    // legend
    HCportrait,   // orient
    0,            // resolution
    0,            // command
    false,        // tofile
    "",           // tofilename
    0.25,         // left
    0.25,         // top
    8.0,          // width
    10.5          // height
};


void
QThelpDlg::print_slot()
{
    if (!hlpHCcb.command)
        hlpHCcb.command = lstring::copy(GRappIf()->GetPrintCmd());
    PopUpPrint(0, &hlpHCcb, HCtextPS);
}


void
QThelpDlg::reload_slot()
{
    h_cur_topic->set_topline(get_scroll_pos());
    newtopic(h_cur_topic->keyword(), false, false, true);
}


void
QThelpDlg::quit_slot()
{
    deleteLater();
}


void
QThelpDlg::search_slot()
{
    PopUpInput("Enter keyword for database search:", "", "Search", 0, 0);
    connect(wb_input, SIGNAL(action_call(const char*, void*)), this,
        SLOT(do_search_slot(const char*, void*)));
}


void
QThelpDlg::find_slot()
{
    PopUpInput("Enter word for text search:", "", "Find Text", 0, 0);
    connect(wb_input, SIGNAL(action_call(const char*, void*)), this,
        SLOT(do_find_text_slot(const char*, void*)));
}


void
QThelpDlg::set_font_slot(bool set)
{
    if (set) {
        PopUpFontSel(0, GRloc(), MODE_ON, 0, 0, FNT_MOZY);
        connect(wb_fontsel, SIGNAL(dismiss()), this, SLOT(font_down_slot()));
    }
    else
        PopUpFontSel(0, GRloc(), MODE_OFF, 0, 0, 0);
}


// Handle font selector dismissal.
//
void
QThelpDlg::font_down_slot()
{
    h_SetFont->setChecked(false);
}


void
QThelpDlg::dont_cache_slot(bool set)
{
    h_params->NoCache = set;
}


void
QThelpDlg::clear_cache_slot()
{
    HLP()->context()->clearCache();
}


void
QThelpDlg::reload_cache_slot()
{
    HLP()->context()->reloadCache();
}


void
QThelpDlg::show_cache_slot()
{
    show_cache(MODE_ON);
}


void
QThelpDlg::no_cookies_slot(bool set)
{
    h_params->NoCookies = set;
}


void
QThelpDlg::no_images_slot(bool set)
{
    if (set) {
        stop_image_download();
        h_params->LoadMode = HLPparams::LoadNone;
    }
}


void
QThelpDlg::sync_images_slot(bool set)
{
    if (set) {
        stop_image_download();
        h_params->LoadMode = HLPparams::LoadSync;
    }
}


void
QThelpDlg::delayed_images_slot(bool set)
{
    if (set) {
        stop_image_download();
        h_params->LoadMode = HLPparams::LoadDelayed;
    }
}


void
QThelpDlg::progressive_images_slot(bool set)
{
    if (set) {
        stop_image_download();
        h_params->LoadMode = HLPparams::LoadProgressive;
    }
}


void
QThelpDlg::anchor_plain_slot(bool set)
{
    if (set) {
        h_params->AnchorButtons = false;
        h_params->AnchorUnderlined = false;
        h_viewer->set_anchor_style(ANC_PLAIN);

        int position = get_scroll_pos();
        set_scroll_pos(position);
    }
}


void
QThelpDlg::anchor_buttons_slot(bool set)
{
    if (set) {
        h_params->AnchorButtons = true;
        h_params->AnchorUnderlined = false;
        h_viewer->set_anchor_style(ANC_BUTTON);
    }
}


void
QThelpDlg::anchor_underline_slot(bool set)
{
    if (set) {
        h_params->AnchorButtons = false;
        h_params->AnchorUnderlined = true;
        h_viewer->set_anchor_style(ANC_SINGLE_LINE);

        int position = get_scroll_pos();
        set_scroll_pos(position);
    }
}


void
QThelpDlg::anchor_highlight_slot(bool set)
{
    h_params->AnchorHighlight = set;
    h_viewer->set_anchor_highlighting(set);
}


void
QThelpDlg::bad_html_slot(bool set)
{
    h_params->BadHTMLwarnings = set;
    h_viewer->set_html_warnings(set);
}


void
QThelpDlg::freeze_animations_slot(bool set)
{
    h_params->FreezeAnimations = set;
    h_viewer->set_freeze_animations(set);
}


void
QThelpDlg::log_transactions_slot(bool set)
{
    h_params->PrintTransact = set;
}


void
QThelpDlg::add_slot()
{
    if (!h_cur_topic)
        return;
    HLPtopic *tp = h_cur_topic;
    const char *ptitle = tp->title();
    char *title;
    if (ptitle && *ptitle)
        title = lstring::copy(ptitle);
    else
        title = lstring::copy(h_viewer->get_title());
    char *url = lstring::copy(tp->keyword());
    if (!url || !*url) {
        delete [] url;
        delete [] title;
        return;
    }
    if (!title || !*title) {
        delete [] title;
        title = lstring::copy(url);
    }
    HLPbookMark *b = HLP()->context()->bookmarkUpdate(title, url);
    delete [] title;
    delete [] url;

    QString qs = QString(b->title);
    qs.truncate(32);
    h_main_menus[2]->addAction(
        new action_item(b, h_main_menus[2]));
}


void
QThelpDlg::delete_slot()
{
}


namespace {
    void yncb(bool val, void *client_data)
    {
        if (val)
            delete static_cast<action_item*>(client_data);
    }
}


// Handler for bookmarks selected in the menu.
// 
void
QThelpDlg::bookmark_slot(QAction *action)
{
    action_item *ac = dynamic_cast<action_item*>(action);
    if (ac) {
        if (h_DeleteBookmark->isChecked()) {
            char buf[256];
            strcpy(buf, "Delete ");
            char *t = buf + strlen(buf);
            strncpy(t, ac->bookmark()->title, 32);
            t[33] = 0;
            strcat(t, " ?");
            PopUpAffirm(0, GRloc(), buf, yncb, ac);
        }
        else {
            HLPbookMark *b = ac->bookmark();
            newtopic(b->url, false, false, true);
        }
    }
}


void
QThelpDlg::help_slot()
{
    if (QTdev::self()->MainFrame())
        QTdev::self()->MainFrame()->PopUpHelp("helpsys");
    else
        PopUpHelp("helpsys");
}


// Handle selections from the cache listing.
//
void
QThelpDlg::cache_choice_slot(const char *string)
{
    lstring::advtok(&string);
    newtopic(string, false, false, true);
}


// Print the current anchor href in the status label.
//
void
QThelpDlg::anchor_track_slot(htmAnchorCallbackStruct *c)
{
    if (c && c->href)
        h_status_bar->showMessage(QString(c->href));
    else
        h_status_bar->showMessage(QString(h_cur_topic->keyword()));
}


// Handle clicking on an anchor.
//
void
QThelpDlg::newtopic_slot(htmAnchorCallbackStruct *c)
{
    if (c == 0 || c->href == 0)
        return;
    c->visited = true;

    // download if shift pressed
    bool force_download = false;
    QMouseEvent *qme = static_cast<QMouseEvent*>(c->event);
    if (qme && (qme->modifiers() & Qt::ShiftModifier))
        force_download = true;

    bool spawn = false;
    if (!force_download) {
        if (c->target) {
            if (!h_cur_topic->target() ||
                    strcmp(h_cur_topic->target(), c->target)) {
                HLPtopic *t = HLP()->context()->findUrlTopic(c->target);
                if (t) {
                    newtopic(c->href, false, false, false);
                    return;
                }
                // Special targets:
                //  _top    reuse same window, no frames
                //  _self   put in originating frame
                //  _blank  put in new window
                //  _parent put in parent frame (nested framesets)

                if (!strcmp(c->target, "_top")) {
                    newtopic(c->href, false, false, false);
                    return;
                }
                // note: _parent not handled, use new window
                if (strcmp(c->target, "_self"))
                    spawn = true;
            }
        }
    }

    if (!spawn) {
        // spawn a new window if button 2 pressed
        if (qme && qme->button() == Qt::MiddleButton)
            spawn = true;
    }

    newtopic(c->href, spawn, force_download, false);

    if (c->target && spawn) {
        HLPtopic *t = HLP()->context()->findKeywordTopic(c->href);
        if (t)
            t->set_target(c->target);
    }
}


// Handle the "submit" request for an html form.  The form return is
// always downloaded and never taken from the cache, since this
// prevents multiple submissions of the same form.
//
void
QThelpDlg::form_slot(htmFormCallbackStruct *cbs)
{
    HLP()->context()->formProcess(cbs, this);
}


// Handle frames.
//
void
QThelpDlg::frame_slot(htmFrameCallbackStruct *cbs)
{
    if (cbs->reason == HTM_FRAMECREATE) {
        h_viewer->hide_drawing_area(true);
        h_frame_array_size = cbs->nframes;
        h_frame_array = new QThelpDlg*[h_frame_array_size];
        for (int i = 0; i < h_frame_array_size; i++) {
            h_frame_array[i] = new QThelpDlg(false, this);
            // use parent's defaults
            h_frame_array[i]->h_params = h_params;
            h_frame_array[i]->set_frame_parent(this);
            h_frame_array[i]->set_frame_name(cbs->frames[i].name);

            h_frame_array[i]->setGeometry(cbs->frames[i].x, cbs->frames[i].y,
                cbs->frames[i].width, cbs->frames[i].height);

            if (cbs->frames[i].scroll_type == FRAME_SCROLL_NONE) {
                h_frame_array[i]->h_viewer->setVerticalScrollBarPolicy(
                    Qt::ScrollBarAlwaysOff);
                h_frame_array[i]->h_viewer->setHorizontalScrollBarPolicy(
                    Qt::ScrollBarAlwaysOff);
            }
            else if (cbs->frames[i].scroll_type == FRAME_SCROLL_AUTO) {
                h_frame_array[i]->h_viewer->setVerticalScrollBarPolicy(
                    Qt::ScrollBarAsNeeded);
                h_frame_array[i]->h_viewer->setHorizontalScrollBarPolicy(
                    Qt::ScrollBarAsNeeded);
            }
            else if (cbs->frames[i].scroll_type == FRAME_SCROLL_YES) {
                h_frame_array[i]->h_viewer->setVerticalScrollBarPolicy(
                    Qt::ScrollBarAlwaysOn);
                h_frame_array[i]->h_viewer->setHorizontalScrollBarPolicy(
                    Qt::ScrollBarAlwaysOn);
            }

            h_frame_array[i]->show();

            HLPtopic *newtop;
            char hanchor[128];
            HLP()->context()->resolveKeyword(cbs->frames[i].src, &newtop,
                hanchor, this, 0, false, false);
            if (!newtop) {
                char buf[256];
                snprintf(buf, 256, "Unresolved link: %s.", cbs->frames[i].src);
                PopUpErr(MODE_ON, buf);
            }

            h_frame_array[i]->wb_shell = wb_shell;
            newtop->set_target(cbs->frames[i].name);
            newtop->set_context(h_frame_array[i]);
            h_frame_array[i]->h_root_topic = newtop;
            h_frame_array[i]->h_cur_topic = newtop;

            if (!newtop->is_html() &&
                    HLP()->context()->isPlain(newtop->keyword())) {
                newtop->set_show_plain(true);
                h_frame_array[i]->h_viewer->set_mime_type("text/plain");
            }
            else {
                newtop->set_show_plain(false);
                h_frame_array[i]->h_viewer->set_mime_type("text/html");
            }
            h_frame_array[i]->h_viewer->set_source(newtop->get_text());
        }
    }
    else if (cbs->reason == HTM_FRAMERESIZE) {
        for (int i = 0; i < h_frame_array_size; i++) {
            h_frame_array[i]->setGeometry(cbs->frames[i].x, cbs->frames[i].y,
                cbs->frames[i].width, cbs->frames[i].height);
        }
    }
    else if (cbs->reason == HTM_FRAMEDESTROY) {
        for (int i = 0; i < h_frame_array_size; i++)
            delete h_frame_array[i];
        delete [] h_frame_array;
        h_frame_array = 0;
        h_frame_array_size = 0;
        h_viewer->show();
    }
}


// Callback for the "Open" and "Open File" menu commands, opens a new
// keyword or file
//
void
QThelpDlg::do_open_slot(const char *name, void*)
{
    if (name) {
        while (isspace(*name))
            name++;
        if (*name) {
            char *url = 0;
            const char *t = strrchr(name, '.');
            if (t) {
                t++;
                if (lstring::cieq(t, "html") || lstring::cieq(t, "htm") ||
                        lstring::cieq(t, "jpg") || lstring::cieq(t, "gif") ||
                        lstring::cieq(t, "png")) {
                    if (!lstring::is_rooted(name)) {
                        char *cwd = getcwd(0, 256);
                        if (cwd) {
                            int len = strlen(cwd) + strlen(name) + 2;
                            url = new char[len];
                            snprintf(url, len, "%s/%s", cwd, name);
                            delete [] cwd;
                            if (access(url, R_OK)) {
                                // no such file
                                delete [] url;
                                url = 0;
                            }
                        }
                    }
                }
            }
            if (!url)
                url = lstring::copy(name);
            newtopic(url, false, false, true);
            if (wb_input)
                wb_input->popdown();
            delete [] url;
        }
    }
}


// Callback passed to PopUpInput to actually save the text in a file.
//
void
QThelpDlg::do_save_slot(const char *fnamein, void*)
{
    char *fname = pathlist::expand_path(fnamein, false, true);
    if (!fname)
        return;
    if (filestat::check_file(fname, W_OK) == NOGO) {
        PopUpMessage(filestat::error_msg(), true);
        delete [] fname;
        return;
    }

    FILE *fp = fopen(fname, "w");
    if (!fp) {
        char tbuf[256];
        if (strlen(fname) > 64)
            strcpy(fname + 60, "...");
        snprintf(tbuf, 256, "Error: can't open file %s", fname);
        PopUpMessage(tbuf, true);
        delete [] fname;
        return;
    }
    char *tptr = h_viewer->get_plain_text();
    const char *mesg;
    if (tptr) {
        if (fputs(tptr, fp) == EOF) {
            PopUpMessage("Error: block write error", true);
            delete [] tptr;
            fclose(fp);
            delete [] fname;
            return;
        }
        delete [] tptr;
        mesg = "Text saved";
    }
    else
        mesg = "Text file is empty";

    fclose(fp);
    if (wb_input)
        wb_input->popdown();
    PopUpMessage(mesg, false);
    delete [] fname;
}


// Callback passed to PopUpInput to actually perform a database keyword
// search.
//
void
QThelpDlg::do_search_slot(const char *target, void*)
{
    if (target && *target) {
        HLPtopic *newtop = HLP()->search(target);
        if (!newtop)
            PopUpErr(MODE_ON, "Unresolved link.");
        else
            newtop->link_new_and_show(false, h_cur_topic);
    }
    if (wb_input)
        wb_input->popdown();
}


void
QThelpDlg::do_find_text_slot(const char *target, void*)
{
    if (target && *target)
        h_viewer->find_words(target, false, false);
}


//-----------------------------------------------------------------------------
// Private functions

// Function to display a new topic, or respond to a link
//
void
QThelpDlg::newtopic(const char *href, bool spawn, bool force_download,
    bool nonrelative)
{
    HLPtopic *newtop;
    char hanchor[128];
    if (HLP()->context()->resolveKeyword(href, &newtop, hanchor, this,
            h_cur_topic, force_download, nonrelative))
        return;
    if (!newtop) {
        char buf[256];
        snprintf(buf, 256, "Unresolved link: %s.", href);
        PopUpErr(MODE_ON, buf);
        return;
    }
    newtop->set_context(this);
    newtop->link_new_and_show(spawn, h_cur_topic);
}


// Halt all image transfers in progress for the widget, and clear the
// queue of jobs for this window
//
void
QThelpDlg::stop_image_download()
{
    if (h_params->LoadMode == HLPparams::LoadProgressive)
        h_viewer->progressive_kill();
    HLP()->context()->abortImageDownload(this);
}

