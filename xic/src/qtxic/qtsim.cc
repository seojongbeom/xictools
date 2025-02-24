
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

#include "qtsim.h"
#include <signal.h>

#include <QLayout>
#include <QGroupBox>
#include <QLabel>
#include <QPushButton>


//-----------------------------------------------------------------------------
// Popup for monitoring asynchronous simulation runs
//

void
cSced::PopUpSim(SpType status)
{
    if (!QTdev::exists() || !QTmainwin::exists())
        return;
    QTsimRunDlg::control(status);
}
// End of cSced functions.


SpType QTsimRunDlg::sp_status = SpNil;
QTsimRunDlg *QTsimRunDlg::instPtr;

QTsimRunDlg::QTsimRunDlg(const char *msg)
{
    instPtr = this;
    sp_status = SpNil;

    setWindowTitle(tr("SPICE Run"));
    setAttribute(Qt::WA_DeleteOnClose);
//    gtk_window_set_resizable(GTK_WINDOW(popup), false);

    QMargins qmtop(2, 2, 2, 2);
    QMargins qm;
    QVBoxLayout *vbox = new QVBoxLayout(this);
    vbox->setContentsMargins(qmtop);
    vbox->setSpacing(2);
    
    QGroupBox *gb = new QGroupBox();
    vbox->addWidget(gb);
    QHBoxLayout *hb = new QHBoxLayout(gb);
    hb->setContentsMargins(qm);

    sp_label = new QLabel(msg);
    hb->addWidget(sp_label);

    QHBoxLayout *hbox = new QHBoxLayout();
    hbox->setContentsMargins(qm);
    hbox->setSpacing(2);
    vbox->addLayout(hbox);

    QPushButton *btn = new QPushButton(tr("Pause"));
    hbox->addWidget(btn); 
    connect(btn, SIGNAL(clicked()), this, SLOT(pause_btn_slot()));

    btn = new QPushButton(tr("Dismiss"));
    hbox->addWidget(btn); 
    connect(btn, SIGNAL(clicked()), this, SLOT(dismiss_btn_slot()));

    QTmainwin *w = QTmainwin::self();
    set_transient_for(w);
    QTdev::self()->SetPopupLocation(GRloc(LW_LL), this, w->Viewport());
    show();
}


QTsimRunDlg::~QTsimRunDlg()
{
    sp_status = SpNil;
    instPtr = 0;
}


// Static function.
void
QTsimRunDlg::control(SpType status)
{
    const char *msg;
    switch (status) {
    case SpNil:
    default:
        if (instPtr)
            instPtr->hide();
        sp_status = SpNil;
        return;
    case SpBusy:
        msg = "Running...";
        sp_status = SpBusy;
        break;
    case SpPause:
        msg = "Paused";
        sp_status = SpPause;
        QTdev::self()->AddTimer(2000, sp_down_timer, 0);
        break;
    case SpDone:
        msg = "Analysis Complete";
        sp_status = SpDone;
        QTdev::self()->AddTimer(2000, sp_down_timer, 0);
        break;
    case SpError:
        msg = "Error: connection broken";
        sp_status = SpError;
        break;
    }
    if (instPtr) {
        QTpkg::self()->RegisterIdleProc(sp_label_set_idle, (void*)msg);
        return;
    }

    new QTsimRunDlg(msg);
}


// Static function.
// Make the popup go away after an interval.
//
int
QTsimRunDlg::sp_down_timer(void*)
{
    if (instPtr)
        instPtr->hide();
    return (false);
}


// Static function.
int
QTsimRunDlg::sp_label_set_idle(void *arg)
{
    if (instPtr) {
        const char *msg = (const char*)arg;
        instPtr->sp_label->setText(msg);
        instPtr->show();
    }
    return (false);
}


void
QTsimRunDlg::pause_btn_slot()
{
    // Tell the simulator to pause, if an analysis is in progress.
    SCD()->spif()->InterruptSpice();
}


void
QTsimRunDlg::dismiss_btn_slot()
{
    if (instPtr)
        instPtr->hide();
}

