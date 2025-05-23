
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

#include "qtattri.h"
#include "dsp_inlines.h"
#include "qtinterf/qtdblsb.h"

#include <QApplication>
#include <QLayout>
#include <QTabWidget>
#include <QGroupBox>
#include <QLabel>
#include <QToolButton>
#include <QPushButton>
#include <QCheckBox>
#include <QComboBox>
#include <QSpinBox>
#include <QBitmap>


//-----------------------------------------------------------------------------
// QTattributesDlg:  Dialog to control cursor modes and other window
// attributes.
// Called from main menu: Attributes/Set Attributes.
//
// Help system keywords used:
//  xic:attr

namespace {
    const char *const hdn_menu[] = {
        "all labels",
        "all electrical labels",
        "electrical property labels",
        "no labels",
        0
    };

    const char *const cursvals[] = {
        "default",
        "cross",
        "left arrow",
        "right arrow",
        0
    };

    // Cursors.
    // b=1 m=1 black
    // b=0 m=1 white
    // b=0 m=0 transparent
    // b=1 m=1 undefined

    // Legacy small cross-hair cursor.
#define cursor_cross_width 16
#define cursor_cross_height 16
#define cursor_cross_x_hot 8
#define cursor_cross_y_hot 7
    unsigned char cursor_cross_bits[] = {
        0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
        0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x7e, 0xfc,
        0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x01,
        0x00, 0x01, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00 };
    unsigned char cursor_cross_mask[] = {
        0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03,
        0x80, 0x03, 0x80, 0x03, 0x7e, 0xfc, 0x7e, 0xfc,
        0x7e, 0xfc, 0x80, 0x03, 0x80, 0x03, 0x80, 0x03,
        0x80, 0x03, 0x80, 0x03, 0x80, 0x03, 0x00, 0x00 };

    // Right arrow, QT seems not to have one as stock.
#define cursor_right_width 10
#define cursor_right_height 16
#define cursor_right_x_hot 7
#define cursor_right_y_hot 0
    unsigned char cursor_right_bits[] = {
        0x00, 0x01, 0x00, 0x01, 0x80, 0x01, 0xc0, 0x01,
        0xe0, 0x01, 0xf0, 0x01, 0xf8, 0x01, 0xfc, 0x01,
        0xfe, 0x01, 0xf0, 0x01, 0xb0, 0x01, 0x18, 0x00,
        0x18, 0x00, 0x0c, 0x00, 0x0c, 0x00, 0x00, 0x00};
    unsigned char cursor_right_mask[] = {
        0x00, 0x03, 0x80, 0x03, 0xc0, 0x03, 0xe0, 0x03,
        0xf0, 0x03, 0xf8, 0x03, 0xfc, 0x03, 0xfe, 0x03,
        0xff, 0x03, 0xff, 0x03, 0xf8, 0x03, 0xbc, 0x03,
        0x3c, 0x00, 0x1e, 0x00, 0x1e, 0x00, 0x0c, 0x00};
}


// Return the cursur type currently in force.
//
CursorType
cMain::GetCursor()
{
    if (!QTmainwin::self())
        return (CursorDefault);
    return ((CursorType)QTmainwin::self()->cursor_type());
}


// Change or update the cursor for wd, or all drawing windows if wd is
// null.  This should be called after a window mode change, since the
// cross cursor will need to be changed if the background color
// changes.
//
// Call with force true for new windows.
//
void
cMain::UpdateCursor(WindowDesc *wd, CursorType t, bool force)
{
    if (!force && t == (CursorType)QTmainwin::self()->cursor_type() &&
            t != CursorCross)
        return;
    if (!wd && QTmainwin::self())
        QTmainwin::self()->set_cursor_type(t);

    // The cross cursor makes things complicated, as it requires
    // background and foreground colors per window, i.e., each window
    // is given a separate instantiation of the cursor.

    if (t == CursorDefault) {
        // QT default cursor.
        if (wd) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(Qt::ArrowCursor);
            return;
        }
        WDgen wgen(WDgen::MAIN, WDgen::ALL);
        while ((wd = wgen.next()) != 0) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(Qt::ArrowCursor);
        }
    }
    else if (t == CursorCross) {
        // Legacy cross cursor.
        QBitmap bits_bm =
            QBitmap::fromData(QSize(cursor_cross_width, cursor_cross_height),
            cursor_cross_bits, QImage::Format_MonoLSB);
        QBitmap bits_mask =
            QBitmap::fromData(QSize(cursor_cross_width, cursor_cross_height),
            cursor_cross_mask, QImage::Format_MonoLSB);
        QCursor cross_cursor(bits_bm, bits_mask,
            cursor_cross_x_hot, cursor_cross_y_hot);
        if (wd) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(cross_cursor);
            return;
        }
        WDgen wgen(WDgen::MAIN, WDgen::ALL);
        while ((wd = wgen.next()) != 0) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(cross_cursor);
        }
    }
    else if (t == CursorLeftArrow) {
        // Stock left pointer cursor.
        if (wd) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(Qt::ArrowCursor);
            return;
        }
        WDgen wgen(WDgen::MAIN, WDgen::ALL);
        while ((wd = wgen.next()) != 0) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(Qt::ArrowCursor);
        }
    }
    else if (t == CursorRightArrow) {
        QBitmap bits_bm =
            QBitmap::fromData(QSize(cursor_right_width, cursor_right_height),
            cursor_right_bits, QImage::Format_MonoLSB);
        QBitmap bits_mask =
            QBitmap::fromData(QSize(cursor_right_width, cursor_right_height),
            cursor_right_mask, QImage::Format_MonoLSB);
        QCursor right_cursor(bits_bm, bits_mask,
            cursor_right_x_hot, cursor_right_y_hot);
        if (wd) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(right_cursor);
            return;
        }
        WDgen wgen(WDgen::MAIN, WDgen::ALL);
        while ((wd = wgen.next()) != 0) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(right_cursor);
        }
    }
    else if (t == CursorBusy) {
        // Stock watch (busy) cursor.
        if (wd) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(Qt::WaitCursor);
            return;
        }
        WDgen wgen(WDgen::MAIN, WDgen::ALL);
        while ((wd = wgen.next()) != 0) {
            QTsubwin *w = dynamic_cast<QTsubwin*>(wd->Wbag());
            w->Viewport()->setCursor(Qt::WaitCursor);
        }
    }
}


void
cMain::PopUpAttributes(GRobject caller, ShowMode mode)
{
    if (!QTdev::exists() || !QTmainwin::exists())
        return;
    if (mode == MODE_OFF) {
        delete QTattributesDlg::self();
        return;
    }
    if (mode == MODE_UPD) {
        if (QTattributesDlg::self())
            QTattributesDlg::self()->update();
        return;
    }
    if (QTattributesDlg::self())
        return;

    new QTattributesDlg(caller);

    QTattributesDlg::self()->set_transient_for(QTmainwin::self());
    QTdev::self()->SetPopupLocation(GRloc(), QTattributesDlg::self(),
        QTmainwin::self()->Viewport());
    QTattributesDlg::self()->show();
}
// End of cMain funcrtions.


QTattributesDlg *QTattributesDlg::instPtr;

QTattributesDlg::QTattributesDlg(GRobject c)
{
    instPtr = this;
    at_caller = c;
    at_cursor = 0;
    at_fullscr = 0;
    at_sb_visthr = 0;
    at_sb_cxpct = 0;
    at_sb_offset = 0;

    at_minst = 0;
    at_mcntr = 0;

    at_abprop = 0;
    at_sb_tsize = 0;

    at_ebterms = 0;
    at_sb_ttsize = 0;
    at_sb_tmsize = 0;

    at_hdn = 0;
    at_sb_lheight = 0;
    at_sb_llen = 0;
    at_sb_llines = 0;

    at_ebthst = 0;

    setWindowTitle(tr("Window Attributes"));
    setAttribute(Qt::WA_DeleteOnClose);

    QMargins qmtop(2, 2, 2, 2);
    QMargins qm;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(qmtop);
    vbox->setSpacing(2);

    // Fixed size window.
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
    QLabel *label = new QLabel(tr("Set misc. window attributes"));
    hb->addWidget(label);

    QToolButton *tbtn = new QToolButton();
    tbtn->setText(tr("Help"));
    hbox->addWidget(tbtn);
    connect(tbtn, &QAbstractButton::clicked,
        this, &QTattributesDlg::help_btn_slot);

    QTabWidget *nbook = new QTabWidget();
    vbox->addWidget(nbook);

    // General page
    //
    QWidget *page = new QWidget();
    nbook->addTab(page, tr("General"));
    QVBoxLayout *vb = new QVBoxLayout(page);
    vb->setContentsMargins(qmtop);
    vb->setSpacing(2);

    hb = new QHBoxLayout();
    vb->addLayout(hb);
    hb->setContentsMargins(qm);
    hb->setSpacing(2);

    label = new QLabel(tr("Cursor:"));
    hb->addWidget(label);

    // Weirdness:  When any input widget (including the spin buttons
    // below) have the focus, the cursor reverts back to the QT
    // default (QT6 on macOS).

    at_cursor = new QComboBox();
    hb->addWidget(at_cursor);
    for (int i = 0; cursvals[i]; i++)
        at_cursor->addItem(cursvals[i]);
    at_cursor->setCurrentIndex(XM()->GetCursor());
    connect(at_cursor, QOverload<int>::of(&QComboBox::currentIndexChanged),
        this, &QTattributesDlg::cursor_menu_changed_slot);

#if QT_VERSION >= QT_VERSION_CHECK(6,8,0)
#define CHECK_BOX_STATE_CHANGED &QCheckBox::checkStateChanged
#else
#define CHECK_BOX_STATE_CHANGED &QCheckBox::stateChanged
#endif

    at_fullscr = new QCheckBox(tr("Use full-window cursor"));
    hb->addWidget(at_fullscr);
    connect(at_fullscr, CHECK_BOX_STATE_CHANGED,
        this, &QTattributesDlg::usefwc_btn_slot);

    QGridLayout *grid = new QGridLayout();
    vb->addLayout(grid);

    label = new QLabel(tr("Subcell visibility threshold (pixels)"));
    grid->addWidget(label, 0, 0);

    at_sb_visthr = new QSpinBox();
    grid->addWidget(at_sb_visthr, 0, 1);
    at_sb_visthr->setRange(DSP_MIN_CELL_THRESHOLD, DSP_MAX_CELL_THRESHOLD);
    at_sb_visthr->setValue(DSP_DEF_CELL_THRESHOLD);
    connect(at_sb_visthr, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::visthr_sb_slot);

    label = new QLabel(tr("Push context display illumination percent"));
    grid->addWidget(label, 1, 0);

    at_sb_cxpct = new QSpinBox();
    grid->addWidget(at_sb_cxpct, 1, 1);
    at_sb_cxpct->setRange(DSP_MIN_CX_DARK_PCNT, 100);
    at_sb_cxpct->setValue(DSP_DEF_CX_DARK_PCNT);
    connect(at_sb_cxpct, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::cxpct_sb_slot);

    label = new QLabel(tr("Pixels between pop-ups and prompt line"));
    grid->addWidget(label, 2, 0);

    at_sb_offset = new QSpinBox();
    grid->addWidget(at_sb_offset, 2, 1);
    at_sb_offset->setRange(-16, 16);
    at_sb_offset->setValue(0);
    connect(at_sb_offset, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::offset_sb_slot);

    // Selections page
    //
    page = new QWidget();
    nbook->addTab(page, tr("Selections"));
    vb = new QVBoxLayout(page);
    vb->setContentsMargins(qmtop);
    vb->setSpacing(2);

    at_minst = new QCheckBox(tr(
        "Show origin of selected physical instances"));
    vb->addWidget(at_minst);
    connect(at_minst, CHECK_BOX_STATE_CHANGED,
        this, &QTattributesDlg::markinst_btn_slot);

    at_mcntr = new QCheckBox(tr(
        "Show centroids of selected physical objects"));
    vb->addWidget(at_mcntr);
    connect(at_mcntr, CHECK_BOX_STATE_CHANGED,
        this, &QTattributesDlg::markcntr_btn_slot);

    // Phys Props page
    //
    page = new QWidget();
    nbook->addTab(page, tr("Phys Props"));
    grid = new QGridLayout(page);

    at_abprop = new QCheckBox(tr(
        "Erase behind physical properties text"));
    grid->addWidget(at_abprop, 0, 0);
    connect(at_abprop, CHECK_BOX_STATE_CHANGED,
        this, &QTattributesDlg::abprop_btn_slot);

    label = new QLabel(tr("Physical property text size (pixels)"));
    grid->addWidget(label, 1, 0);

    at_sb_tsize = new QSpinBox();
    grid->addWidget(at_sb_tsize, 1, 1);
    at_sb_tsize->setRange(DSP_MIN_PTRM_TXTHT, DSP_MAX_PTRM_TXTHT);
    at_sb_tsize->setValue(DSP_DEF_PTRM_TXTHT);
    connect(at_sb_tsize, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::tsize_sb_slot);

    // Terminals page
    //
    page = new QWidget();
    nbook->addTab(page, tr("Terminals"));
    grid = new QGridLayout(page);
    hb = new QHBoxLayout;
    grid->addLayout(hb, 0, 0, 1, 2);
    hb->setContentsMargins(qmtop);
    hb->setSpacing(2);

    label = new QLabel(tr("Erase behind physical terminals"));
    hb->addWidget(label);

    at_ebterms = new QComboBox();
    hb->addWidget(at_ebterms);

    at_ebterms->addItem("Don't erase");
    at_ebterms->addItem("Cell terminals only");
    at_ebterms->addItem("All terminals");
    at_ebterms->setCurrentIndex(at_ebthst);
    connect(at_ebterms, QOverload<int>::of(&QComboBox::currentIndexChanged),
        this, &QTattributesDlg::ebt_menu_changed_slot);

    label = new QLabel(tr("Terminal text pixel size"));
    grid->addWidget(label, 1, 0);

    at_sb_ttsize = new QSpinBox();
    grid->addWidget(at_sb_ttsize, 1, 1);
    at_sb_ttsize->setRange(DSP_MIN_PTRM_TXTHT, DSP_MAX_PTRM_TXTHT);
    at_sb_ttsize->setValue(DSP()->TermTextSize());
    connect(at_sb_ttsize, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::ttsize_sb_slot);

    label = new QLabel(tr("Terminal mark size"));
    grid->addWidget(label, 2, 0);

    at_sb_tmsize = new QSpinBox();
    grid->addWidget(at_sb_tmsize, 2, 1);
    at_sb_tmsize->setRange(DSP_MIN_PTRM_DELTA, DSP_MAX_PTRM_DELTA);
    at_sb_tmsize->setValue(DSP()->TermMarkSize());
    connect(at_sb_tmsize, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::tmsize_sb_slot);

    // Labels page
    //
    page = new QWidget();
    nbook->addTab(page, tr("Labels"));
    grid = new QGridLayout(page);
    hb = new QHBoxLayout();
    grid->addLayout(hb, 0, 0, 1, 2);
    hb->setContentsMargins(qmtop);
    hb->setSpacing(2);

    label = new QLabel(tr("Hidden label scope"));
    hb->addWidget(label);

    at_hdn = new QComboBox();
    hb->addWidget(at_hdn);
    for (int i = 0; hdn_menu[i]; i++)
        at_hdn->addItem(hdn_menu[i]);
    connect(at_hdn, QOverload<int>::of(&QComboBox::currentIndexChanged),
        this, &QTattributesDlg::hdn_menu_changed_slot);

    label = new QLabel(tr("Default minimum label height"));
    grid->addWidget(label, 1, 0);

    at_sb_lheight = new QTdoubleSpinBox();
    grid->addWidget(at_sb_lheight, 1, 1);
    at_sb_lheight->setRange(CD_MIN_TEXT_HEI, CD_MAX_TEXT_HEI);
    at_sb_lheight->setDecimals(2);
    at_sb_lheight->setValue(CD_DEF_TEXT_HEI);
    connect(at_sb_lheight,
        QOverload<double>::of(&QTdoubleSpinBox::valueChanged),
        this, &QTattributesDlg::lheight_sb_slot);

    label = new QLabel(tr("Maximum displayed label length"));
    grid->addWidget(label, 2, 0);

    at_sb_llen = new QSpinBox();
    grid->addWidget(at_sb_llen, 2, 1);
    at_sb_llen->setRange(DSP_MIN_MAX_LABEL_LEN, DSP_MAX_MAX_LABEL_LEN);
    at_sb_llen->setValue(DSP_DEF_MAX_LABEL_LEN);
    connect(at_sb_llen, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::llen_sb_slot);

    label = new QLabel(tr("Label optional displayed line limit"));
    grid->addWidget(label, 3, 0);

    at_sb_llines = new QSpinBox();
    grid->addWidget(at_sb_llines, 3, 1);
    at_sb_llines->setRange(DSP_MIN_MAX_LABEL_LINES, DSP_MAX_MAX_LABEL_LINES);
    at_sb_llines->setValue(DSP_DEF_MAX_LABEL_LINES);
    connect(at_sb_llines, QOverload<int>::of(&QSpinBox::valueChanged),
        this, &QTattributesDlg::llines_sb_slot);

    // Dismiss button
    //
    QPushButton *btn = new QPushButton(tr("Dismiss"));
    btn->setObjectName("Default");
    vbox->addWidget(btn);
    connect(btn, &QAbstractButton::clicked,
        this, &QTattributesDlg::dismiss_btn_slot);

    update();
}


QTattributesDlg::~QTattributesDlg()
{
    instPtr = 0;
    if (at_caller)
        QTdev::Deselect(at_caller);
}


#ifdef Q_OS_MACOS
#define DLGTYPE QTattributesDlg
#include "qtinterf/qtmacos_event.h"
#endif


void
QTattributesDlg::update()
{
    QTdev::SetStatus(at_minst,
        CDvdb()->getVariable(VA_MarkInstanceOrigin));
    QTdev::SetStatus(at_mcntr,
        CDvdb()->getVariable(VA_MarkObjectCentroid));
    QTdev::SetStatus(at_abprop,
        CDvdb()->getVariable(VA_EraseBehindProps));

    int d;
    const char *str = CDvdb()->getVariable(VA_PhysPropTextSize);
    if (str && sscanf(str, "%d", &d) == 1 && d >= DSP_MIN_PTRM_TXTHT &&
            d <= DSP_MAX_PTRM_TXTHT)
        ;
    else
        d = DSP_DEF_PTRM_TXTHT;
    at_sb_tsize->setValue(d);

    if (at_ebthst != (int)DSP()->EraseBehindTerms()) {
        at_ebterms->setCurrentIndex(DSP()->EraseBehindTerms());
        at_ebthst = DSP()->EraseBehindTerms();
    }

    str = CDvdb()->getVariable(VA_TermTextSize);
    if (str && sscanf(str, "%d", &d) == 1 && d >= DSP_MIN_PTRM_TXTHT &&
            d <= DSP_MAX_PTRM_TXTHT)
        ;
    else
        d = DSP_DEF_PTRM_TXTHT;
    at_sb_ttsize->setValue(d);

    str = CDvdb()->getVariable(VA_TermMarkSize);
    if (str && sscanf(str, "%d", &d) == 1 && d >= DSP_MIN_PTRM_DELTA &&
            d <= DSP_MAX_PTRM_DELTA)
        ;
    else
        d = DSP_DEF_PTRM_DELTA;
    at_sb_tmsize->setValue(d);

    str = CDvdb()->getVariable(VA_CellThreshold);
    if (str && sscanf(str, "%d", &d) == 1 && d >= DSP_MIN_CELL_THRESHOLD &&
            d <= DSP_MAX_CELL_THRESHOLD)
        ;
    else
        d = DSP_DEF_CELL_THRESHOLD;
    at_sb_visthr->setValue(d);

    str = CDvdb()->getVariable(VA_ContextDarkPcnt);
    if (str && sscanf(str, "%d", &d) == 1 && d >= DSP_MIN_CX_DARK_PCNT &&
            d <= 100)
        ;
    else
        d = DSP_DEF_CX_DARK_PCNT;
    at_sb_cxpct->setValue(d);

    str = CDvdb()->getVariable(VA_LowerWinOffset);
    if (str && sscanf(str, "%d", &d) == 1 && d >= -16 && d <= 16)
        ;
    else
        d = 0;
    at_sb_offset->setValue(d);

    str = CDvdb()->getVariable(VA_LabelHiddenMode);
    d = str ? atoi(str) : 0;
    at_hdn->setCurrentIndex(d);

    double dd;
    str = CDvdb()->getVariable(VA_LabelDefHeight);
    if (str && sscanf(str, "%lf", &dd) == 1 && dd >= CD_MIN_TEXT_HEI &&
            dd <= CD_MAX_TEXT_HEI)
        ;
    else
        dd = CD_DEF_TEXT_HEI;
    at_sb_lheight->setValue(dd);

    str = CDvdb()->getVariable(VA_LabelMaxLen);
    if (str && sscanf(str, "%d", &d) == 1 && d >= DSP_MIN_MAX_LABEL_LEN &&
            d <= DSP_MAX_MAX_LABEL_LEN)
        ;
    else
        d = DSP_DEF_MAX_LABEL_LEN;
    at_sb_llen->setValue(d);

    str = CDvdb()->getVariable(VA_LabelMaxLines);
    if (str && sscanf(str, "%d", &d) == 1 && d >= DSP_MIN_MAX_LABEL_LINES &&
            d <= DSP_MAX_MAX_LABEL_LINES)
        ;
    else
        d = DSP_DEF_MAX_LABEL_LINES;
    at_sb_llines->setValue(d);
}


void
QTattributesDlg::help_btn_slot()
{
    DSPmainWbag(PopUpHelp("xic:attr"))
}


void
QTattributesDlg::cursor_menu_changed_slot(int i)
{
    CursorType ct = (CursorType)i;
    XM()->UpdateCursor(0, ct);
}


void
QTattributesDlg::usefwc_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_FullWinCursor, 0);
    else
        CDvdb()->clearVariable(VA_FullWinCursor);
}


void
QTattributesDlg::visthr_sb_slot(int d)
{
    if (d == DSP_DEF_CELL_THRESHOLD)
        CDvdb()->clearVariable(VA_CellThreshold);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_CellThreshold, buf);
    }
}


void
QTattributesDlg::cxpct_sb_slot(int d)
{
    if (d == DSP_DEF_CX_DARK_PCNT)
        CDvdb()->clearVariable(VA_ContextDarkPcnt);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_ContextDarkPcnt, buf);
    }
}


void
QTattributesDlg::offset_sb_slot(int d)
{
    if (d == 0)
        CDvdb()->clearVariable(VA_LowerWinOffset);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_LowerWinOffset, buf);
    }
}


void
QTattributesDlg::markinst_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_MarkInstanceOrigin, "");
    else
        CDvdb()->clearVariable(VA_MarkInstanceOrigin);
}


void
QTattributesDlg::markcntr_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_MarkObjectCentroid, "");
    else
        CDvdb()->clearVariable(VA_MarkObjectCentroid);
}


void
QTattributesDlg::abprop_btn_slot(int state)
{
    if (state)
        CDvdb()->setVariable(VA_EraseBehindProps, "");
    else
        CDvdb()->clearVariable(VA_EraseBehindProps);
}


void
QTattributesDlg::tsize_sb_slot(int d)
{
    if (d == DSP_DEF_PTRM_TXTHT)
        CDvdb()->clearVariable(VA_PhysPropTextSize);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_PhysPropTextSize, buf);
    }
}


void
QTattributesDlg::ebt_menu_changed_slot(int i)
{
    if (i == 0) {
        CDvdb()->clearVariable(VA_EraseBehindTerms);
        at_ebthst = 0;
    }
    else if (i == 1) {
        CDvdb()->setVariable(VA_EraseBehindTerms, "");
        at_ebthst = 1;
    }
    else if (i == 2) {
        CDvdb()->setVariable(VA_EraseBehindTerms, "all");
        at_ebthst = 2;
    }
}


void
QTattributesDlg::ttsize_sb_slot(int d)
{
    if (d == DSP_DEF_PTRM_TXTHT)
        CDvdb()->clearVariable(VA_TermTextSize);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_TermTextSize, buf);
    }
}


void
QTattributesDlg::tmsize_sb_slot(int d)
{
    if (d == DSP_DEF_PTRM_DELTA)
        CDvdb()->clearVariable(VA_TermMarkSize);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_TermMarkSize, buf);
    }
}


void
QTattributesDlg::hdn_menu_changed_slot(int i)
{
    if (i == 0)
        CDvdb()->clearVariable(VA_LabelHiddenMode);
    else if (i > 0) {
        char bf[8];
        bf[0] = '0' + i;
        bf[1] = 0;
        CDvdb()->setVariable(VA_LabelHiddenMode, bf);
    }
}


void
QTattributesDlg::lheight_sb_slot(double d)
{
    if (fabs(d - CD_DEF_TEXT_HEI) < 1e-3)
        CDvdb()->clearVariable(VA_LabelDefHeight);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%.2f", d);
        CDvdb()->setVariable(VA_LabelDefHeight, buf);
    }
}


void
QTattributesDlg::llen_sb_slot(int d)
{
    if (d == DSP_DEF_MAX_LABEL_LEN)
        CDvdb()->clearVariable(VA_LabelMaxLen);
    else {
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_LabelMaxLen, buf);
    }
}


void
QTattributesDlg::llines_sb_slot(int d)
{
    if (d == DSP_DEF_MAX_LABEL_LINES)
        CDvdb()->clearVariable(VA_LabelMaxLines);
    else {
        if (d > DSP_MAX_MAX_LABEL_LINES)
            d = DSP_MAX_MAX_LABEL_LINES;
        char buf[32];
        snprintf(buf, sizeof(buf), "%d", d);
        CDvdb()->setVariable(VA_LabelMaxLines, buf);
    }
}


void
QTattributesDlg::dismiss_btn_slot()
{
    XM()->PopUpAttributes(0, MODE_OFF);
}

