
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

#ifndef QTCHDOPEN_H
#define QTCHDOPEN_H

#include "main.h"
#include "qtmain.h"

#include <QDialog>


//-----------------------------------------------------------------------------
// QTchdOpenDlg:  Dialog to create a cell hierarchy digest (CHD).

class QTabWidget;
class QLineEdit;
class QComboBox;
class QRadioButton;
class QToolButton;
class QTcnameMap;

class QTchdOpenDlg : public QDialog, public QTbag
{
    Q_OBJECT

public:
    QTchdOpenDlg(GRobject, bool(*)(const char*, const char*, int, void*),
        void*, const char*, const char*);
    ~QTchdOpenDlg();

#ifdef Q_OS_MACOS
    bool event(QEvent*);
#endif

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

    void update(const char*, const char*);

    static QTchdOpenDlg *self()             { return (instPtr); }

private slots:
    void help_btn_slot();
    void p1_info_slot(int);
    void apply_btn_slot();
    void dismiss_btn_slot();

private:
    GRobject    co_caller;
    QTabWidget  *co_nbook;
    QLineEdit   *co_p1_text;
    QComboBox   *co_p1_info;
    QLineEdit   *co_p2_text;
    QRadioButton *co_p2_mem;
    QRadioButton *co_p2_file;
    QRadioButton *co_p2_none;
    QLineEdit   *co_idname;
    QToolButton *co_apply;

    QTcnameMap  *co_p1_cnmap;

    bool(*co_callback)(const char*, const char*, int, void*);
    void *co_arg;

    static QTchdOpenDlg *instPtr;
};

#endif

