
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

#ifndef QTSEARCH_H
#define QTSEARCH_H

#include "ginterf/graphics.h"
#include <QVariant>
#include <QDialog>
#include <QTimer>
#include <QKeyEvent>


class QCheckBox;
class QGroupBox;
class QLabel;
class QLineEdit;
class QPushButton;

namespace qtinterf {
    class QTbag;
    class QTsearchDlg;
}

class qtinterf::QTsearchDlg : public QDialog, public GRpopup
{
    Q_OBJECT

public:
    QTsearchDlg(QTbag*, const char*);
    ~QTsearchDlg();

#ifdef Q_OS_MACOS
    bool event(QEvent*);
#endif

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
    void popdown();

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

    void set_ign_case(bool);
    void set_message(const char*);
    void set_transient_message(const char*);
    QString get_target();

signals:
    void search_down();
    void search_up();
    void ignore_case(bool);

private slots:
    void down_btn_slot();
    void up_btn_slot();
    void icase_btn_slot(bool);
    void dismiss_btn_slot();
    void timeout_slot();

private:
    QLabel      *se_label;
    QLineEdit   *se_edit;
    QCheckBox   *se_nc;
    const char  *se_label_string;
    QTimer      se_timer;
};

#endif

