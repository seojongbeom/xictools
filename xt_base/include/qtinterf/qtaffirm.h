
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

#ifndef QTAFFIRM_H
#define QTAFFIRM_H

#include "ginterf/graphics.h"

#include <QVariant>
#include <QDialog>

class QTextEdit;
class QPushButton;

namespace qtinterf {
    class QTaffirmDlg;
    class QTbag;
}

class qtinterf::QTaffirmDlg : public QDialog, public GRaffirmPopup
{
    Q_OBJECT

public:
    QTaffirmDlg(QTbag*, const char*);
    ~QTaffirmDlg();

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
    void register_caller(GRobject, bool=false, bool=false);
    void popdown();

    void set_transient_for(QWidget *prnt)
    {
        Qt::WindowFlags f = windowFlags();
        setParent(prnt);
#ifdef __APPLE__
        f |= Qt::Tool;
#endif
        setWindowFlags(f);
    }

    QSize sizeHint() const { return (QSize(300, 100)); }

signals:
    void affirm(bool, void*);

private slots:
    void affirm_btn_slot();
    void cancel_btn_slot();
};

#endif

