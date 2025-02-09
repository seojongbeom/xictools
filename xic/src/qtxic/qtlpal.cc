
/*========================================================================*
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
 * Xic Integrated Circuit Layout and Schematic Editor                     *
 *                                                                        *
 *========================================================================*
 $Id:$
 *========================================================================*/

#include "qtlpal.h"
#include "dsp_color.h"
#include "dsp_layer.h"
#include "dsp_inlines.h"
#include "fio.h"
#include "fio_gdsii.h"
#include "keymap.h"
#include "tech.h"
#include "menu.h"
#include "attr_menu.h"
#include "qtltab.h"
#include "qtinterf/qtfont.h"
#include "qtinterf/qtcanvas.h"

#include <QLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QMenu>
#include <QAction>
#include <QResizeEvent>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QDrag>
#include <QMimeData>


//-----------------------------------------------------------------------------
// The Layer Palette.  The top third is a text field that displays
// information about a layer under the pointer, or the current layer.
// The middle third contains icons for the last few current layer
// choices.  The bottom third is a user-configurable palette.  The
// user can drag their favorite layers into this area.  Clicking on
// any of the layer icons will set the current layer.
//
// Help system keywords used:
//  xic:ltpal

void
cMain::PopUpLayerPalette(GRobject caller, ShowMode mode, bool showinfo,
    CDl *ldesc)
{
    if (!QTdev::exists() || !QTmainwin::exists())
        return;
    if (mode == MODE_OFF) {
        if (QTlayerPaletteDlg::self())
            QTlayerPaletteDlg::self()->deleteLater();
        return;
    }
    if (mode == MODE_UPD) {
        if (QTlayerPaletteDlg::self()) {
            if (showinfo)
                QTlayerPaletteDlg::self()->update_info(ldesc);
            else
                QTlayerPaletteDlg::self()->update_layer(ldesc);
        }
        return;
    }
    if (QTlayerPaletteDlg::self())
        return;

    new QTlayerPaletteDlg(caller);

    QTlayerPaletteDlg::self()->set_transient_for(QTmainwin::self());
    QTdev::self()->SetPopupLocation(GRloc(), QTlayerPaletteDlg::self(),
        QTmainwin::self()->Viewport());
    QTlayerPaletteDlg::self()->show();
}
// End of cMain functions.


namespace {

    // These give the widget areas distinctive backgrounds.

    unsigned int text_backg()
    {
        return (DSP()->Color(PromptEditFocusBackgColor));
    }

    unsigned int hist_backg()
    {
        return (DSP()->Color(PromptEditBackgColor));
    }

    unsigned int user_backg()
    {
        return (DSP()->Color(PromptBackgroundColor));
    }
}


QTlayerPaletteDlg *QTlayerPaletteDlg::instPtr;

QTlayerPaletteDlg::QTlayerPaletteDlg(GRobject caller) : QTdraw(XW_LPAL)
{
    instPtr = this;
    lp_caller = caller;
    lp_remove = 0;
    memset(lp_history, 0, LP_PALETTE_COLS * sizeof(CDl*));
    memset(lp_user, 0, LP_PALETTE_COLS * LP_PALETTE_ROWS * sizeof(CDl*));
//    lp_pmap_width = 0;
//    lp_pmap_height = 0;
//    lp_pmap_dirty = false;

    lp_drag_x = 0;
    lp_drag_y = 0;
    lp_dragging = false;

    lp_hist_y = 0;
    lp_user_y = 0;
    lp_line_height = 0;
    lp_box_dimension = 0;
    lp_box_text_spacing = 0;
    lp_entry_width = 0;

    setWindowTitle(tr("Layer Palette"));
    setAttribute(Qt::WA_DeleteOnClose);
//    gtk_window_set_resizable(GTK_WINDOW(lp_shell), false);

    QMargins qmtop(2, 2, 2, 2);
    QMargins qm;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(qmtop);
    vbox->setSpacing(2);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    QPushButton *recall_btn = new QPushButton(tr("Recall"));
    hbox->addWidget(recall_btn);

    QMenu *recall_menu = new QMenu();
    recall_btn->setMenu(recall_menu);
    for (int i = 1; i < 8; i++) {
        char buf[16];
        snprintf(buf, sizeof(buf), "Reg %d", i);
        QAction *a = recall_menu->addAction(buf);
        a->setData(i);
    }
    connect(recall_menu, SIGNAL(triggered(QAction*)),
        this, SLOT(recall_menu_slot(QAction*)));

    QPushButton *save_btn = new QPushButton(tr("Save"));
    hbox->addWidget(save_btn);

    QMenu *save_menu = new QMenu();
    save_btn->setMenu(save_menu);
    for (int i = 1; i < 8; i++) {
        char buf[16];
        snprintf(buf, sizeof(buf), "Reg %d", i);
        QAction *a = save_menu->addAction(buf);
        a->setData(i);
    }
    connect(save_menu, SIGNAL(triggered(QAction*)),
        this, SLOT(save_menu_slot(QAction*)));

    lp_remove = new QPushButton(tr("Remove"));
    lp_remove->setCheckable(true);
    hbox->addWidget(lp_remove);

    QPushButton *btn = new QPushButton(tr("Help"));
    hbox->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(help_btn_slot()));

    QGroupBox *gb = new QGroupBox(0);
    vbox->addWidget(gb);
    QVBoxLayout *vb = new QVBoxLayout(gb);
    vb->setContentsMargins(qmtop);
    vb->setSpacing(2);

    gd_viewport = new QTcanvas();
    vb->addWidget(gd_viewport);
    Viewport()->setFocusPolicy(Qt::StrongFocus);
    Viewport()->setAcceptDrops(true);

    QFont *fnt;
    if (FC.getFont(&fnt, FNT_SCREEN))
        gd_viewport->set_font(fnt);
    connect(QTfont::self(), SIGNAL(fontChanged(int)),
        this, SLOT(font_changed_slot(int)), Qt::QueuedConnection);

    connect(Viewport(), SIGNAL(resize_event(QResizeEvent*)),
        this, SLOT(resize_slot(QResizeEvent*)));
/*
    connect(Viewport(), SIGNAL(new_painter(QPainter*)),
        this, SLOT(new_painter_slot(QPainter*)));
    connect(Viewport(), SIGNAL(paint_event(QPaintEvent*)),
        this, SLOT(paint_slot(QPaintEvent*)));
*/
    connect(Viewport(), SIGNAL(press_event(QMouseEvent*)),
        this, SLOT(button_down_slot(QMouseEvent*)));
    connect(Viewport(), SIGNAL(release_event(QMouseEvent*)),
        this, SLOT(button_up_slot(QMouseEvent*)));
    connect(Viewport(), SIGNAL(motion_event(QMouseEvent*)),
        this, SLOT(motion_slot(QMouseEvent*)));
/*
    connect(Viewport(), SIGNAL(key_press_event(QKeyEvent*)),
        this, SLOT(key_down_slot(QKeyEvent*)));
    connect(Viewport(), SIGNAL(key_release_event(QKeyEvent*)),
        this, SLOT(key_up_slot(QKeyEvent*)));
    connect(Viewport(), SIGNAL(enter_event(QEnterEvent*)),
        this, SLOT(enter_slot(QEnterEvent*)));
    connect(Viewport(), SIGNAL(leave_event(QEvent*)),
        this, SLOT(leave_slot(QEvent*)));
    connect(Viewport(), SIGNAL(focus_in_event(QFocusEvent*)),
        this, SLOT(focus_in_slot(QFocusEvent*)));
    connect(Viewport(), SIGNAL(focus_out_event(QFocusEvent*)),
        this, SLOT(focus_out_slot(QFocusEvent*)));
*/
    connect(Viewport(), SIGNAL(drag_enter_event(QDragEnterEvent*)),
        this, SLOT(drag_enter_slot(QDragEnterEvent*)));
    connect(Viewport(), SIGNAL(drop_event(QDropEvent*)),
        this, SLOT(drop_slot(QDropEvent*)));

    /*
    gtk_widget_add_events(gd_viewport, GDK_STRUCTURE_MASK);
    g_signal_connect(G_OBJECT(gd_viewport), "configure-event",
        G_CALLBACK(lp_resize_hdlr), 0);
#if GTK_CHECK_VERSION(3,0,0)
    g_signal_connect(G_OBJECT(gd_viewport), "draw",
        G_CALLBACK(lp_redraw_hdlr), 0);
#else
    gtk_widget_add_events(gd_viewport, GDK_EXPOSURE_MASK);
    g_signal_connect(G_OBJECT(gd_viewport), "expose-event",
        G_CALLBACK(lp_redraw_hdlr), 0);
#endif
    gtk_widget_add_events(gd_viewport, GDK_BUTTON_PRESS_MASK);
    g_signal_connect(G_OBJECT(gd_viewport), "button-press-event",
        G_CALLBACK(lp_button_down_hdlr), 0);
    gtk_widget_add_events(gd_viewport, GDK_BUTTON_RELEASE_MASK);
    g_signal_connect(G_OBJECT(gd_viewport), "button-release-event",
        G_CALLBACK(lp_button_up_hdlr), 0);
    gtk_widget_add_events(gd_viewport, GDK_POINTER_MOTION_MASK);
    g_signal_connect(G_OBJECT(gd_viewport), "motion-notify-event",
        G_CALLBACK(lp_motion_hdlr), 0);
    g_signal_connect(G_OBJECT(gd_viewport), "drag-begin",
        G_CALLBACK(lp_drag_begin), 0);
    g_signal_connect(G_OBJECT(gd_viewport), "drag-end",
        G_CALLBACK(lp_drag_end), 0);
    g_signal_connect(G_OBJECT(gd_viewport), "drag-data-get",
        G_CALLBACK(lp_drag_data_get), 0);
    gtk_drag_dest_set(gd_viewport, GTK_DEST_DEFAULT_ALL, lp_targets,
        n_lp_targets, GDK_ACTION_COPY);
    g_signal_connect_after(G_OBJECT(gd_viewport), "drag-data-received",
        G_CALLBACK(lp_drag_data_received), 0);
    g_signal_connect(G_OBJECT(gd_viewport), "style-set",
        G_CALLBACK(lp_font_change_hdlr), 0);

    GTKfont::setupFont(gd_viewport, FNT_SCREEN, true);
    */

    btn = new QPushButton(tr("Dismiss"));
    vbox->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(dismiss_btn_slot()));

    init_size();
//    lp_recall_proc(0, 0);
}


QTlayerPaletteDlg::~QTlayerPaletteDlg()
{
//    lp_save_proc(0, 0);

    instPtr = 0;
    SetGbag(0);
    if (lp_caller)
        QTdev::Deselect(lp_caller);
}


// Update the info text.
//
void
QTlayerPaletteDlg::update_info(CDl *ldesc)
{
    int fwid, fhei;
    TextExtent(0, &fwid, &fhei);
    int xx = 2;
    int yy = fhei;

    SetColor(text_backg());
    SetFillpattern(0);
    SetBackground(text_backg());
    Box(0, 0, width(), LP_TEXT_LINES*fhei + 2);

    unsigned long c1 = DSP()->Color(PromptTextColor);
    unsigned long c2 = DSP()->Color(PromptEditTextColor);
    const char *str;

    char buf[64];
    const char *lname = CDldb()->getOAlayerName(ldesc->oaLayerNum());
    if (!lname)
        lname = "";
    snprintf(buf, 32, " (%d)", ldesc->oaLayerNum());
    SetColor(c1);
    str = "name (num): ";
    Text(str, xx, yy, 0);
    xx += QTfont::stringWidth(str, gd_viewport);
    SetColor(c2);
    Text(lname, xx, yy, 0);
    xx += QTfont::stringWidth(lname, gd_viewport);
    Text(buf, xx, yy, 0);

    yy += fhei;
    xx = 2;

    const char *pname = CDldb()->getOApurposeName(ldesc->oaPurposeNum());
    if (!pname)
        pname = CDL_PRP_DRAWING;
    snprintf(buf, 32, " (%d)", ldesc->oaPurposeNum());
    SetColor(c1);
    str = "purpose (num): ";
    Text(str, xx, yy, 0);
    xx += QTfont::stringWidth(str, gd_viewport);
    SetColor(c2);
    Text(pname, xx, yy, 0);
    xx += QTfont::stringWidth(pname, gd_viewport);
    Text(buf, xx, yy, 0);

    yy += fhei;
    xx = 2;

    SetColor(c1);
    str = "alias: ";
    Text(str, xx, yy, 0);
    xx += QTfont::stringWidth(str, gd_viewport);
    if (ldesc->lppName()) {
        SetColor(c2);
        Text(ldesc->lppName(), xx, yy, 0);
    }

    yy += fhei;
    xx = 2;

    SetColor(c1);
    str = "descr: ";
    Text(str, xx, yy, 0);
    xx += QTfont::stringWidth(str, gd_viewport);
    if (ldesc->description()) {
        SetColor(c2);
        Text(ldesc->description(), xx, yy, 0);
    }

    yy += fhei;
    xx = 2;

    bool hasmap = false;
    int l = -1, d = -1;
    if (ldesc->strmOut()) {
        l = ldesc->strmOut()->layer();
        d = ldesc->strmOut()->dtype();
        hasmap = true;
    }
    else if (strmdata::hextrn(ldesc->name(), &l, &d))
        hasmap = true;
    if (hasmap) {
        SetColor(c1);
        str = "GDSII layer/dtype: ";
        Text(str, xx, yy, 0);
        xx += QTfont::stringWidth(str, gd_viewport);

        if (l > 255 || d > 255)
            snprintf(buf, sizeof(buf), "%d (%04Xh) / ", l, l);
        else
            snprintf(buf, sizeof(buf), "%d (%02Xh) / ", l, l);
        SetColor(c2);
        Text(buf, xx, yy, 0);
        xx += QTfont::stringWidth(buf, gd_viewport);
        if (l > 255 || d > 255)
            snprintf(buf, sizeof(buf), "%d (%04Xh)", d, d);
        else
            snprintf(buf, sizeof(buf), "%d (%02Xh)", d, d);
        Text(buf, xx, yy, 0);
    }

    Update();
}


// Update the layer history list.
//
void
QTlayerPaletteDlg::update_layer(CDl *ldesc)
{
    if (ldesc) {
        if (!CDldb()->findLayer(ldesc->name(), DSP()->CurMode())) {
            // The ldesc was removed from the layer table, purge it
            // from the lists.
            for (int i = 0; i < LP_PALETTE_COLS; i++) {
                if (ldesc == lp_history[i]) {
                    for (int j = i+1; j < LP_PALETTE_COLS; j++)
                        lp_history[j-1] = lp_history[j];
                    lp_history[LP_PALETTE_COLS-1] = 0;
                    break;
                }
            }
            int usz = LP_PALETTE_COLS * LP_PALETTE_ROWS;
            for (int i = 0; i < usz; i++) {
                if (ldesc == lp_user[i]) {
                    for (int j = i+1; j < usz; j++)
                        lp_user[j-1] = lp_user[j];
                    lp_user[usz-1] = 0;
                    break;
                }
            }
        }
        else {
            for (int i = 0; i < LP_PALETTE_COLS; i++) {
                if (ldesc == lp_history[i]) {
                    if (i == 0)
                        return;
                    for (int j = i; j > 0; j--)
                        lp_history[j] = lp_history[j-1];
                    lp_history[0] = ldesc;
//                    lp_pmap_dirty = true;
                    refresh(0, 0, 0, 0);
                    return;
                }
            }
            for (int i = LP_PALETTE_COLS - 1; i > 0; i--)
                lp_history[i] = lp_history[i-1];
            lp_history[0] = ldesc;
        }
    }
//    lp_pmap_dirty = true;
    refresh(0, 0, 0, 0);
}


void
QTlayerPaletteDlg::update_user(CDl *ldesc, int xx, int yy)
{
    int col = (xx-2)/lp_entry_width;
    if (col < 0)
        col = 0;
    else if (col >= LP_PALETTE_COLS)
        col = LP_PALETTE_COLS - 1;
    int row = (yy - lp_user_y)/(lp_user_y - lp_hist_y);
    if (row < 0)
        row = 0;
    else if (row >= LP_PALETTE_ROWS)
        row = LP_PALETTE_ROWS-1;
    int indx = row*LP_PALETTE_COLS + col;

    int usz = LP_PALETTE_COLS * LP_PALETTE_ROWS;
    for (int i = 0; i < usz; i++) {
        if (!lp_user[i]) {
            if (indx > i)
                indx = i;
            break;
        }
    }

    int sindx = -1;
    for (int i = 0; i < usz; i++) {
        if (ldesc == lp_user[i]) {
            sindx = i;
            break;
        }
    }
    if (sindx < 0) {
        for (int i = usz - 1; i > indx; i--)
            lp_user[i] = lp_user[i-1];
        lp_user[indx] = ldesc;
    }
    else if (sindx < indx) {
        if (!lp_user[indx]) {
            indx--;
            if (indx == sindx)
                return;
        }
        for (int i = sindx; i < indx; i++)
            lp_user[i] = lp_user[i+1];
        lp_user[indx] = ldesc;
    }
    else if (sindx > indx) {
        for (int i = sindx; i > indx; i--)
            lp_user[i] = lp_user[i-1];
        lp_user[indx] = ldesc;
    }
    else
        return;
//    lp_pmap_dirty = true;
    refresh(0, 0, 0, 0);
}


void
QTlayerPaletteDlg::init_size()
{
    int fwid, fhei;
    TextExtent(0, &fwid, &fhei);
    lp_hist_y = LP_TEXT_LINES*fhei + fhei/2 + 4;
    lp_user_y = lp_hist_y + 2*fhei + fhei/2;

    int y_offset = 4;
    lp_line_height = 2*fhei + 2;
    lp_box_dimension = lp_line_height - 2*y_offset;
    lp_box_text_spacing = lp_box_dimension/4;
    lp_entry_width = lp_box_dimension + 3*lp_box_text_spacing + 3*fwid + 4;

    int wid = LP_PALETTE_COLS*lp_entry_width + 4;
    int hei = lp_user_y + (2*fhei + fhei/2)*LP_PALETTE_ROWS;
    gd_viewport->setMinimumWidth(wid);
    gd_viewport->setMinimumHeight(hei);
}


// Redraw the two sample areas, not the text area.
//
void
QTlayerPaletteDlg::redraw()
{
    int win_width = Viewport()->width();
    int win_height = Viewport()->height();
    SetFillpattern(0);
    SetColor(user_backg());
    Box(0, lp_hist_y - 8, win_width, lp_hist_y - 6);
    SetColor(hist_backg());
    Box(0, lp_hist_y - 6, win_width, lp_user_y - 6);
    SetColor(user_backg());
    Box(0, lp_user_y - 6, win_width, win_height);

    int backg = DSP()->Color(BackgroundColor);
    char buf[128];
    for (int xx = 0; xx < 2; xx++) {
        CDl **lary = xx ? lp_user : lp_history;
        int y1 = xx ? lp_user_y : lp_hist_y;
        int x1 = 4;
        int sz = LP_PALETTE_COLS;
        if (xx)
            sz *= LP_PALETTE_ROWS;
        for (int i = 0; i < sz; i++) {
            CDl *ld = lary[i];
            if (!ld)
                continue;

            if (i && i % LP_PALETTE_COLS == 0) {
                y1 += (lp_user_y - lp_hist_y);
                x1 = 4;
            }
            SetFillpattern(0);
            SetColor(backg);
            Box(x1-4, y1-4, x1 + lp_box_dimension + 4,
                y1 + lp_box_dimension + 4);

            SetColor(dsp_prm(ld)->pixel());
            if (!ld->isInvisible()) {
                if (ld->isFilled()) {
                    SetFillpattern(dsp_prm(ld)->fill());
                    Box(x1, y1, x1 + lp_box_dimension, y1 + lp_box_dimension);
                    if (dsp_prm(ld)->fill()) {
                        SetFillpattern(0);
                        if (ld->isOutlined()) {
                            SetLinestyle(0);
                            GRmultiPt xp(5);
                            if (ld->isOutlinedFat()) {
                                xp.assign(0, x1+1, y1+1);
                                xp.assign(1, x1+1, y1 + lp_box_dimension-1);
                                xp.assign(2, x1 + lp_box_dimension-1, y1 +
                                    lp_box_dimension-1);
                                xp.assign(3, x1 + lp_box_dimension-1, y1+1);
                                xp.assign(4, x1+1, y1+1);
                                PolyLine(&xp, 5);
                            }
                            xp.assign(0, x1, y1);
                            xp.assign(1, x1, y1 + lp_box_dimension);
                            xp.assign(2, x1 + lp_box_dimension,
                                y1 + lp_box_dimension);
                            xp.assign(3, x1 + lp_box_dimension, y1);
                            xp.assign(4, x1, y1);
                            PolyLine(&xp, 5);
                        }
                        if (ld->isCut()) {
                            SetLinestyle(0);
                            Line(x1, y1, x1 + lp_box_dimension,
                                y1 + lp_box_dimension);
                            Line(x1, y1 + lp_box_dimension,
                                x1 + lp_box_dimension, y1);
                        }
                    }
                }
                else {
                    GRmultiPt xp(5);
                    SetFillpattern(0);
                    if (ld->isOutlined()) {
                        if (ld->isOutlinedFat()) {
                            xp.assign(0, x1+1, y1+1);
                            xp.assign(1, x1+1, y1 + lp_box_dimension-1);
                            xp.assign(2, x1 + lp_box_dimension-1,
                                y1 + lp_box_dimension-1);
                            xp.assign(3, x1 + lp_box_dimension-1, y1+1);
                            xp.assign(4, x1+1, y1+1);
                            PolyLine(&xp, 5);
                        }
                        else
                            SetLinestyle(DSP()->BoxLinestyle());
                    }
                    else
                        SetLinestyle(0);
                    xp.assign(0, x1, y1);
                    xp.assign(1, x1, y1 + lp_box_dimension);
                    xp.assign(2, x1 + lp_box_dimension, y1 + lp_box_dimension);
                    xp.assign(3, x1 + lp_box_dimension, y1);
                    xp.assign(4, x1, y1);
                    PolyLine(&xp, 5);
                    if (ld->isCut()) {
                        Line(x1, y1, x1 + lp_box_dimension,
                            y1 + lp_box_dimension);
                        Line(x1, y1 + lp_box_dimension, x1 + lp_box_dimension,
                            y1);
                    }
                }
            }
            SetFillpattern(0);
            SetLinestyle(0);
            if (ld->isNoSelect())
                SetColor(DSP()->Color(GUIcolorDvSl));
            else if (xx)
                SetColor(user_backg());
            else
                SetColor(hist_backg());
            Box(x1 + lp_box_dimension + lp_box_text_spacing, y1,
                x1 + lp_entry_width - lp_box_text_spacing - 4,
                y1 + lp_box_dimension);

            SetColor(DSP()->Color(PromptEditTextColor));
            int y_text_fudge = 2;
            int yt = y1 + lp_box_dimension + y_text_fudge;
            int xt = x1 + lp_box_dimension + lp_box_text_spacing + 2;
            snprintf(buf, sizeof(buf), "%d", ld->index(DSP()->CurMode()));
            Text(buf, xt, yt, 0);

            SetColor(DSP()->Color(PromptCursorColor));
            if (ld == LT()->CurLayer()) {
                SetLinestyle(0);
                GRmultiPt xp(5);
                xp.assign(0, x1 - 2, y1 - 2);
                xp.assign(1,
                    xp.at(0).x, xp.at(0).y + lp_box_dimension + 4);
                xp.assign(2,
                    xp.at(1).x + lp_entry_width - lp_box_text_spacing,
                    xp.at(1).y);
                xp.assign(3,
                    xp.at(2).x, xp.at(2).y - lp_box_dimension - 4);
                xp.assign(4,
                    xp.at(3).x - lp_entry_width + lp_box_text_spacing,
                    xp.at(3).y);
                PolyLine(&xp, 5);
            }

            x1 += lp_entry_width;
        }
    }
//    lp_pmap_dirty = true;
}


// Exposure redraw, avoids flicker.
//
void
QTlayerPaletteDlg::refresh(int xx, int yy, int w, int h)
{
    /*
#if GTK_CHECK_VERSION(3,0,0)
    if (!GetDrawable()->get_window())
        GetDrawable()->set_window(gtk_widget_get_window(gd_viewport));
    if (!GetDrawable()->get_window())
        return;
    int win_width = GetDrawable()->get_width();
    int win_height = GetDrawable()->get_height();
    lp_pmap_dirty = GetDrawable()->set_draw_to_pixmap();
    if (w <= 0)
        w = win_width;
    if (h <= 0)
        h = win_height;
#else
    if (!gd_window)
        gd_window = gtk_widget_get_window(gd_viewport);
    if (!gd_window)
        return;

    int win_width = gdk_window_get_width(gd_window);
    int win_height = gdk_window_get_height(gd_window);
    if (w <= 0)
        w = win_width;
    if (h <= 0)
        h = win_height;

    if (!lp_pixmap || lp_pmap_width != win_width ||
            lp_pmap_height != win_height) {
        // Widget is not currently resizable.
        if (lp_pixmap)
            gdk_pixmap_unref(lp_pixmap);
        lp_pmap_width = win_width;
        lp_pmap_height = win_height;
        lp_pixmap = gdk_pixmap_new(gd_window, lp_pmap_width, lp_pmap_height,
            gdk_visual_get_depth(GTKdev::self()->Visual()));
        lp_pmap_dirty = true;
    }

    GdkWindow *win = gd_window;
    gd_window = lp_pixmap;
#endif

    if (lp_pmap_dirty) {
        redraw();
        lp_pmap_dirty = false;
    }

#if GTK_CHECK_VERSION(3,0,0)
    GetDrawable()->set_draw_to_window();
    GetDrawable()->copy_pixmap_to_window(GC(), x, y, w, h);
#else
    gdk_window_copy_area(win, GC(), x, y, gd_window, x, y, w, h);
    gd_window = win;
#endif
    */
}


// Button1 press/release action.  Reset the current layer to the one
// pointed to, and perform necessary actions.
//
void
QTlayerPaletteDlg::b1_handler(int xx, int yy, int state, bool down)
{
    if (down) {
        if (remove(xx, yy)) {
//            lp_pmap_dirty = true;
            refresh(0, 0, 0, 0);
            return;
        }
        CDl *ld = ldesc_at(xx, yy);
        if (!ld)
            return;
        if (state & (GR_SHIFT_MASK | GR_CONTROL_MASK)) {
            if (state & GR_SHIFT_MASK)
                LT()->SetLayerVisibility(LTtoggle, ld, 
                    (DSP()->CurMode() == Electrical) || !LT()->NoPhysRedraw());
            if (state & GR_CONTROL_MASK)
                LT()->SetLayerSelectability(LTtoggle, ld);
//            lp_pmap_dirty = true;
            refresh(0, 0, 0, 0);
            return;
        }

        lp_dragging = true;
        lp_drag_x = xx;
        lp_drag_y = yy;
        LT()->HandleLayerSelect(ld);
    }
    else
        lp_dragging = false;
}


// Button2 action.  This toggles the visibility of the layers.  The
// sample box is not shown for invisible layers.  The screen is not
// redrawn after this operation unless the shift key is pressed while
// making the selection.
//
// In electrical mode, the drawing layer is always visible.  Instead
// the action on this layer is to turn the fill attribute on/off,
// changing (for now) whether dots are filled or outlined only.
//
void
QTlayerPaletteDlg::b2_handler(int xx, int yy, int state, bool down)
{
    if (down) {
        CDl *ld = ldesc_at(xx, yy);
        if (!ld)
            return;

        LT()->SetLayerVisibility(LTtoggle, ld,
            ((DSP()->CurMode() == Electrical) ||
            (LT()->NoPhysRedraw() && (state & GR_SHIFT_MASK)) ||
            (!LT()->NoPhysRedraw() && !(state & GR_SHIFT_MASK))));
//        lp_pmap_dirty = true;
        refresh(0, 0, 0, 0);
    }
}


// Button3 action.  This toggles blinking of the layer.  When activated,
// a timer function periodically alters the color table entry used by the
// selected layer(s).
//
void
QTlayerPaletteDlg::b3_handler(int xx, int yy, int state, bool down)
{
    if (down) {
        CDl *ld = ldesc_at(xx, yy);
        if (!ld)
            return;

        bool ctrl = (state & GR_CONTROL_MASK);
        bool shft = (state & GR_SHIFT_MASK);
        if (ctrl || shft) {
            LT()->HandleLayerSelect(ld);

            if (ctrl && !shft)
                MainMenu()->MenuButtonPress(MMmain, MenuCOLOR);
            else if (!ctrl && shft)
                MainMenu()->MenuButtonPress(MMmain, MenuFILL);
            else if (ctrl && shft)
                MainMenu()->MenuButtonPress(MMmain, MenuLPEDT);
        }
        else
            QTltab::self()->blink(ld);
    }
}


CDl *
QTlayerPaletteDlg::ldesc_at(int xx, int yy)
{
    if (yy < lp_hist_y)
        return (0);
    int col = (xx - 2)/lp_entry_width;
    if (col < 0)
        col = 0;
    else if (col >= LP_PALETTE_COLS)
        col = LP_PALETTE_COLS - 1;

    if (yy < lp_user_y)
        return (lp_history[col]);

    int row = (yy - lp_user_y)/(lp_user_y - lp_hist_y);
    if (row < 0)
        row = 0;
    else if (row > LP_PALETTE_ROWS-1)
        row = LP_PALETTE_ROWS-1;
    return (lp_user[row*LP_PALETTE_COLS + col]);
}


// If clicked on an entry in the user area with the Remove button
// active, remove the entry and reset the button.
//
bool
QTlayerPaletteDlg::remove(int xx, int yy)
{
    if (!QTdev::GetStatus(lp_remove))
        return (false);
    if (yy < lp_user_y)
        return (false);
    int row = (yy - lp_user_y)/(lp_user_y - lp_hist_y);
    if (row < 0)
        row = 0;
    else if (row > LP_PALETTE_ROWS-1)
        row = LP_PALETTE_ROWS-1;
    int col = (xx - 2)/lp_entry_width;
    if (col < 0)
        col = 0;
    else if (col >= LP_PALETTE_COLS)
        col = LP_PALETTE_COLS - 1;
    int ix = row*LP_PALETTE_COLS + col;
    if (lp_user[ix]) {
        int usz = LP_PALETTE_COLS * LP_PALETTE_ROWS;
        usz--;
        for (int i = ix; i < usz; i++)
            lp_user[i] = lp_user[i+1];
        lp_user[usz] = 0;
        QTdev::SetStatus(lp_remove, false);
        return (true);
    }
    return (false);
}


void
QTlayerPaletteDlg::recall_menu_slot(QAction *a)
{
    int ix = a->data().toInt();

    int usz = LP_PALETTE_COLS * LP_PALETTE_ROWS;
    for (int i = 0; i < usz; i++)
        lp_user[i] = 0;

    const char *s = Tech()->LayerPaletteReg(ix, DSP()->CurMode());
    int cnt = 0;
    char *tok;
    while ((tok = lstring::gettok(&s)) != 0) {
        CDl *ld = CDldb()->findLayer(tok, DSP()->CurMode());
        delete [] tok;
        if (!ld)
            continue;
        lp_user[cnt] = ld;
        cnt++;
    }
//    lp_pmap_dirty = true;
    refresh(0, 0, 0, 0);
}


void
QTlayerPaletteDlg::save_menu_slot(QAction *a)
{
    int ix = a->data().toInt();

    sLstr lstr;
    int usz = LP_PALETTE_COLS * LP_PALETTE_ROWS;
    for (int i = 0; i < usz; i++) {
        CDl *ld = lp_user[i];
        if (!ld)
            break;
        if (i)
            lstr.add_c(' ');
        lstr.add(ld->name());
    }
    Tech()->SetLayerPaletteReg(ix, DSP()->CurMode(), lstr.string());
}


void
QTlayerPaletteDlg::help_btn_slot()
{
    DSPmainWbag(PopUpHelp("xic:lpal"))
}


void
QTlayerPaletteDlg::font_changed_slot(int fnum)
{
    if (fnum == FNT_SCREEN) {
        QFont *fnt;
        if (FC.getFont(&fnt, FNT_SCREEN))
            gd_viewport->set_font(fnt);
        init_size();
    }
}


void
QTlayerPaletteDlg::resize_slot(QResizeEvent*)
{
}


void
QTlayerPaletteDlg::button_down_slot(QMouseEvent *ev)
{
    int button = 0;
    if (ev->button() == Qt::LeftButton)
        button = 1;
    else if (ev->button() == Qt::MiddleButton)
        button = 2;
    else if (ev->button() == Qt::RightButton)
        button = 3;

    button = Kmap()->ButtonMap(button);
    int state = ev->modifiers();

    if (XM()->IsDoingHelp() && (state & GR_SHIFT_MASK)) {
        DSPmainWbag(PopUpHelp("layertab"))
        return;
    }

    switch (button) {
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    case 1:
        b1_handler(ev->position().x(), ev->position().y(), state, true);
        break;
    case 2:
        b2_handler(ev->position().x(), ev->position().y(), state, true);
        break;
    case 3:
        b3_handler(ev->position().x(), ev->position().y(), state, true);
        break;
#else
    case 1:
        b1_handler(ev->x(), ev->y(), state, true);
        break;
    case 2:
        b2_handler(ev->x(), ev->y(), state, true);
        break;
    case 3:
        b3_handler(ev->x(), ev->y(), state, true);
        break;
#endif
    }
    update();
}


void
QTlayerPaletteDlg::button_up_slot(QMouseEvent *ev)
{
    int button = 0;
    if (ev->button() == Qt::LeftButton)
        button = 1;
    else if (ev->button() == Qt::MiddleButton)
        button = 2;
    else if (ev->button() == Qt::RightButton)
        button = 3;

    button = Kmap()->ButtonMap(button);
    int state = ev->modifiers();

    if (XM()->IsDoingHelp() && (state & GR_SHIFT_MASK)) {
        DSPmainWbag(PopUpHelp("layertab"))
        return;
    }

    switch (button) {
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    case 1:
        b1_handler(ev->position().x(), ev->position().y(), state, false);
        break;
    case 2:
        b2_handler(ev->position().x(), ev->position().y(), state, false);
        break;
    case 3:
        b3_handler(ev->position().x(), ev->position().y(), state, false);
        break;
#else
    case 1:
        b1_handler(ev->x(), ev->y(), state, false);
        break;
    case 2:
        b2_handler(ev->x(), ev->y(), state, false);
        break;
    case 3:
        b3_handler(ev->x(), ev->y(), state, false);
        break;
#endif
    }
}


void
QTlayerPaletteDlg::motion_slot(QMouseEvent *ev)
{
    if (ev->type() != QEvent::MouseMove) {
        ev->ignore();
        return;
    }
    ev->accept();

#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
    int xx = ev->position().x();
    int yy = ev->position().y();
#else
    int xx = ev->x();
    int yy = ev->y();
#endif
    if (lp_dragging &&
            (abs(xx - lp_drag_x) > 4 || abs(yy - lp_drag_y) > 4)) {
        lp_dragging = false;

//        int entry = entry_of_xy(xx, yy);
//        int last_ent = last_entry();
//        if (entry <= last_ent) {
            CDl *ld = ldesc_at(xx, yy);
            XM()->PopUpLayerPalette(0, MODE_UPD, true, ld);

            LayerFillData dd(ld);
            QDrag *drag = new QDrag(sender());
            drag->setPixmap(QPixmap(QTltab::fillpattern_xpm()));
            QMimeData *mimedata = new QMimeData();
            QByteArray qdata((const char*)&dd, sizeof(LayerFillData));
            mimedata->setData(QTltab::mime_type(), qdata);
            drag->setMimeData(mimedata);

//            QTsubwin::HaveDrag = true;
            drag->exec(Qt::CopyAction);
//            QTsubwin::HaveDrag = false;

            delete drag;
//        }
    }



    /*

    if (!Lpal)
        return (false);
    int x = (int)event->motion.x;
    int y = (int)event->motion.y;
    if (Lpal->lp_dragging &&
            (abs(x - Lpal->lp_drag_x) > 4 || abs(y - Lpal->lp_drag_y) > 4)) {
        Lpal->lp_dragging = false;
        // fillpattern only
        GtkTargetList *targets = gtk_target_list_new(lp_targets, 1);
        gtk_drag_begin(caller, targets, (GdkDragAction)GDK_ACTION_COPY,
            1, event);
    }

    CDl *ld = Lpal->ldesc_at(x, y);
    if (ld)
        Lpal->update_info(ld);
        */

}


/*
void
QTlayerPaletteDlg::key_down_slot(QKeyEvent*)
{
}


void
QTlayerPaletteDlg::key_up_slot(QKeyEvent*)
{
}
*/


void
QTlayerPaletteDlg::drag_enter_slot(QDragEnterEvent *ev)
{
    if (ev->mimeData()->hasFormat(QTltab::mime_type()))
        ev->acceptProposedAction();
    if (ev->mimeData()->hasColor())
        ev->acceptProposedAction();
}


void
QTlayerPaletteDlg::drop_slot(QDropEvent *ev)
{
    if (ev->mimeData()->hasFormat(QTltab::mime_type())) {
        QByteArray bary = ev->mimeData()->data(QTltab::mime_type());
        LayerFillData *dd = (LayerFillData*)bary.data();
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
        XM()->FillLoadCallback(dd,
                LT()->LayerAt(ev->position().x(), ev->position().y()));
#else
        XM()->FillLoadCallback(dd, LT()->LayerAt(ev->pos().x(), ev->pos().y()));
#endif
        ev->acceptProposedAction();
        if (DSP()->CurMode() == Electrical || !LT()->NoPhysRedraw())
            DSP()->RedisplayAll();
        return;
    }
    if (ev->mimeData()->hasColor()) {
        ev->acceptProposedAction();
        QColor color = qvariant_cast<QColor>(ev->mimeData()->colorData());
/* XXX
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
        int entry = entry_of_xy(ev->position().x(), ev->position().y());
#else
        int entry = entry_of_xy(ev->x(), ev->y());
#endif

        if (entry > last_entry())
            return;
        CDl *layer =
            CDldb()->layer(entry + first_visible() + 1, DSP()->CurMode());
*/
#if QT_VERSION >= QT_VERSION_CHECK(6,0,0)
        CDl *layer = ldesc_at(ev->position().x(), ev->position().y());
#else
        CDl *layer = ldesc_at(ev->pos().x(), ev->pos().y());
#endif

        LT()->SetLayerColor(layer, color.red(), color.green(), color.blue());
        // update the colors
        LT()->ShowLayerTable(layer);
        XM()->PopUpFillEditor(0, MODE_UPD);
        ev->acceptProposedAction();
        if (DSP()->CurMode() == Electrical || !LT()->NoPhysRedraw())
            DSP()->RedisplayAll();
    }
}


void
QTlayerPaletteDlg::dismiss_btn_slot()
{
    XM()->PopUpLayerPalette(0, MODE_OFF, false, 0);
}


#ifdef notdef

// Static function.
// Widget is not resizable.
int
QTlayerPaletteDlg::lp_resize_hdlr(GtkWidget*, GdkEvent*, void*)
{
    if (!Lpal)
        return (0);
#if GTK_CHECK_VERSION(3,0,0)
    if (!Lpal->GetDrawable()->get_window()) {
        GdkWindow *window = gtk_widget_get_window(Lpal->gd_viewport);
        Lpal->GetDrawable()->set_window(window);
    }
#else
    if (!Lpal->gd_window)
        Lpal->gd_window = gtk_widget_get_window(Lpal->gd_viewport);
#endif
    Lpal->update_layer(LT()->CurLayer());
    Lpal->update_info(LT()->CurLayer());
    return (true);
}


// Static function.
// Redraw the drawing area.
//
#if GTK_CHECK_VERSION(3,0,0)
int
QTlayerPaletteDlg::lp_redraw_hdlr(GtkWidget*, cairo_t *cr, void*)
#else
int
QTlayerPaletteDlg::lp_redraw_hdlr(GtkWidget*, GdkEvent *event, void*)
#endif
{
#if GTK_CHECK_VERSION(3,0,0)
    cairo_rectangle_int_t rect;
    ndkDrawable::redraw_area(cr, &rect);
    Lpal->refresh(rect.x, rect.y, rect.width, rect.height);
#else
    GdkEventExpose *pev = (GdkEventExpose*)event;
    Lpal->refresh(pev->area.x, pev->area.y,
        pev->area.width, pev->area.height);
#endif
    return (true);
}


// Static function.
// Set the pixmap.
//
void
QTlayerPaletteDlg::lp_drag_begin(GtkWidget*, GdkDragContext *context, gpointer)
{
    GdkPixbuf *pixbuf = gdk_pixbuf_new_from_xpm_data(fillpattern_xpm);
    gtk_drag_set_icon_pixbuf(context, pixbuf, -2, -2);
    GTKsubwin::HaveDrag = true;
}


// Static function.
void
QTlayerPaletteDlg::lp_drag_end(GtkWidget*, GdkDragContext*, gpointer)
{
    GTKsubwin::HaveDrag = false;
}


// Static function.
// Initialize data for drag/drop transfer from 'this'.
//
void
QTlayerPaletteDlg::lp_drag_data_get(GtkWidget*, GdkDragContext*,
    GtkSelectionData *data, guint, guint, void*)
{
    CDl *ld = LT()->CurLayer();
    if (!ld)
        return;
    LayerFillData dd(ld);
    gtk_selection_data_set(data, gtk_selection_data_get_target(data),
        8, (unsigned char*)&dd, sizeof(LayerFillData));
}


    /*
    // The layer table is a dnd source for fill patterns, and a receiver for
    // fillpatterns and colors.
    //
    GtkTargetEntry lp_targets[] = {
        { (char*)"fillpattern", 0, 0 },
        { (char*)"application/x-color", 0, 1 }
    };
    guint n_lp_targets = sizeof(lp_targets) / sizeof(lp_targets[0]);
    */

// Static function.
// Drag data received from layer table, or from 'this'.  The layer is added
// to the user palette line.
//
void
QTlayerPaletteDlg::lp_drag_data_received(GtkWidget*, GdkDragContext *context,
    gint x, gint y, GtkSelectionData *data, guint, guint time)
{
    // datum is a guint16 array of the format:
    //  R G B opacity
    GdkAtom a = gdk_atom_intern("fillpattern", true);
    if (gtk_selection_data_get_target(data) == a) {
        LayerFillData *dd = (LayerFillData*)gtk_selection_data_get_data(data);
        if (dd->d_from_layer) {
            if (dd->d_layernum > 0) {
                CDl *ld = CDldb()->layer(dd->d_layernum, DSP()->CurMode());
                if (ld && Lpal)
                    Lpal->update_user(ld, x, y);
            }
        }
        else {
            CDl *ld = Lpal->ldesc_at(x, y);
            XM()->FillLoadCallback(
                (LayerFillData*)gtk_selection_data_get_data(data), ld);
            // update the colors
            Lpal->update_layer(0);
            LT()->ShowLayerTable(ld);
            XM()->PopUpFillEditor(0, MODE_UPD);
        }
    }
    else {
        if (gtk_selection_data_get_length(data) < 0) {
            gtk_drag_finish(context, false, false, time);
            return;
        }
        if (gtk_selection_data_get_format(data) != 16 ||
                gtk_selection_data_get_length(data) != 8) {
            fprintf(stderr, "Received invalid color data\n");
            gtk_drag_finish(context, false, false, time);
            return;
        }
        guint16 *vals = (guint16*)gtk_selection_data_get_data(data);

        CDl *ld = Lpal->ldesc_at(x, y);

        LT()->SetLayerColor(ld, vals[0] >> 8, vals[1] >> 8, vals[2] >> 8);
        // update the colors
        Lpal->update_layer(0);
        LT()->ShowLayerTable(ld);
        XM()->PopUpFillEditor(0, MODE_UPD);
    }
    gtk_drag_finish(context, true, false, time);
    if (DSP()->CurMode() == Electrical || !LT()->NoPhysRedraw())
        DSP()->RedisplayAll();
}

#endif
