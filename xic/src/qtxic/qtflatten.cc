
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

#include "qtflatten.h"
#include "edit.h"
#include "dsp_inlines.h"
#include "cvrt_variables.h"

#include <QApplication>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>
#include <QComboBox>
#include <QCheckBox>
#include <QAction>


//-----------------------------------------------------------------------------
// QTflattenDlg:  Dialog for the Flatten command.
// Called from main menu: Edit/Flatten.
//
// Help system keywords used:
//  xic:flatn

#define DMAX 6

// Pop-up for the Flatten command, consists of a depth option selector,
// fast-mode toggle, go and dismiss buttons.
//
void
cEdit::PopUpFlatten(GRobject caller, ShowMode mode,
    bool (*callback)(const char*, bool, const char*, void*),
    void *arg, int depth, bool fmode, bool merge)
{
    if (!QTdev::exists() || !QTmainwin::exists())
        return;
    if (mode == MODE_OFF) {
        delete QTflattenDlg::self();
        return;
    }
    if (mode == MODE_UPD) {
        if (QTflattenDlg::self())
            QTflattenDlg::self()->update();
        return;
    }
    if (QTflattenDlg::self())
        return;

    new QTflattenDlg(caller, callback, arg, depth, fmode, merge);

    QTflattenDlg::self()->set_transient_for(QTmainwin::self());
    QTdev::self()->SetPopupLocation(GRloc(), QTflattenDlg::self(),
        QTmainwin::self()->Viewport());
    QTflattenDlg::self()->show();
}
// End of cEdit functions.


QTflattenDlg *QTflattenDlg::instPtr;

QTflattenDlg::QTflattenDlg(
    GRobject c, bool(*callback)(const char*, bool, const char*, void*),
    void *arg, int dep, bool fmode, bool merge)
{
    instPtr = this;
    fl_caller = c;
    fl_novias = 0;
    fl_nopcells = 0;
    fl_nolabels = 0;
    fl_merge = 0;
    fl_go = 0;
    fl_callback = callback;
    fl_arg = arg;

    setWindowTitle(tr("Flatten Hierarchy"));
    setAttribute(Qt::WA_DeleteOnClose);

    QMargins qmtop(2, 2, 2, 2);
    QMargins qm;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(qmtop);
    vbox->setSpacing(2);
    vbox->setSizeConstraint(QLayout::SetFixedSize);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    // label in frame plus help btn
    //
    QGroupBox *gb = new QGroupBox();
    hbox->addWidget(gb);
    QHBoxLayout *hb = new QHBoxLayout(gb);
    hb->setContentsMargins(qm);
    hb->setSpacing(2);
    QLabel *label = new QLabel(tr("Selected subcells will be flattened"));
    hb->addWidget(label);

    QToolButton *tbtn = new QToolButton();
    tbtn->setText(tr("Help"));
    hbox->addWidget(tbtn);
    connect(tbtn, &QAbstractButton::clicked,
        this, &QTflattenDlg::help_btn_slot);

    // depth option
    //
    hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    label = new QLabel(tr("Depth to flatten"));
    hbox->addWidget(label);

    QComboBox *entry = new QComboBox();
    hbox->addWidget(entry);

    if (dep < 0)
        dep = 0;
    if (dep > DMAX)
        dep = DMAX;
    for (int i = 0; i <= DMAX; i++) {
        char buf[16];
        if (i == DMAX)
            strcpy(buf, "all");
        else
            snprintf(buf, sizeof(buf), "%d", i);
        entry->addItem(buf);
    }
    entry->setCurrentIndex(dep);
    connect(entry, &QComboBox::currentTextChanged,
        this, &QTflattenDlg::depth_menu_slot);

#if QT_VERSION >= QT_VERSION_CHECK(6,8,0)
#define CHECK_BOX_STATE_CHANGED &QCheckBox::checkStateChanged
#else
#define CHECK_BOX_STATE_CHANGED &QCheckBox::stateChanged
#endif

    // check boxes
    //
    fl_novias = new QCheckBox(tr(
        "Don't flatten standard vias, move to top"));
    vbox->addWidget(fl_novias);
    connect(fl_novias, CHECK_BOX_STATE_CHANGED,
        this, &QTflattenDlg::novias_btn_slot);

    fl_nopcells = new QCheckBox(tr(
        "Don't flatten param. cells, move to top"));
    vbox->addWidget(fl_nopcells);
    connect(fl_nopcells, CHECK_BOX_STATE_CHANGED,
        this, &QTflattenDlg::nopcells_btn_slot);

    fl_nolabels = new QCheckBox(tr("Ignore labels in subcells"));
    vbox->addWidget(fl_nolabels);
    connect(fl_nolabels, CHECK_BOX_STATE_CHANGED,
        this, &QTflattenDlg::nolabels_btn_slot);

    QCheckBox *cbox = new QCheckBox(tr("Use fast mode, NOT UNDOABLE"));
    vbox->addWidget(cbox);
    QTdev::SetStatus(cbox, fmode);
    connect(cbox, CHECK_BOX_STATE_CHANGED,
        this, &QTflattenDlg::fastmode_btn_slot);

    fl_merge = new QCheckBox(tr("Use object merging when flattening"));
    vbox->addWidget(fl_merge);
    QTdev::SetStatus(fl_merge, merge);
    connect(fl_merge, CHECK_BOX_STATE_CHANGED,
        this, &QTflattenDlg::merge_btn_slot);

    // flatten and dismiss buttons
    //
    hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addSpacing(10);
    vbox->addLayout(hbox);

    fl_go = new QToolButton();
    fl_go->setText(tr("Flatten"));
    hbox->addWidget(fl_go);
    connect(fl_go, &QAbstractButton::clicked,
        this, &QTflattenDlg::go_btn_slot);

    QPushButton *btn = new QPushButton(tr("Dismiss"));
    btn->setObjectName("Default");
    hbox->addWidget(btn);
    connect(btn, &QAbstractButton::clicked,
        this, &QTflattenDlg::dismiss_btn_slot);

    update();
}


QTflattenDlg::~QTflattenDlg()
{
    instPtr = 0;
    if (fl_caller)
        QTdev::Deselect(fl_caller);
    if (fl_callback)
        (*fl_callback)(0, false, 0, fl_arg);
}


#ifdef Q_OS_MACOS
#define DLGTYPE QTflattenDlg
#include "qtinterf/qtmacos_event.h"
#endif


void
QTflattenDlg::update()
{
    QTdev::SetStatus(fl_novias,
        CDvdb()->getVariable(VA_NoFlattenStdVias));
    QTdev::SetStatus(fl_nopcells,
        CDvdb()->getVariable(VA_NoFlattenPCells));
    QTdev::SetStatus(fl_nolabels,
        CDvdb()->getVariable(VA_NoFlattenLabels));
}


void
QTflattenDlg::help_btn_slot()
{
    DSPmainWbag(PopUpHelp("xic:flatn"))
}


void
QTflattenDlg::depth_menu_slot(const QString &qs)
{
    if (fl_callback) {
        const char *str = lstring::copy(qs.toLatin1().constData());
        if (str) {
            (*fl_callback)("depth", true, str, fl_arg);
            delete [] str;
        }
    }
}


void
QTflattenDlg::novias_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_NoFlattenStdVias, "");
    else
        CDvdb()->clearVariable(VA_NoFlattenStdVias);
}


void
QTflattenDlg::nopcells_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_NoFlattenPCells, "");
    else
        CDvdb()->clearVariable(VA_NoFlattenPCells);
}


void
QTflattenDlg::nolabels_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_NoFlattenLabels, "");
    else
        CDvdb()->clearVariable(VA_NoFlattenLabels);
}


void
QTflattenDlg::fastmode_btn_slot(int state)
{
    if (fl_callback)
        (*fl_callback)("mode", state, 0, fl_arg);
}


void
QTflattenDlg::merge_btn_slot(int state)
{
    if (fl_callback)
        (*fl_callback)("merge", state, 0, fl_arg);
}


void
QTflattenDlg::go_btn_slot()
{
    if (fl_callback)
        (*fl_callback)("flatten", true, 0, fl_arg);
}


void
QTflattenDlg::dismiss_btn_slot()
{
    ED()->PopUpFlatten(0, MODE_OFF, 0, 0);
}

