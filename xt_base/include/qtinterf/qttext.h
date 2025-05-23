
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
 * QtInterf Graphical Interface Library                                   *
 *                                                                        *
 *========================================================================*
 $Id:$
 *========================================================================*/

#ifndef QTTEXT_H
#define QTTEXT_H

#include "ginterf/graphics.h"
#include "miscutil/lstring.h"

#include <QVariant>
#include <QDialog>
#include <QKeyEvent>


class QGroupBox;
class QToolButton;
namespace qtinterf {
    class QTbag;
    class QTtextDlg;
    class QTmsgDlg;
    class QTledDlg;
    class QTtextEdit;
}

class qtinterf::QTtextDlg : public QDialog, public GRtextPopup
{
    Q_OBJECT

public:
    // Fancy message box types.
    enum PuType {PuWarn, PuErr, PuErrAlso, PuInfo, PuInfo2, PuHTML};

    QTtextDlg(QTbag*, const char*, PuType=PuInfo, STYtype=STY_NORM);
    ~QTtextDlg();

#ifdef Q_OS_MACOS
    bool event(QEvent*);
#endif

    QSize sizeHint() const;

    // GRpopup overrides
    void set_visible(bool visib)
        {
            if (visib) {
                show();
                raise();
                activateWindow();
            }
            else
                hide();
        }
    void set_desens()               { tx_desens = true; }
    bool is_desens()                { return (tx_desens); }

    void set_transient_for(QWidget *prnt)
        {
            Qt::WindowFlags f = windowFlags();
            setParent(prnt);
#ifdef Q_OS_MACOS
            f |= Qt::Tool;
#endif
            setWindowFlags(f);
        }

    // Don't pop down from Esc press.
    void keyPressEvent(QKeyEvent *ev)
        {
            if (ev->key() != Qt::Key_Escape)
                QDialog::keyPressEvent(ev);
        }

    // When set, error pop-ups have a "Show Error Log" button that
    // pops up a file browser on this file.
    //
    static void set_error_log(const char *s)
        {
            char *t = lstring::copy(s);
            delete [] tx_errlog;
            tx_errlog = t;
        }

    void popdown();
    void setTitle(const char*);
    void setText(const char*);
    bool get_btn2_state();
    void set_btn2_state(bool);
    bool update(const char*);

    QTtextEdit *editor()        { return (tx_tbox); }

private slots:
    void save_btn_slot(bool);
    void showlog_btn_slot();
    void help_btn_slot();
    void activate_btn_slot(bool);
    void dismiss_btn_slot();
    void anchor_clicked_slot(const QUrl&);

private:
    static ESret tx_save_cb(const char*, void*);
    static int tx_timeout(void*);

    QTtextEdit  *tx_tbox;
    QToolButton *tx_save;
    QToolButton *tx_activate;
    QTledDlg    *tx_save_pop;
    QTmsgDlg    *tx_msg_pop;
    PuType      tx_which;
    STYtype     tx_style;
    bool        tx_desens;      // If true, parent->wb_inout is disabled.

    static char *tx_errlog;
};

#endif

