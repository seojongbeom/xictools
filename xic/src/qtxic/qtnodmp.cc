
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

#include "config.h"
#include "qtnodmp.h"
#include "sced.h"
#include "sced_nodemap.h"
#include "extif.h"
#include "dsp_inlines.h"
#include "cd_propnum.h"
#include "cd_terminal.h"
#include "cd_netname.h"
#include "events.h"
#include "menu.h"
#include "ebtn_menu.h"
#include "ext_menu.h"
#include "select.h"
#include "promptline.h"
#include "errorlog.h"
#include "qtinterf/qtinput.h"

#include "bitmaps/lsearch.xpm"
#ifdef HAVE_REGEX_H
#include <regex.h>
#else
#include "regex/regex.h"
#endif

#include <QLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTreeWidget>
#include <QRadioButton>
#include <QSplitter>
#include <QCheckBox>
#include <QLabel>
#include <QHeaderView>


namespace {
    // Some utilities for GtkTreeView.

    // Return the text item at row,col, needs to be freed.
    //
    char *list_get_text(QTreeWidget *list, int row, int col)
    {
        return (0);
        /*
        GtkTreePath *p = gtk_tree_path_new_from_indices(row, -1);
        GtkTreeModel *store = gtk_tree_view_get_model(GTK_TREE_VIEW(list));
        GtkTreeIter iter;
        if (!gtk_tree_model_get_iter(store, &iter, p))
            return (0);
        char *text;
        gtk_tree_model_get(store, &iter, col, &text, -1);
        gtk_tree_path_free(p);
        return (lstring::tocpp(text));
        */
    }

    void list_move_to(QTreeWidget *list, int row)
    {
        /*
        // Run events, this is important:  If the cells have been
        // recently updated, the get_background_area call will return
        // a bogus value!  (GTK bug)
        //
        gtk_DoEvents(1000);

        // Don't scroll unless we have to, the scroll_to_cell function
        // doesn't do the right thing, so we attempt to handle this
        // ourselves.  We can do this since to cell height is fixed.

        GtkAdjustment *adj = gtk_tree_view_get_vadjustment(GTK_TREE_VIEW(list));
        if (!adj)
            return;

        GtkTreePath *p = gtk_tree_path_new_from_indices(row, -1);
        GdkRectangle r;
        gtk_tree_view_get_background_area(GTK_TREE_VIEW(list), p, 0, &r);

        int last_row = (int)(gtk_adjustment_get_value(adj)/r.height);
        int vis_rows = (int)(gtk_adjustment_get_page_size(adj)/r.height);
        if (row < last_row || row > last_row + vis_rows) {
            gtk_tree_view_scroll_to_cell(GTK_TREE_VIEW(list), p, 0,
                false, 0.0, 0.0);
        }
        gtk_tree_path_free(p);
        */
    }

    void list_select_row(QTreeWidget *list, int row)
    {
        /*
        GtkTreePath *p = gtk_tree_path_new_from_indices(row, -1);
        GtkTreeSelection *sel =
            gtk_tree_view_get_selection(GTK_TREE_VIEW(list));
        gtk_tree_selection_select_path(sel, p);
        gtk_tree_path_free(p);
        */
    }
}


namespace ns_nodmp {
    struct NmpState : public CmdState
    {
        NmpState(const char *nm, const char *hk) : CmdState(nm, hk) { }
        virtual ~NmpState();

        void b1down() { cEventHdlr::sel_b1down(); }
        void b1up();
        void b1up_altw();
        void esc();
    };
}


//-------------------------------------------------------------------------
// Node (Net) Name Mapping
//
// Help system keywords used:
//  xic:nodmp

// The return is true when MODE_UPD, and an update was done.  This is
// used by the extraction system.  True is also returned on successful
// MODE_ON.
//
bool
cSced::PopUpNodeMap(GRobject caller, ShowMode mode, int node)
{
    if (!QTdev::exists() || !QTmainwin::exists())
        return (false);
    if (mode == MODE_OFF) {
        if (QTnodeMapDlg::self())
            QTnodeMapDlg::self()->deleteLater();
        return (false);
    }
    if (mode == MODE_UPD) {
        if (QTnodeMapDlg::self())
            return (QTnodeMapDlg::self()->update(node));
        return (false);
    }
    if (QTnodeMapDlg::self())
        return (true);
    if (!CurCell(Electrical, true))
        return (false);

    new QTnodeMapDlg(caller, node);

    QTnodeMapDlg::self()->set_transient_for(QTmainwin::self());
    QTdev::self()->SetPopupLocation(GRloc(LW_LL), QTnodeMapDlg::self(),
        QTmainwin::self()->Viewport());
    QTnodeMapDlg::self()->show();
    return (true);
}
// End of cSced functions.


bool QTnodeMapDlg::nm_use_extract;
short int QTnodeMapDlg::nm_win_width;
short int QTnodeMapDlg::nm_win_height;
short int QTnodeMapDlg::nm_grip_pos;
QTnodeMapDlg *QTnodeMapDlg::instPtr;

QTnodeMapDlg::QTnodeMapDlg(GRobject caller, int node)
{
    instPtr = this;
    nm_caller = caller;
    nm_cmd = 0;
    nm_use_np = 0;
    nm_rename = 0;
    nm_remove = 0;
    nm_point_btn = 0;
    nm_srch_btn = 0;
    nm_srch_entry = 0;
    nm_srch_nodes = 0;
    nm_node_list = 0;
    nm_term_list = 0;
    nm_usex_btn = 0;
    nm_find_btn = 0;
    nm_showing_node = -1;
    nm_showing_row = -1;
    nm_showing_term_row = -1;
    nm_noupdating = false;
    nm_node = 0;
    nm_cdesc = 0;
    nm_rm_affirm = 0;
    nm_join_affirm = 0;
    nm_n_no_select = false;
    nm_t_no_select = false;

    setWindowTitle(tr("Node (Net) Name Mapping"));
    setAttribute(Qt::WA_DeleteOnClose);

    QMargins qmtop(2, 2, 2, 2);
    QMargins qm;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(qmtop);
    vbox->setSpacing(2);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    // button line
    //
    nm_use_np = new QPushButton(tr("Use nophys"));
    nm_use_np->setCheckable(true);
    hbox->addWidget(nm_use_np);
    connect(nm_use_np, SIGNAL(toggled(bool)),
        this, SLOT(nophys_btn_slot(bool)));

    nm_rename = new QPushButton(tr("Map Name"));
    nm_rename->setCheckable(true);
    hbox->addWidget(nm_rename);
    connect(nm_rename, SIGNAL(toggled(bool)),
        this, SLOT(mapname_btn_slot(bool)));

    nm_remove = new QPushButton(tr("Unmap"));
    nm_remove->setCheckable(true);
    hbox->addWidget(nm_remove);
    connect(nm_remove, SIGNAL(toggled(bool)),
        this, SLOT(unmap_btn_slot(bool)));

    nm_point_btn = new QPushButton(tr("Click-Select Mode"));
    nm_point_btn->setCheckable(true);
    hbox->addWidget(nm_point_btn);
    connect(nm_point_btn, SIGNAL(toggled(bool)),
        this, SLOT(click_btn_slot(bool)));

    QPushButton *btn = new QPushButton(tr("Help"));
    hbox->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(help_btn_slot()));

    // second button line
    //
    hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    QLabel *label = new QLabel(tr("Search"));
    hbox->addWidget(label);

    nm_srch_btn = new QPushButton();
    hbox->addWidget(nm_srch_btn);
    nm_srch_btn->setIcon(QIcon(QPixmap(lsearch_xpm)));
    connect(nm_srch_btn, SIGNAL(clicked()), this, SLOT(srch_btn_slot()));

    nm_srch_entry = new QLineEdit();
    hbox->addWidget(nm_srch_entry);
    connect(nm_srch_entry, SIGNAL(textChanged(const QString&)),
        this, SLOT(srch_text_changed_slot(const QString&)));

    nm_srch_nodes = new QRadioButton(tr("Nodes"));
    hbox->addWidget(nm_srch_nodes);
    QRadioButton *rbtn = new QRadioButton(tr("Terminals"));
    hbox->addWidget(rbtn);

    hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    QSplitter *spl = new QSplitter();
    hbox->addWidget(spl);
    spl->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);

    // node listing text
    //
    nm_node_list = new QTreeWidget();
    spl->addWidget(nm_node_list);
    nm_node_list->setHeaderLabels(QStringList(QList<QString>() <<
        tr("Internal?") << tr("Mapped") << tr("Set")));
    nm_node_list->header()->setMinimumSectionSize(25);
    nm_node_list->header()->resizeSection(0, 50);

    // terminal listing text
    //
    nm_term_list = new QTreeWidget();
    spl->addWidget(nm_term_list);
    nm_term_list->setHeaderLabels(QStringList(QList<QString>() <<
        tr("Terminals?")));
    nm_term_list->header()->setMinimumSectionSize(25);

    int wd1 = 0.75*width();
    spl->setSizes(QList<int>() << wd1 << width());

    QFont *fnt;
    if (FC.getFont(&fnt, FNT_PROP)) {
        nm_node_list->setFont(*fnt);
        nm_term_list->setFont(*fnt);
    }
    connect(QTfont::self(), SIGNAL(fontChanged(int)),
        this, SLOT(font_changed_slot(int)), Qt::QueuedConnection);

    // cancel button row
    //
    hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    btn = new QPushButton(tr(" Deselect "));
    hbox->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(deselect_btn_slot()));

    btn = new QPushButton(tr("Dismiss"));
    hbox->addWidget(btn);
    connect(btn, SIGNAL(clicked()), this, SLOT(dismiss_btn_slot()));

    nm_usex_btn = new QCheckBox(tr("Use Extract"));
    hbox->addWidget(nm_usex_btn);
    connect(nm_usex_btn, SIGNAL(stateChanged(int)),
        this, SLOT(usex_btn_slot(int)));
    if (ExtIf()->hasExtract())
        nm_usex_btn->show();
    else
        nm_usex_btn->hide();

    nm_find_btn = new QPushButton(tr("Find"));
    hbox->addWidget(nm_find_btn);
    connect(nm_find_btn, SIGNAL(clicked()), this, SLOT(find_btn_slot()));

    // If the group/node selection mode in extraction is enabled with
    // a selection, configure the pop-up to have that node selected.
    //
    if (node < 0 && DSP()->ShowingNode() >= 0 && ExtIf()->selectShowNode(-1))
        node = DSP()->ShowingNode();

/*XXX
    if (nm_win_width > 0 && nm_win_height > 0) {
        gtk_window_set_default_size(GTK_WINDOW(wb_shell),
            nm_win_width, nm_win_height);
        gtk_paned_set_position(GTK_PANED(nm_paned), nm_grip_pos);
    }
*/
    if (DSP()->CurMode() == Physical)
        nm_use_extract = true;
    update(node);
    ExtIf()->PopUpExtSetup(0, MODE_UPD);
}


QTnodeMapDlg::~QTnodeMapDlg()
{
    instPtr = 0;
    if (nm_cmd)
        nm_cmd->esc();
    bool state = QTdev::GetStatus(nm_rename);
    if (state)
        EV()->InitCallback();

    // Keep node selected if extraction group/node selection is active.
    if (!ExtIf()->selectShowNode(-1))
        DSP()->ShowNode(ERASE, nm_showing_node);

    if (nm_rm_affirm)
        nm_rm_affirm->popdown();
    if (nm_join_affirm)
        nm_join_affirm->popdown();
    if (nm_caller)
        QTdev::SetStatus(nm_caller, false);
    if (wb_shell) {
/*
        int wid = gdk_window_get_width(gtk_widget_get_window(wb_shell));
        int hei = gdk_window_get_height(gtk_widget_get_window(wb_shell));
        nm_win_width = wid;
        nm_win_height = hei;
        nm_grip_pos = gtk_paned_get_position(GTK_PANED(nm_paned));
        g_signal_handlers_disconnect_by_func(G_OBJECT(wb_shell),
            (gpointer)nm_cancel_proc, wb_shell);
*/
    }
    if (nm_node) {
        DSP()->HliteElecTerm(ERASE, nm_node, nm_cdesc, 0);
        CDterm *t;
        if (nm_cdesc)
            t = ((CDp_cnode*)nm_node)->inst_terminal();
        else
            t = ((CDp_snode*)nm_node)->cell_terminal();
        DSP()->HlitePhysTerm(ERASE, t);
    }
    ExtIf()->PopUpExtSetup(0, MODE_UPD);
}


bool
QTnodeMapDlg::update(int node)
{
    if (nm_noupdating)
        return (true);

    bool iselec = (DSP()->CurMode() == Electrical);
    nm_use_np->setEnabled(iselec);
    nm_rename->setEnabled(false);
    nm_remove->setEnabled(false);
    if (nm_rm_affirm)
        nm_rm_affirm->popdown();
    if (nm_join_affirm)
        nm_join_affirm->popdown();
    if (wb_input)
        wb_input->popdown();

    CDs *cursde = CurCell(Electrical);  // allow symbolic for check below
    if (!cursde) {
        SCD()->PopUpNodeMap(0, MODE_OFF);
        return (false);
    }

    if (node >= 0) {
        // This update is coming from group/node selection in the
        // extraction system.  Make sure that net we're not in
        // use-nophys mode.
        SCD()->setIncludeNoPhys(false);
        SCD()->connect(cursde);
    }

    DSP()->ShowNode(ERASE, nm_showing_node);
    enable_point(!cursde->isSymbolic());
    nm_showing_row = -1;

    if (node >= 0) {
        for (int row = 0; ; row++) {
            int n = node_of_row(row);
            if (n < 0)
                break;
            if (n == node) {
                nm_showing_node = node;
                break;
            }
        }
    }
    update_map();

    QTdev::SetStatus(nm_usex_btn, nm_use_extract);
    QTdev::SetStatus(nm_use_np, SCD()->includeNoPhys());
    if (nm_use_extract) {
        QTdev::SetStatus(nm_point_btn,
            MainMenu()->MenuButtonStatus(MMext, MenuEXSEL));
    }
    else
        QTdev::SetStatus(nm_point_btn, (nm_cmd != 0));
    return (true);
}


void
QTnodeMapDlg::show_node_terms(int node)
{
    DSP()->ShowNode(ERASE, nm_showing_node);
    nm_showing_node = -1;

    nm_term_list->clear();
    nm_find_btn->setEnabled(false);
    if (nm_node) {
        DSP()->HliteElecTerm(ERASE, nm_node, nm_cdesc, 0);
        CDterm *t;
        if (nm_cdesc)
            t = ((CDp_cnode*)nm_node)->inst_terminal();
        else
            t = ((CDp_snode*)nm_node)->cell_terminal();
        DSP()->HlitePhysTerm(ERASE, t);
        nm_node = 0;
    }
    nm_cdesc = 0;

/*
    GtkTreeIter iter;
    const char *strings[1];
    const char *msg = "no terminals found";
    CDs *cursde = CurCell(Electrical, true);
    if (!cursde)
        return;
    if (node < 0) {
        strings[0] = "bad node";
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, strings[0], -1);
    }
    else if (node == 0) {
        strings[0] = "ground node";
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, strings[0], -1);
        nm_showing_node = node;
    }
    else {
        bool didone = false;
        stringlist *sl = SCD()->getElecNodeContactNames(cursde, node);
        for (stringlist *s = sl; s; s = s->next) {
            strings[0] = s->string;
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, strings[0], -1);
            didone = true;
        }
        stringlist::destroy(sl);
        if (!didone) {
            strings[0] = msg;
            gtk_list_store_append(store, &iter);
            gtk_list_store_set(store, &iter, 0, strings[0], -1);
        }
        nm_showing_node = node;
    }
*/
    DSP()->ShowNode(DISPLAY, nm_showing_node);
}


void
QTnodeMapDlg::update_map()
{
    CDcbin cbin(DSP()->CurCellName());
    if (!cbin.elec())
        return;

    // Grab a list of the node properties connected to the node being
    // shown, if any, before the connectivity update.
    CDpl *pl = SCD()->getElecNodeProps(cbin.elec(), nm_showing_node);

    cNodeMap *map = cbin.elec()->nodes();
    if (!map) {
        map = new cNodeMap(cbin.elec());
        cbin.elec()->setNodes(map);
    }
    // this updates the node map
    SCD()->connect(cbin.elec());

    int last_row = 0;
    int vis_rows = 10;
    {
/*
        GtkTreePath *p = gtk_tree_path_new_from_indices(0, -1);
        GdkRectangle r;
        gtk_tree_view_get_background_area(GTK_TREE_VIEW(nm_node_list),
            p, 0, &r);
        gtk_tree_path_free(p);
        if (r.height > 0) {
            GtkAdjustment *adj =
                gtk_tree_view_get_vadjustment(GTK_TREE_VIEW(nm_node_list));
            if (adj) {
                last_row = (int)(gtk_adjustment_get_value(adj)/r.height);
                vis_rows = (int)(gtk_adjustment_get_page_size(adj)/r.height);
            }
        }
*/
    }

    nm_rename->setEnabled(false);
    nm_remove->setEnabled(false);

    nm_node_list->clear();

/*
    GtkTreeIter iter;
    int sz = map->countNodes();
    for (int i = 0; i < sz; i++) {
        char buf1[32], buf2[4];
        snprintf(buf1, sizeof(buf1), "%d", i);
        buf2[0] = 0;
        buf2[1] = 0;
        buf2[2] = 0;
        char *strings[3];
        strings[0] = buf1;
        strings[1] = (char*)map->mapName(i);
        strings[2] = buf2;
        char *t = buf2;
        if (map->isGlobal(i) || i == 0)
            *t++ = 'G';
        if (map->isSet(i))
            *t++ = 'Y';
        gtk_list_store_append(store, &iter);
        gtk_list_store_set(store, &iter, 0, strings[0], 1, strings[1],
            2, strings[2], -1);
    }

    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(NM->nm_term_list));
    gtk_tree_selection_unselect_all(sel);
    store =
        GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(nm_term_list)));
    gtk_list_store_clear(store);
    gtk_widget_set_sensitive(nm_find_btn, false);
    if (nm_node) {
        DSP()->HliteElecTerm(ERASE, nm_node, nm_cdesc, 0);
        CDterm *t;
        if (nm_cdesc)
            t = ((CDp_cnode*)nm_node)->inst_terminal();
        else
            t = ((CDp_snode*)nm_node)->cell_terminal();
        DSP()->HlitePhysTerm(ERASE, t);
        nm_node = 0;
    }
*/
    nm_cdesc = 0;

    // The node number may have changed, try to find the new one, but
    // it may have disappeared.
    //
    if (nm_showing_node > 0 && pl) {
        bool found = false;
        for (CDpl *p = pl; p; p = p->next) {
            int node = ((CDp_cnode*)p->pdesc)->enode();
            CDpl *plx = SCD()->getElecNodeProps(cbin.elec(), node);
            for (CDpl *px = plx; px; px = px->next) {
                if (px->pdesc == p->pdesc) {
                    found = true;
                    break;
                }
            }
            CDpl::destroy(plx);
            if (found) {
                nm_showing_node = node;
                break;
            }
        }
        if (!found)
            nm_showing_node = -1;
    }
    CDpl::destroy(pl);

    if (nm_showing_node >= 0) {
        // select row
        for (int row = 0; ; row++) {
            int node = node_of_row(row);
            if (node < 0)
                break;
            if (node == nm_showing_node) {
                list_select_row(nm_node_list, row);
                // Make sure selection is visible.
                if (row < last_row || row >= last_row + vis_rows)
                    last_row = row;
                break;
            }
        }

        list_move_to(nm_node_list, last_row);
    }
}


void
QTnodeMapDlg::enable_point(bool on)
{
    if (on)
        nm_point_btn->setEnabled(true);
    else {
        if (nm_cmd)
            nm_cmd->esc();
        nm_point_btn->setEnabled(false);
    }
}


int
QTnodeMapDlg::node_of_row(int row)
{
    /*
    char *text = list_get_text(NM->nm_node_list, row, 0);
    if (!text)
        return (-1);
    int node;
    if (sscanf(text, "%d", &node) < 1 || node < 0)
        node = -1;
    delete [] text;
    return (node);
    */
return (-1);
}


// Apply the name to the currently selected node.
//
void
QTnodeMapDlg::set_name(const char *name)
{
    cNodeMap *map = CurCell(Electrical)->nodes();
    if (!map)
        // "can't happen"
        return;
    int node = node_of_row(nm_showing_row);
    if (node < 0)
        // "can't happen"
        return;

    if (!map->newEntry(name, node)) {
        sLstr lstr;
        lstr.add("Operation failed: ");
        lstr.add(Errs()->get_error());
        PopUpMessage(lstr.string(), true);
        return;
    }
    DSP()->ShowNode(ERASE, nm_showing_node);
    nm_showing_node = -1;
    update_map();
    int indx = find_row(name);
    if (indx >= 0) {
        list_select_row(nm_node_list, indx);
        list_move_to(nm_node_list, indx);
        // Row-select causes the input widget to pop-down.
        char buf[256];
        snprintf(buf, 256,
            " Name %s is linked to internal node %d. ",
            name, node_of_row(indx));
        PopUpMessage(buf, false);
    }
    else
        PopUpMessage("Operation failed, unknown error.", true);
}


// Function to actually perform the search.
//
void
QTnodeMapDlg::do_search(int *pindx, int *ptindx)
{
    if (pindx)
        *pindx = -1;
    if (ptindx)
        *ptindx = -1;
    QByteArray str_ba = nm_srch_entry->text().toLatin1();
    const char *str = str_ba.constData();
    if (!str || !*str)
        return;

    regex_t preg;
    if (regcomp(&preg, str, REG_EXTENDED | REG_ICASE | REG_NOSUB)) {
        PopUpMessage("Regular expression syntax error.", true);
        return;
    }

    if (QTdev::GetStatus(nm_srch_nodes)) {
        for (int i = nm_showing_row + 1; ; i++) {
            char *text = list_get_text(nm_node_list, i, 1);
            if (!text)
                break;
            int r = regexec(&preg, text, 0, 0, 0);
            delete [] text;
            if (!r) {
                regfree(&preg);
                if (pindx)
                    *pindx = i;
                regfree(&preg);
                return;
            }
        }
    }
    else {
        CDs *cursde = CurCell(Electrical, true);
        if (!cursde) {
            regfree(&preg);
            return;
        }
        int start = nm_showing_row;
        if (start < 0)
            start = 0;
        for (int i = start; ; i++) {
            int n = node_of_row(i);
            if (n == 0)
                continue;
            if (n < 0)
                break;
            stringlist *sl = SCD()->getElecNodeContactNames(cursde, n);
            int trow = 0;
            for (stringlist *s = sl; s; s = s->next) {
                if (i == nm_showing_row && trow <= nm_showing_term_row) {
                    trow++;
                    continue;
                }
                if (!regexec(&preg, s->string, 0, 0, 0)) {
                    regfree(&preg);
                    if (pindx)
                        *pindx = i;
                    if (ptindx)
                        *ptindx = trow;
                    stringlist::destroy(sl);
                    regfree(&preg);
                    return;
                }
                trow++;
            }
            stringlist::destroy(sl);
        }
    }

    regfree(&preg);
}


// Find the row with the name given.
//
int
QTnodeMapDlg::find_row(const char *str)
{
    if (!str || !*str)
        return (-1);
    CDnetName nn = CDnetex::name_tab_find(str);
    if (nn) {
        for (int i = 1; ; i++) {
            char *text = list_get_text(nm_node_list, i, 1);
            if (!text)
                break;
            if (!strcmp(Tstring(nn), text)) {
                delete [] text;
                return (i);
            }
            delete [] text;
        }
    }
    return (-1);
}


// Static function.
// Handler for the name entry pop-up.
//
void
QTnodeMapDlg::nm_name_cb(const char *name, void*)
{
    if (!instPtr)
        return;
    char *nametok = lstring::clip_space(name);
    if (!nametok)
        return;
    cNodeMap *map = CurCell(Electrical)->nodes();
    if (!map)
        // "can't happen"
        return;
    int node = instPtr->node_of_row(instPtr->nm_showing_row);
    if (node < 0)
        // "can't happen"
        return;

    // Check giving a name already in use.
    int nx = map->findNode(nametok);
    if (nx >= 0 && nx != node) {
        char buf[256];
        snprintf(buf, 256,
        " A net named \"%s\" already exists, and will be joined with\n"
        " the selected net.  This can make schematics difficult to trace.\n"
        " Do you wish to join the nets?", nametok);

        // Callback frees nametok.
        instPtr->nm_join_affirm = instPtr->PopUpAffirm(0, LW_CENTER, buf,
            instPtr->nm_join_cb, nametok);
        instPtr->nm_join_affirm->register_usrptr((void**)&instPtr->nm_join_affirm);
        return;
    }
    instPtr->set_name(nametok);
    delete [] nametok;
}


// Static function.
// Handler for the join nets affirmation pop-up.  This pop-up appears
// if the user gives a net name already in use.  The arg is a malloc'ed
// name token which needs to be freed.
//
void
QTnodeMapDlg::nm_join_cb(bool yes, void *arg)
{
    char *name = (char*)arg;
    if (instPtr && yes)
        instPtr->set_name(name);
    delete [] name;
}


// Static function.
// Handler for the remove mapping confirmation pop-up.
//
void
QTnodeMapDlg::nm_rm_cb(bool yes, void*)
{
    char buf[256];
    if (yes && instPtr && instPtr->nm_showing_row >= 0) {
        int node = instPtr->node_of_row(instPtr->nm_showing_row);
        if (node > 0) {
            CDs *cursde = CurCell(Electrical, true);
            if (cursde) {
                cNodeMap *map = cursde->nodes();
                if (map) {
                    char *text = list_get_text(instPtr->nm_node_list,
                        instPtr->nm_showing_row, 1);
                    if (text && *text) {
                        snprintf(buf, 256,
                            "Name %s link with internal node %d removed.",
                            text, node);
                        map->delEntry(node);
                        instPtr->update_map();
                        instPtr->PopUpMessage(buf, false);
                        delete [] text;
                        return;
                    }
                    delete [] text;
                }
            }
        }
    }
    if (yes && instPtr)
        instPtr->PopUpMessage("No name/node link found.", true);
}


void
QTnodeMapDlg::nophys_btn_slot(bool state)
{
    SCD()->setIncludeNoPhys(state);
    SCD()->connect(CurCell(Electrical, true));
}


void
QTnodeMapDlg::mapname_btn_slot(bool state)
{
    if (!state) {
        if (wb_input)
            wb_input->popdown();
        return;
    }
    if (nm_showing_row < 0) {
        PopUpMessage("No selected node to name/rename.", true);
        QTdev::Deselect(nm_rename);
        return;
    }

    EV()->InitCallback();
    int node = node_of_row(nm_showing_row);
    if (node < 0) {
        PopUpMessage("Error, unknown or bad node.", true);
        QTdev::Deselect(nm_rename);
        return;
    }
    if (node == 0) {
        PopUpMessage("Can't rename the ground node.", true);
        QTdev::Deselect(nm_rename);
        return;
    }

    CDs *cursde = CurCell(Electrical, true);
    if (!cursde) {
        PopUpMessage("No currrent cell.", true);
        QTdev::Deselect(nm_rename);
        return;
    }

    cNodeMap *map = cursde->nodes();
    if (!map) {
        PopUpMessage("Internal error: no map.", true);
        QTdev::Deselect(nm_rename);
        return;
    }
    if (map->isGlobal(node)) {
        PopUpMessage("Node is global, can't set name.", true);
        QTdev::Deselect(nm_rename);
        return;
    }

    char buf[256];
    snprintf(buf, 256, " Name for internal node %d ? ", node);
    char *text = list_get_text(nm_node_list, nm_showing_row, 1);
    PopUpInput(buf, text, "Apply", nm_name_cb, 0);
    if (wb_input)
        wb_input->register_caller(nm_rename);
    delete [] text;
}


void
QTnodeMapDlg::unmap_btn_slot(bool state)
{
    if (!state) {
        if (nm_rm_affirm)
            nm_rm_affirm->popdown();
        return;
    }

    char buf[256];
    if (nm_showing_row >= 0) {
        int node = node_of_row(nm_showing_row);
        if (node > 0) {
            CDs *cursde = CurCell(Electrical, true);
            if (cursde) {
                cNodeMap *map = cursde->nodes();
                if (map) {
                    char *text = list_get_text(nm_node_list,
                        nm_showing_row, 1);
                    if (text && *text) {
                        snprintf(buf, 256,
                            " Remove name %s link with internal node %d ? ",
                            text, node);
                        nm_rm_affirm = PopUpAffirm(nm_remove, LW_CENTER,
                            buf, nm_rm_cb, 0);
                        nm_rm_affirm->register_usrptr(
                            (void**)&nm_rm_affirm);
                        delete [] text;
                        return;
                    }
                    delete [] text;
                }
            }
        }
    }
    PopUpMessage("No name/node link found.", false);
//XXX    GTKdev::Deselect(caller);
}


void
QTnodeMapDlg::click_btn_slot(bool state)
{
    if (nm_use_extract) {
        bool st = MainMenu()->MenuButtonStatus(MMext, MenuEXSEL);
        if (st != state)
            MainMenu()->MenuButtonPress(MMext, MenuEXSEL);
    }
    else {
        if (state) {
            if (!nm_cmd) {
                EV()->InitCallback();
                nm_cmd = new NmpState("NODESEL", "xic:nodmp#click");
                if (!EV()->PushCallback(nm_cmd)) {
                    delete nm_cmd;
                    nm_cmd = 0;
                    QTdev::Deselect(nm_point_btn);
                    return;
                }
            }
            PL()->ShowPrompt("Selection of nodes in drawing is enabled.");
        }
        else {
            if (nm_cmd)
                nm_cmd->esc();
            PL()->ShowPrompt("Selection of nodes in drawing is disabled.");
        }
    }
}


void
QTnodeMapDlg::help_btn_slot()
{
    DSPmainWbag(PopUpHelp("xic:nodmp"))
}


void
QTnodeMapDlg::srch_btn_slot()
{
    int indx, tindx;
    do_search(&indx, &tindx);
    if (indx >= 0) {
        list_select_row(nm_node_list, indx);
        list_move_to(nm_node_list, indx);
    }
    if (tindx >= 0) {
        list_select_row(nm_term_list, tindx);
        list_move_to(nm_term_list, tindx);
    }
}


void
QTnodeMapDlg::srch_text_changed_slot(const QString&)
{
}


void
QTnodeMapDlg::deselect_btn_slot()
{
    DSP()->ShowNode(ERASE, nm_showing_node);
    nm_showing_node = -1;

/*
    GtkTreeSelection *sel =
        gtk_tree_view_get_selection(GTK_TREE_VIEW(NM->nm_node_list));
    gtk_tree_selection_unselect_all(sel);

    sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(NM->nm_term_list));
    gtk_tree_selection_unselect_all(sel);
    GtkListStore *store = GTK_LIST_STORE(
        gtk_tree_view_get_model(GTK_TREE_VIEW(NM->nm_term_list)));
    gtk_list_store_clear(store);
*/

    nm_find_btn->setEnabled(false);
    nm_rename->setEnabled(false);
    nm_remove->setEnabled(false);
    if (nm_rm_affirm)
        nm_rm_affirm->popdown();
    if (nm_join_affirm)
        nm_join_affirm->popdown();
    if (wb_input)
        wb_input->popdown();
    if (nm_node) {
        DSP()->HliteElecTerm(ERASE, nm_node, nm_cdesc, 0);
        CDterm *t;
        if (nm_cdesc)
            t = ((CDp_cnode*)nm_node)->inst_terminal();
        else
            t = ((CDp_snode*)nm_node)->cell_terminal();
        DSP()->HlitePhysTerm(ERASE, t);
        nm_node = 0;
    }
    nm_cdesc = 0;
}


void
QTnodeMapDlg::dismiss_btn_slot()
{
    SCD()->PopUpNodeMap(0, MODE_OFF);
}


void
QTnodeMapDlg::usex_btn_slot(int state)
{
    nm_use_extract = state;
    if (nm_cmd)
        nm_cmd->esc();
    update(0);
}


void
QTnodeMapDlg::find_btn_slot()
{
    int row = nm_showing_term_row;
    if (row < 0)
        return;
    if (nm_use_extract) {
        CDs *psd = CurCell(Physical);
        if (psd) {
            if (!ExtIf()->associate(psd)) {
                Log()->ErrorLogV(mh::Processing, "Association failed!\n%s",
                    Errs()->get_error());
            }
        }
    }

    char *text = list_get_text(nm_term_list, row, 0);
    if (text && *text) {
        CDc *cdesc;
        CDp_node *pn;
        int vecix;
        if (DSP()->FindTerminal(text, &cdesc, &vecix, &pn))
            DSP()->ShowTerminal(cdesc, vecix, pn);
    }
    delete [] text;
}


void
QTnodeMapDlg::font_changed_slot(int fnum)
{
    if (fnum == FNT_PROP) {
        QFont *fnt;
        if (FC.getFont(&fnt, fnum)) {
            nm_node_list->setFont(*fnt);
            nm_term_list->setFont(*fnt);
        }
        update(0);
    }
}


#ifdef notdef

// Static function.
int
QTnodeMapDlg::nm_select_nlist_proc(GtkTreeSelection*, GtkTreeModel*,
    GtkTreePath *path, int issel, void*)
{
    if (NM) {
        if (issel) {
            NM->nm_showing_row = -1;
            gtk_widget_set_sensitive(NM->nm_rename, false);
            gtk_widget_set_sensitive(NM->nm_remove, false);
            if (NM->nm_rm_affirm)
                NM->nm_rm_affirm->popdown();
            if (NM->nm_join_affirm)
                NM->nm_join_affirm->popdown();
            if (NM->wb_input)
                NM->wb_input->popdown();
            return (true);
        }
        if (NM->nm_n_no_select) {
            // Don't let a focus event select anything!
            NM->nm_n_no_select = false;
            return (false);
        }

        // See note in tlist_proc.
        if (NM->nm_showing_row >= 0)
            return (true);

        int *indices = gtk_tree_path_get_indices(path);
        if (!indices)
            return (false);
        NM->nm_showing_row = *indices;
        int node = nm_node_of_row(*indices);
        if (node < 0)
            return (true);

        // Lock out the call back to QTnodeMapDlg::update, select the node in
        // physical if command is active.
        NM->nm_noupdating = true;
        ExtIf()->selectShowNode(node);
        NM->nm_noupdating = false;

        NM->show_node_terms(node);
        if (DSP()->CurMode() == Electrical) {

            char *text = list_get_text(NM->nm_node_list, NM->nm_showing_row, 2);
            if (text && (text[0] == 'Y' || text[0] == 'Y')) {
                // Y, with or without G.  If G, the global name must
                // have been assigned, so editing is allowed.

                gtk_widget_set_sensitive(NM->nm_rename, true);
                gtk_widget_set_sensitive(NM->nm_remove, true);
            }
            else if (text && text[0] == 'G') {
                gtk_widget_set_sensitive(NM->nm_rename, false);
                gtk_widget_set_sensitive(NM->nm_remove, false);
            }
            else
                gtk_widget_set_sensitive(NM->nm_rename, true);
            delete [] text;
        }
        return (true);
    }
    return (true);
}


// Static function.
// This handler is a hack to avoid a GtkTreeWidget defect:  when focus
// is taken and there are no selections, the 0'th row will be
// selected.  There seems to be no way to avoid this other than a hack
// like this one.  We set a flag to lock out selection changes in this
// case.
//
bool
QTnodeMapDlg::nm_n_focus_proc(GtkWidget*, GdkEvent*, void*)
{
    if (NM) {
        GtkTreeSelection *sel =
            gtk_tree_view_get_selection(GTK_TREE_VIEW(NM->nm_node_list));
        // If nothing selected set the flag.
        if (!gtk_tree_selection_get_selected(sel, 0, 0))
            NM->nm_n_no_select = true;
    }
    return (false);
}
        

// Static function.
int
QTnodeMapDlg::nm_select_tlist_proc(GtkTreeSelection*, GtkTreeModel *store,
    GtkTreePath *path, int issel, void*)
{
    if (NM) {
        // The calling sequence from selections in the GtkTreeView is
        // a little screwy.  Suppose that you initially select row 1. 
        // That event will call this function once with issel false as
        // expected.  Then click row 2 and find that this function is
        // called three times:  isset=false.  row=2.  isset=true,
        // row=1, isset=false, row=2.
        //
        // int *ii = gtk_tree_path_get_indices(path);
        // printf("tlist %d %d\n", issel, *ii);

        if (issel) {
            NM->nm_showing_term_row = -1;
            gtk_widget_set_sensitive(NM->nm_find_btn, false);
            if (NM->nm_node) {
                DSP()->HliteElecTerm(ERASE, NM->nm_node, NM->nm_cdesc, 0);
                CDterm *t;
                if (NM->nm_cdesc)
                    t = ((CDp_cnode*)NM->nm_node)->inst_terminal();
                else
                    t = ((CDp_snode*)NM->nm_node)->cell_terminal();
                DSP()->HlitePhysTerm(ERASE, t);
                NM->nm_node = 0;
            }
            NM->nm_cdesc = 0;
            return (true);
        }
        if (NM->nm_t_no_select) {
            // Don't let a focus event select anything!
            NM->nm_t_no_select = false;
            return (false);
        }

        // Here's the fix for above: ignore the first call.
        if (NM->nm_showing_term_row >= 0)
            return (true);

        int *indices = gtk_tree_path_get_indices(path);
        if (!indices)
            return (false);
        NM->nm_showing_term_row = *indices;
        GtkTreeIter iter;
        if (!gtk_tree_model_get_iter(store, &iter, path))
            return (true);
        char *text;
        gtk_tree_model_get(store, &iter, 0, &text, -1);
        if (text) {
            bool torw = ((text[0] == 'T' || text[0] == 'W') && text[1] == ' ');
            // True for wire or terminal device indicators, which mean
            // nothing to the find terminal function.
            gtk_widget_set_sensitive(NM->nm_find_btn, !torw);

            if (DSP()->CurMode() == Physical) {
                CDs *psd = CurCell(Physical);
                if (psd) {
                    if (!ExtIf()->associate(psd)) {
                        Log()->ErrorLogV(mh::Processing,
                            "Association failed!\n%s", Errs()->get_error());
                    }
                }
            }
            if (!torw) {
                CDc *cdesc;
                CDp_node *pn;
                int vecix;  // unused
                if (DSP()->FindTerminal(text, &cdesc, &vecix, &pn)) {
                    DSP()->HliteElecTerm(DISPLAY, pn, cdesc, -1);
                    CDterm *t;
                    if (cdesc)
                        t = ((CDp_cnode*)pn)->inst_terminal();
                    else
                        t = ((CDp_snode*)pn)->cell_terminal();
                    DSP()->HlitePhysTerm(DISPLAY, t);
                    NM->nm_node = pn;
                    NM->nm_cdesc = cdesc;
                }
            }
            free(text);
        }
        return (true);
    }
    return (false);
}


// Static function.
// Focus handler.
//
bool
QTnodeMapDlg::nm_t_focus_proc(GtkWidget*, GdkEvent*, void*)
{
    if (NM) {
        GtkTreeSelection *sel =
            gtk_tree_view_get_selection(GTK_TREE_VIEW(NM->nm_term_list));
        // If nothing selected set the flag.
        if (!gtk_tree_selection_get_selected(sel, 0, 0))
            NM->nm_t_no_select = true;
    }
    return (false);
}
        


// Static function.
// Handler for the rename button.
//
void
QTnodeMapDlg::nm_rename_proc(GtkWidget *caller, void*)
{
}


// Static function.
// Handler for pressing Enter in the text entry, will press the search
// button.
//
void
QTnodeMapDlg::nm_activate_proc(GtkWidget*, void*)
{
    if (!NM)
        return;
    GTKdev::CallCallback(NM->nm_srch_btn);
}

// End of QTnodeMapDlg functions.

#endif

NmpState::~NmpState()
{
    if (QTnodeMapDlg::self())
        QTnodeMapDlg::self()->clear_cmd();
}


void
NmpState::b1up()
{
    if (ExtIf()->hasExtract()) {
        int node = -1;
        if (DSP()->CurMode() == Electrical)
            node = ExtIf()->netSelB1Up();
        else {
            int grp = ExtIf()->netSelB1Up();
            node = ExtIf()->nodeOfGroup(CurCell(Physical), grp);
        }
        if (node >= 0) {
            QTnodeMapDlg::self()->show_node_terms(node);
            QTnodeMapDlg::self()->update_map();
        }
    }
    else if (DSP()->CurMode() == Electrical) {
        BBox AOI;
        CDol *sels;
        if (!cEventHdlr::sel_b1up(&AOI, 0, &sels))
            return;

        WindowDesc *wdesc = EV()->ButtonWin();
        if (!wdesc)
            wdesc = DSP()->MainWdesc();
        if (!wdesc->IsSimilar(Electrical, DSP()->MainWdesc()))
            return;
        int delta = 1 + (int)(DSP()->PixelDelta()/wdesc->Ratio());
        PSELmode ptsel = PSELpoint;
        if (AOI.width() < delta && AOI.height() < delta) {
            ptsel = PSELstrict_area;
            AOI.bloat(delta);
        }

        // check wires
        for (CDol *sl = sels; sl; sl = sl->next) {
            if (sl->odesc->type() != CDWIRE)
                continue;
            CDw *wrdesc = (CDw*)sl->odesc;
            if (!cSelections::processSelect(wrdesc, &AOI, ptsel, ASELnormal,
                    delta))
                continue;
            CDp_node *pn = (CDp_node*)wrdesc->prpty(P_NODE);
            if (pn) {
                QTnodeMapDlg::self()->show_node_terms(pn->enode());
                QTnodeMapDlg::self()->update_map();
                CDol::destroy(sels);
                return;
            }
        }
        CDol::destroy(sels);

        // Check subcells, can't use sels bacause only one subcell is
        // returned.
        CDs *cursde = CurCell(Electrical, true);
        if (cursde) {
            CDg gdesc;
            gdesc.init_gen(cursde, CellLayer(), &AOI);
            CDc *cdesc;
            while ((cdesc = (CDc*)gdesc.next()) != 0) {
                CDp_cnode *pn = (CDp_cnode*)cdesc->prpty(P_NODE);
                for ( ; pn; pn = pn->next()) {
                    for (unsigned int ix = 0; ; ix++) {
                        int x, y;
                        if (!pn->get_pos(ix, &x, &y))
                            break;
                        if (AOI.intersect(x, y, true)) {
                            QTnodeMapDlg::self()->show_node_terms(pn->enode());
                            QTnodeMapDlg::self()->update_map();
                            return;
                        }
                    }
                }
            }
        }
    }
}


// This allows a user to select nodes from the layout, if extraction
// has been run.  There is no visual group selection indication. 
// Better to set the Use Extraction check box and use the net
// selection panel from the extraction system.
//
void
NmpState::b1up_altw()
{
    if (EV()->CurrentWin()->CurCellName() != DSP()->MainWdesc()->CurCellName())
        return;
    if (ExtIf()->hasExtract()) {
        int node;
        if (DSP()->CurMode() == Electrical) {
            int grp = ExtIf()->netSelB1Up_altw();
            node = ExtIf()->nodeOfGroup(CurCell(Physical), grp);
        }
        else
            node = ExtIf()->netSelB1Up_altw();
        if (node > 0) {
            QTnodeMapDlg::self()->show_node_terms(node);
            QTnodeMapDlg::self()->update_map();
        }
    }
}


void
NmpState::esc()
{
    if (QTnodeMapDlg::self())
        QTnodeMapDlg::self()->desel_point_btn();
    EV()->PopCallback(this);
    delete this;
}

