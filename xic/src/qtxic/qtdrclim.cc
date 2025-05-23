
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

#include "qtdrclim.h"
#include "drc.h"
#include "dsp_inlines.h"
#include "qtllist.h"

#include <QApplication>
#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>
#include <QCheckBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QRadioButton>


//-----------------------------------------------------------------------------
// QTdrcSetupDlg:  DRC Setup dialog, provides entry fields for the
// various limit parameters and the error recording level.
// Called from main menu: DRC/DRC Setup.
//
// Help system keywords used:
//  xic:limit

void
cDRC::PopUpDrcLimits(GRobject caller, ShowMode mode)
{
    if (!QTdev::exists() || !QTmainwin::exists())
        return;
    if (mode == MODE_OFF) {
        delete QTdrcSetupDlg::self();
        return;
    }
    if (mode == MODE_UPD) {
        if (QTdrcSetupDlg::self())
            QTdrcSetupDlg::self()->update();
        return;
    }
    if (QTdrcSetupDlg::self())
        return;

    new QTdrcSetupDlg(caller);

    QTdrcSetupDlg::self()->set_transient_for(QTmainwin::self());
    QTdev::self()->SetPopupLocation(GRloc(LW_UR), QTdrcSetupDlg::self(),
        QTmainwin::self()->Viewport());
    QTdrcSetupDlg::self()->show();
}
// End of cDRC functions.


QTdrcSetupDlg *QTdrcSetupDlg::instPtr;

QTdrcSetupDlg::QTdrcSetupDlg(GRobject c)
{
    instPtr = this;
    dl_caller = c;
    dl_luse = 0;
    dl_lskip = 0;
    dl_llist = 0;
    dl_ruse = 0;
    dl_rskip = 0;
    dl_rlist = 0;
    dl_skip = 0;
    dl_b1 = 0;
    dl_b2 = 0;
    dl_b3 = 0;
    dl_sb_max_errs = 0;
    dl_sb_imax_objs = 0;
    dl_sb_imax_time = 0;
    dl_sb_imax_errs = 0;

    setWindowTitle(tr("DRC Parameter Setup"));
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

    // label in frame plus help btn
    //
    QGroupBox *gb = new QGroupBox();
    hbox->addWidget(gb);
    QHBoxLayout *hb = new QHBoxLayout(gb);
    hb->setContentsMargins(qm);
    hb->setSpacing(2);
    QLabel *label = new QLabel(tr("Set DRC parameters and limits"));
    hb->addWidget(label);

    QToolButton *tbtn = new QToolButton();
    tbtn->setText(tr("Help"));
    hbox->addWidget(tbtn);
    connect(tbtn, &QAbstractButton::clicked,
        this, &QTdrcSetupDlg::help_btn_slot);

    // Layer list.
    //
    QGridLayout *grid = new QGridLayout();
    vbox->addLayout(grid);

    label = new QLabel(tr("Layer list"));
    grid->addWidget(label, 0, 0);

#if QT_VERSION >= QT_VERSION_CHECK(6,8,0)
#define CHECK_BOX_STATE_CHANGED &QCheckBox::checkStateChanged
#else
#define CHECK_BOX_STATE_CHANGED &QCheckBox::stateChanged
#endif

    dl_luse = new QCheckBox(tr("Check listed layers only  "));
    grid->addWidget(dl_luse, 0, 1);
    connect(dl_luse, CHECK_BOX_STATE_CHANGED,
        this, &QTdrcSetupDlg::luse_btn_slot);

    dl_lskip = new QCheckBox(tr("Skip listed layers"));
    grid->addWidget(dl_lskip, 0, 2);
    connect(dl_lskip, CHECK_BOX_STATE_CHANGED,
        this, &QTdrcSetupDlg::lskip_btn_slot);

    dl_llist = new QTlayerEdit();
    grid->addWidget(dl_llist, 1, 0, 1, 3);

    // Rule list.
    //
    label = new QLabel(tr("Rule list"));
    grid->addWidget(label, 2, 0);

    dl_ruse = new QCheckBox(tr("Check listed rules only"));
    grid->addWidget(dl_ruse, 2, 1);
    connect(dl_ruse, CHECK_BOX_STATE_CHANGED,
        this, &QTdrcSetupDlg::ruse_btn_slot);
    dl_rskip = new QCheckBox(tr("Skip listed rules"));;
    grid->addWidget(dl_rskip, 2, 2);
    connect(dl_rskip, CHECK_BOX_STATE_CHANGED,
        this, &QTdrcSetupDlg::rskip_btn_slot);

    dl_rlist = new QLineEdit();
    grid->addWidget(dl_rlist, 3, 0, 1, 3);

    // Limits group.
    //
    gb = new QGroupBox(tr("DRC limit values, set to 0 for no limit"));
    vbox->addWidget(gb);
    grid = new QGridLayout(gb);

    // Batch Mode error limit.
    //
    label = new QLabel(tr("Batch mode error count limit"));
    grid->addWidget(label, 0, 0);

    dl_sb_max_errs = new QSpinBox();
    grid->addWidget(dl_sb_max_errs, 0, 1);
    dl_sb_max_errs->setMinimum(DRC_MAX_ERRS_MIN);
    dl_sb_max_errs->setMaximum(DRC_MAX_ERRS_MAX);
    dl_sb_max_errs->setValue(DRC()->maxErrors());
    connect(dl_sb_max_errs, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTdrcSetupDlg::max_errs_changed_slot);

    // Interactive Mode object limit.
    //
    label = new QLabel(tr("Interactive checking object count limit"));
    grid->addWidget(label, 1, 0);

    dl_sb_imax_objs = new QSpinBox();
    grid->addWidget(dl_sb_imax_objs, 1, 1);
    dl_sb_imax_objs->setMinimum(DRC_INTR_MAX_OBJS_MIN);
    dl_sb_imax_objs->setMaximum(DRC_INTR_MAX_OBJS_MAX);
    dl_sb_imax_objs->setValue(DRC()->intrMaxObjs());
    connect(dl_sb_imax_objs, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTdrcSetupDlg::imax_objs_changed_slot);

    // Interactive Mode time limit.
    //
    label = new QLabel(tr("Interactive check time limit (milliseconds)"));
    grid->addWidget(label, 2, 0);

    dl_sb_imax_time = new QSpinBox();
    grid->addWidget(dl_sb_imax_time, 2, 1);
    dl_sb_imax_time->setMinimum(DRC_INTR_MAX_TIME_MIN);
    dl_sb_imax_time->setMaximum(DRC_INTR_MAX_TIME_MAX);
    dl_sb_imax_time->setValue(DRC()->intrMaxTime());
    connect(dl_sb_imax_time, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTdrcSetupDlg::imax_time_changed_slot);

    // Interactive Mode error limit.
    //
    label = new QLabel(tr("Interactive mode error count limit"));
    grid->addWidget(label, 3, 0);

    dl_sb_imax_errs = new QSpinBox();
    grid->addWidget(dl_sb_imax_errs, 3, 1);
    dl_sb_imax_errs->setMinimum(DRC_INTR_MAX_ERRS_MIN);
    dl_sb_imax_errs->setMaximum(DRC_INTR_MAX_ERRS_MAX);
    dl_sb_imax_errs->setValue(DRC()->intrMaxErrors());
    connect(dl_sb_imax_errs, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTdrcSetupDlg::imax_errs_changed_slot);

    // Skip cells check box
    //
    dl_skip = new QCheckBox(tr(
        "Skip interactive test of moved/copied/placed cells"));
    grid->addWidget(dl_skip, 4, 0, 1, 2);
    connect(dl_skip, CHECK_BOX_STATE_CHANGED,
        this, &QTdrcSetupDlg::skip_btn_slot);

    // DRC error level
    //
    gb = new QGroupBox(tr("DRC error recording"));
    vbox->addWidget(gb);
    QVBoxLayout *vb = new QVBoxLayout(gb);

    dl_b1 = new QRadioButton(tr("One error per object"));
    vb->addWidget(dl_b1);
    connect(dl_b1, &QRadioButton::toggled,
        this, &QTdrcSetupDlg::b1_btn_slot);

    dl_b2 = new QRadioButton(tr("One error of each type per object"));
    vb->addWidget(dl_b2);
    connect(dl_b2, &QRadioButton::toggled,
        this, &QTdrcSetupDlg::b2_btn_slot);

    dl_b3 = new QRadioButton(tr("Record all errors"));
    vb->addWidget(dl_b3);
    connect(dl_b3, &QRadioButton::toggled,
        this, &QTdrcSetupDlg::b3_btn_slot);

    // Dismiss button
    //
    QPushButton *btn = new QPushButton(tr("Dismiss"));
    btn->setObjectName("Default");
    vbox->addWidget(btn);
    connect(btn, &QAbstractButton::clicked,
        this, &QTdrcSetupDlg::dismiss_btn_slot);

    update();

    // must be done after entry text set
    connect(dl_llist, &QTlayerEdit::textChanged,
        this, &QTdrcSetupDlg::llist_changed_slot);
    connect(dl_rlist, &QLineEdit::textChanged,
        this, &QTdrcSetupDlg::rlist_changed_slot);
}


QTdrcSetupDlg::~QTdrcSetupDlg()
{
    instPtr = 0;
    if (dl_caller)
        QTdev::Deselect(dl_caller);
}


#ifdef Q_OS_MACOS
#define DLGTYPE QTdrcSetupDlg
#include "qtinterf/qtmacos_event.h"
#endif


void
QTdrcSetupDlg::update()
{
    const char *s = CDvdb()->getVariable(VA_DrcUseLayerList);
    if (s) {
        if (*s == 'n' || *s == 'N') {
            QTdev::SetStatus(dl_lskip, true);
            QTdev::SetStatus(dl_luse, false);
        }
        else {
            QTdev::SetStatus(dl_lskip, false);
            QTdev::SetStatus(dl_luse, true);
        }
    }
    else {
        QTdev::SetStatus(dl_lskip, false);
        QTdev::SetStatus(dl_luse, false);
    }

    s = CDvdb()->getVariable(VA_DrcLayerList);
    if (!s)
        s = "";
    const char *l = lstring::copy(dl_llist->text().toLatin1().constData());
    if (!l)
        l = lstring::copy("");
    if (strcmp(s, l))
        dl_llist->setText(s);
    if (QTdev::GetStatus(dl_luse) || QTdev::GetStatus(dl_lskip))
        dl_llist->setEnabled(true);
    else
        dl_llist->setEnabled(false);
    delete [] l;

    s = CDvdb()->getVariable(VA_DrcUseRuleList);
    if (s) {
        if (*s == 'n' || *s == 'N') {
            QTdev::SetStatus(dl_rskip, true);
            QTdev::SetStatus(dl_ruse, false);
        }
        else {
            QTdev::SetStatus(dl_rskip, false);
            QTdev::SetStatus(dl_ruse, true);
        }
    }
    else {
        QTdev::SetStatus(dl_rskip, false);
        QTdev::SetStatus(dl_ruse, false);
    }

    s = CDvdb()->getVariable(VA_DrcRuleList);
    if (!s)
        s = "";
    l = lstring::copy(dl_rlist->text().toLatin1().constData());
    if (!l)
        l = lstring::copy("");
    if (strcmp(s, l))
        dl_rlist->setText(s);
    if (QTdev::GetStatus(dl_ruse) || QTdev::GetStatus(dl_rskip))
        dl_rlist->setEnabled(true);
    else
        dl_rlist->setEnabled(false);

    if (DRC()->maxErrors() > DRC_MAX_ERRS_MAX)
        DRC()->setMaxErrors(DRC_MAX_ERRS_MAX);
    dl_sb_max_errs->setValue(DRC()->maxErrors());
    if (DRC()->intrMaxObjs() > DRC_INTR_MAX_OBJS_MAX)
        DRC()->setIntrMaxObjs(DRC_INTR_MAX_OBJS_MAX);
    dl_sb_imax_objs->setValue(DRC()->intrMaxObjs());
    if (DRC()->intrMaxTime() > DRC_INTR_MAX_TIME_MAX)
        DRC()->setIntrMaxTime(DRC_INTR_MAX_TIME_MAX);
    dl_sb_imax_time->setValue(DRC()->intrMaxTime());
    if (DRC()->intrMaxErrors() > DRC_INTR_MAX_ERRS_MAX)
        DRC()->setIntrMaxErrors(DRC_INTR_MAX_ERRS_MAX);
    dl_sb_imax_errs->setValue(DRC()->intrMaxErrors());
    QTdev::SetStatus(dl_skip, DRC()->isIntrSkipInst());
    if (DRC()->errorLevel() == DRCone_err) {
        QTdev::SetStatus(dl_b1, true);
        QTdev::SetStatus(dl_b2, false);
        QTdev::SetStatus(dl_b3, false);
    }
    else if (DRC()->errorLevel() == DRCone_type) {
        QTdev::SetStatus(dl_b1, false);
        QTdev::SetStatus(dl_b2, true);
        QTdev::SetStatus(dl_b3, false);
    }
    else {
        QTdev::SetStatus(dl_b1, false);
        QTdev::SetStatus(dl_b2, false);
        QTdev::SetStatus(dl_b3, true);
    }
}


void
QTdrcSetupDlg::help_btn_slot()
{
    DSPmainWbag(PopUpHelp("xic:limit"))
}


void
QTdrcSetupDlg::luse_btn_slot(int state)
{
    if (state) {
        CDvdb()->setVariable(VA_DrcUseLayerList, 0);
        // Give the list entry the focus.
        dl_llist->setFocus();
    }
    else
        CDvdb()->clearVariable(VA_DrcUseLayerList);
}


void
QTdrcSetupDlg::lskip_btn_slot(int state)
{
    if (state) {
        CDvdb()->setVariable(VA_DrcUseLayerList, "n");
        // Give the list entry the focus.
        dl_llist->setFocus();
    }
    else
        CDvdb()->clearVariable(VA_DrcUseLayerList);
}


void
QTdrcSetupDlg::ruse_btn_slot(int state)
{
    if (state) {
        CDvdb()->setVariable(VA_DrcUseRuleList, 0);
        // Give the list entry the focus.
        dl_rlist->setFocus();
    }
    else
        CDvdb()->clearVariable(VA_DrcUseRuleList);
}


void
QTdrcSetupDlg::rskip_btn_slot(int state)
{
    if (state) {
        CDvdb()->setVariable(VA_DrcUseRuleList, "n");
        // Give the list entry the focus.
        dl_rlist->setFocus();
    }
    else
        CDvdb()->clearVariable(VA_DrcUseRuleList);
}


void
QTdrcSetupDlg::max_errs_changed_slot(int i)
{
    if (i == DRC_MAX_ERRS_DEF)
        CDvdb()->clearVariable(VA_DrcMaxErrors);
    else {
        QString st;
        CDvdb()->setVariable(VA_DrcMaxErrors,
            st.setNum(i).toLatin1().constData());
    }
}


void
QTdrcSetupDlg::imax_objs_changed_slot(int i)
{
    if (i == DRC_INTR_MAX_OBJS_DEF)
        CDvdb()->clearVariable(VA_DrcInterMaxObjs);
    else {
        QString st;
        CDvdb()->setVariable(VA_DrcInterMaxObjs,
            st.setNum(i).toLatin1().constData());
    }
}


void
QTdrcSetupDlg::imax_time_changed_slot(int i)
{
    if (i == DRC_INTR_MAX_TIME_DEF)
        CDvdb()->clearVariable(VA_DrcInterMaxTime);
    else {
        QString st;
        CDvdb()->setVariable(VA_DrcInterMaxTime,
            st.setNum(i).toLatin1().constData());
    }
}


void
QTdrcSetupDlg::imax_errs_changed_slot(int i)
{
    if (i == DRC_INTR_MAX_ERRS_DEF)
        CDvdb()->clearVariable(VA_DrcInterMaxErrors);
    else {
        QString st;
        CDvdb()->setVariable(VA_DrcInterMaxErrors,
            st.setNum(i).toLatin1().constData());
    }
}


void
QTdrcSetupDlg::skip_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_DrcInterSkipInst, "");
    else
        CDvdb()->clearVariable(VA_DrcInterSkipInst);
}


void
QTdrcSetupDlg::b1_btn_slot(bool state)
{
    if (state)
        CDvdb()->clearVariable(VA_DrcLevel);
}


void
QTdrcSetupDlg::b2_btn_slot(bool state)
{
    if (state)
        CDvdb()->setVariable(VA_DrcLevel, "1");
}


void
QTdrcSetupDlg::b3_btn_slot(bool state)
{
    if (state)
        CDvdb()->setVariable(VA_DrcLevel, "2");
}


void
QTdrcSetupDlg::dismiss_btn_slot()
{
    DRC()->PopUpDrcLimits(0, MODE_OFF);
}


void
QTdrcSetupDlg::llist_changed_slot(const QString &qs)
{
    const char *s = lstring::copy(qs.toLatin1().constData());
    const char *ss = CDvdb()->getVariable(VA_DrcLayerList);
    if (s && *s) {
        if (!ss || strcmp(ss, s))
            CDvdb()->setVariable(VA_DrcLayerList, s);
    }
    else
        CDvdb()->clearVariable(VA_DrcLayerList);
    delete [] s;
}


void
QTdrcSetupDlg::rlist_changed_slot(const QString &qs)
{
    const char *s = lstring::copy(qs.toLatin1().constData());
    const char *ss = CDvdb()->getVariable(VA_DrcRuleList);
    if (s && *s) {
        if (!ss || strcmp(ss, s))
            CDvdb()->setVariable(VA_DrcRuleList, s);
    }
    else
        CDvdb()->clearVariable(VA_DrcRuleList);
    delete [] s;
}

