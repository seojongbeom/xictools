
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

#ifndef QTEDIT_H
#define QTEDIT_H

#include "qtinterf.h"
#include <QVariant>
#include <QDialog>
#include <QKeyEvent>


class QLineEdit;
class QMenu;
class QMenuBar;
class QToolBar;
class QStatusBar;
class QGroupBox;
class QTextEdit;
class QCloseEvent;

namespace qtinterf {
    class QTsearchDlg;
    class QTeditDlg;
}

class qtinterf::QTeditDlg : public QDialog, public GReditPopup,
    public QTbag
{
    Q_OBJECT

public:
    // internal widget state
    enum EventType { QUIT, SAVE, SAVEAS, SOURCE, LOAD, TEXTMOD };

    // widget configuration
    enum EditorType { Editor, Browser, StringEditor, Mailer };

    QTeditDlg(QTbag*, QTeditDlg::EditorType, const char*, bool, void*);
    ~QTeditDlg();

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

    void set_caller(GRobject);
    EditorType get_editor_type()    const { return (ed_editor_type); }
    const char *get_file()          const { return (ed_source_file); }
    void load_file(const char *f)   { load_file_slot(f, 0); }

    void set_mailaddr(const char*);
    void set_mailsubj(const char*);

    QSize sizeHint() const
        {
            if (ed_editor_type == Mailer)
                return (QSize(400, 350));
            return (QSize(500, 300));
        }

private slots:
    void file_selection_slot(const char*, void*);
    void open_slot();
    void load_file_slot(const char*, void*);
    void load_slot();
    void read_file_slot(const char*, void*);
    void read_slot();
    void save_slot();
    void save_file_as_slot(const char*, void*);
    void save_as_slot();
#ifdef WIN32
    void write_crlf_slot(bool);
#endif
    void print_slot();
    void send_slot();
    void quit_slot();
    void undo_slot();
    void undo_available_slot(bool);
    void redo_slot();
    void redo_available_slot(bool);
    void cut_slot();
    void copy_slot();
    void paste_slot();
    void search_slot();
    void source_slot();
    void attach_file_slot(const char*, void*);
    void attach_slot();
    void unattach_slot(QAction*);
    void font_slot();
    void help_slot();
    void text_changed_slot();
    void search_down_slot();
    void search_up_slot();
    void ignore_case_slot(bool);
    void font_changed_slot(int);

private:
    void closeEvent(QCloseEvent*);
    bool read_file(const char*, bool);
    bool write_file(const char*, int, int);
    void set_source(const char*);
    void set_sens(bool);
    bool text_changed();

    EditorType  ed_editor_type;
    EventType   ed_last_event;
    char        *ed_saved_as;
    char        *ed_source_file;
    char        *ed_drop_file;
    char        *ed_last_search;
    bool        ed_text_changed;
    bool        ed_have_source;
    bool        ed_ign_case;
    bool        ed_ign_change;
    unsigned int ed_len;
    unsigned int ed_chksum;

    QWidget     *ed_bar;
    QTsearchDlg *ed_searcher;
    QMenu       *ed_filemenu;
    QMenu       *ed_editmenu;
    QMenu       *ed_optmenu;
    QMenu       *ed_helpmenu;
    QGroupBox   *ed_title;
    QLineEdit   *ed_to_entry;
    QLineEdit   *ed_subj_entry;
    QTtextEdit  *ed_text_editor;
    QStatusBar  *ed_status_bar;

    QAction     *ed_File_Load;
    QAction     *ed_File_Read;
    QAction     *ed_File_Save;
    QAction     *ed_File_SaveAs;
#ifdef WIN32
    QAction     *ed_File_CRLF;
#endif
    QAction     *ed_Edit_Undo;;
    QAction     *ed_Edit_Redo;;
    QAction     *ed_Options_Attach;
    QAction     *ed_HelpMenu;
};

#endif

