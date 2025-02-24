
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

#include "qtmain.h"
#include "qtexpand.h"
#include "dsp_inlines.h"

#include <QAction>
#include <QGroupBox>
#include <QLabel>
#include <QLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QToolButton>


QTexpandDlg::QTexpandDlg(QTbag *owner, const char *string, bool nopeek,
    void *arg) : QDialog(owner ? owner->Shell() : 0)
{
    p_parent = owner;
    p_cb_arg = arg;
    p_callback = 0;

    if (owner)
        owner->MonitorAdd(this);

    setWindowTitle(QString(tr("Expand")));
    setAttribute(Qt::WA_DeleteOnClose);

    QMargins qmtop(2, 2, 2, 2);
    QMargins qm;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(qmtop);
    vbox->setSpacing(2);

    QHBoxLayout *hbox = new QHBoxLayout();
    vbox->addLayout(hbox);
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);

    QGroupBox *gb = new QGroupBox();
    hbox->addWidget(gb);
    QHBoxLayout *hb = new QHBoxLayout(gb);
    hb->setContentsMargins(qm);
    hb->setSpacing(2);
    label = new QLabel(tr("Set Expansion Control String"));
    hb->addWidget(label);

    b_help = new QPushButton(tr("Help"));
    hbox->addWidget(b_help);
    b_help->setAutoDefault(false);
    b_help->setMaximumWidth(70);
    connect(b_help, SIGNAL(clicked()), this, SLOT(help_slot()));

    hbox = new QHBoxLayout();
    vbox->addLayout(hbox);
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    
    edit = new QLineEdit();
    edit->setText(string);
    edit->setMaximumWidth(60);
    hbox->addWidget(edit);

    b_plus = new QToolButton();
    hbox->addWidget(b_plus);
    b_plus->setText(QString("+"));
//XXX    b_plus->setAutoDefault(false);
    connect(b_plus, SIGNAL(clicked()), this, SLOT(plus_slot()));

    b_minus = new QToolButton();
    hbox->addWidget(b_minus);
    b_minus->setText(QString("-"));
//XXX    b_minus->setAutoDefault(false);
    connect(b_minus, SIGNAL(clicked()), this, SLOT(minus_slot()));

    b_all = new QToolButton();
    hbox->addWidget(b_all);
    b_all->setText(QString(tr("all")));
//XXX    b_all->setAutoDefault(false);
    connect(b_all, SIGNAL(clicked()), this, SLOT(all_slot()));

    b_0 = new QToolButton();
    hbox->addWidget(b_0);
    b_0->setText(QString("0"));
//XXX    b_0->setAutoDefault(false);
    connect(b_0, SIGNAL(clicked()), this, SLOT(b0_slot()));

    b_1 = new QToolButton();
    hbox->addWidget(b_1);
    b_1->setText(QString("1"));
//XXX    b_1->setAutoDefault(false);
    connect(b_1, SIGNAL(clicked()), this, SLOT(b1_slot()));

    b_2 = new QToolButton();
    hbox->addWidget(b_2);
    b_2->setText(QString("2"));
//XXX    b_2->setAutoDefault(false);
    connect(b_2, SIGNAL(clicked()), this, SLOT(b2_slot()));

    b_3 = new QToolButton();
    hbox->addWidget(b_3);
    b_3->setText(QString("3"));
//XXX    b_3->setAutoDefault(false);
    connect(b_3, SIGNAL(clicked()), this, SLOT(b3_slot()));

    b_4 = new QToolButton();
    hbox->addWidget(b_4);
    b_4->setText(QString("4"));
//XXX    b_4->setAutoDefault(false);
    connect(b_4, SIGNAL(clicked()), this, SLOT(b4_slot()));

    b_5 = new QToolButton();
    hbox->addWidget(b_5);
    b_5->setText(QString("5"));
//XXX    b_5->setAutoDefault(false);
    connect(b_5, SIGNAL(clicked()), this, SLOT(b5_slot()));

    if (!nopeek) {
        b_peek = new QPushButton(tr("Peek Mode"));
        b_peek->setAutoDefault(false);
        hbox->addWidget(b_peek);
        connect(b_peek, SIGNAL(clicked()), this, SLOT(peek_slot()));
    }
    else
        b_peek = 0;

    hbox = new QHBoxLayout(0);
    vbox->addLayout(hbox);
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);

    b_apply = new QPushButton(tr("Apply"));
    hbox->addWidget(b_apply);
    b_apply->setAutoDefault(true);
    connect(b_apply, SIGNAL(clicked()), this, SLOT(apply_slot()));

    b_dismiss = new QPushButton(tr("Dismiss"));
    hbox->addWidget(b_dismiss);
    b_dismiss->setAutoDefault(false);
    connect(b_dismiss, SIGNAL(clicked()), this, SLOT(dismiss_slot()));
}


QTexpandDlg::~QTexpandDlg()
{
    if (p_usrptr)
        *p_usrptr = 0;
    if (p_caller && p_no_desel) {
        QObject *o = (QObject*)p_caller;
        if (o->isWidgetType()) {
            QPushButton *btn = dynamic_cast<QPushButton*>(o);
            if (btn)
                btn->setChecked(false);
        }
        else {
            QAction *a = dynamic_cast<QAction*>(o);
            if (a)
                a->setChecked(false);
        }
    }
    if (p_parent) {
        QTsubwin *owner = dynamic_cast<QTsubwin*>(p_parent);
        if (owner) {
            owner->MonitorRemove(this);
            owner->clear_expand();
        }
    }
    if (p_callback)
        (*p_callback)(0, p_cb_arg);
}


// GRpopup override
//
void
QTexpandDlg::popdown()
{
    if (!p_parent)
        return;
    QTbag *owner = dynamic_cast<QTbag*>(p_parent);
    if (!owner || !owner->MonitorActive(this))
        return;

    deleteLater();
}


void
QTexpandDlg::update(const char *string)
{
    edit->setText(QString(string));
}


void
QTexpandDlg::help_slot()
{
    DSPmainWbag(PopUpHelp("xic:expnd"))
}


void
QTexpandDlg::plus_slot()
{
    QString qs = edit->text();
    if (!qs.isNull()) {
        const char *t = qs.toLatin1().constData();
        if (*t == '+') {
            qs = qs + QString("+");
            edit->setText(qs);
            return;
        }
    }
    edit->setText(QString("+"));
}


void
QTexpandDlg::minus_slot()
{
    QString qs = edit->text();
    if (!qs.isNull()) {
        const char *t = qs.toLatin1().constData();
        if (*t == '-') {
            qs = qs + QString("-");
            edit->setText(qs);
            return;
        }
    }
    edit->setText(QString("-"));
}


void
QTexpandDlg::all_slot()
{
    edit->setText(QString(tr("all")));
}


void
QTexpandDlg::b0_slot()
{
    edit->setText(QString("0"));
}


void
QTexpandDlg::b1_slot()
{
    edit->setText(QString("1"));
}


void
QTexpandDlg::b2_slot()
{
    edit->setText(QString("2"));
}


void
QTexpandDlg::b3_slot()
{
    edit->setText(QString("3"));
}


void
QTexpandDlg::b4_slot()
{
    edit->setText(QString("4"));
}


void
QTexpandDlg::b5_slot()
{
    edit->setText(QString("5"));
}


void
QTexpandDlg::peek_slot()
{
    edit->setText(QString("p"));
}


void
QTexpandDlg::apply_slot()
{
    char *string = lstring::copy(edit->text().toLatin1().constData());
    bool ret = false;
    if (p_callback)
        ret = (*p_callback)(string, p_cb_arg);
    emit apply(string, p_cb_arg);
    if (!ret)
        popdown();
}


void
QTexpandDlg::dismiss_slot()
{
    deleteLater();
}

