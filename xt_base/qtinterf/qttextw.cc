
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

#include "qttextw.h"
#include "miscutil/lstring.h"

#include <QScrollBar>
#include <QGuiApplication>
#include <QTextDocument>
#include <QTextBlock>
#include <QClipboard>


// A fixed text window class for general use, replaces the
// "text_window" utilities in the GTK verssion.

using namespace qtinterf;


QTtextEdit::QTtextEdit(QWidget *prnt) : QTextEdit(prnt)
{
    // Set an arrow cursor rather than te default I-beam.
    viewport()->setCursor(Qt::ArrowCursor);

    // Default to no wrapping, horizontal scroll bar should appear
    // insted.
    setLineWrapMode(QTextEdit::NoWrap);
}


// Editing.

// Delete the characters from start to end, -1 indicates end of text.
//
void
QTtextEdit::delete_chars(int start,int end)
{
    if (start == end)
        return;
    QTextCursor c = textCursor();
    c.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
    if (start) {
        c.movePosition(QTextCursor::NextCharacter,
            QTextCursor::MoveAnchor, start);
    }
    if (end < 0)
        c.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
    else if (end > start) {
        c.movePosition(QTextCursor::NextCharacter,
            QTextCursor::KeepAnchor, end-start);
    }
    else {
        c.movePosition(QTextCursor::PreviousCharacter,
            QTextCursor::KeepAnchor, start-end);
    }
    c.removeSelectedText();
    setTextCursor(c);
}


// Replace the chars from start to end with the same number of chars
// from string, -1 indicates end of text.  If -1 is given for end,
// the entirety of string will be inserted.
//
void
QTtextEdit::replace_chars(const QColor *color, const char *string,
    int start, int end)
{
    if (!string)
        return;
    if (start == end)
        return;
    delete_chars(start, end);
    QTextCursor c = textCursor();
    QColor clr = textColor();
    if (color)
        setTextColor(*color);
    if (end < 0)
        insertPlainText(string);
    else {
        int nc = abs(end - start);
        int len = strlen(string);
        if (len <= nc)
            insertPlainText(string);
        else {
            char *tstr = lstring::copy(string);
            tstr[nc] = 0;
            insertPlainText(tstr);
            delete [] tstr;
        }
    }
    setTextCursor(c);
    setTextColor(clr);
}


// Insertion.

void
QTtextEdit::set_editable(bool editable)
{
    setReadOnly(!editable);
}


// Insert nc chars from string into the text window at the given
// position.  If nc is -1, string must be null terminated and will be
// inserted in its entirety.  If pos is -1, insertion will start at
// the end of existing text.
//
void
QTtextEdit::insert_chars_at_point(const QColor *color, const char *string,
    int posn, int nc)
{
    if (!string || nc == 0)
        return;
    QTextCursor c = textCursor();
    if (posn < 0)
        c.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    else {
        c.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
        if (posn) {
            c.movePosition(QTextCursor::NextCharacter,
                QTextCursor::MoveAnchor, posn);
        }
    }
    setTextCursor(c);
    if (color)
        setTextColor(*color);
    else
        setTextColor(QColor("black"));
    if (nc < 0) {
        insertPlainText(string);
        return;
    }
    int len = strlen(string);
    if (len <= nc) {
        insertPlainText(string);
        return;
    }
    char *tstr = lstring::copy(string);
    tstr[nc] = 0;
    insertPlainText(tstr);
    delete [] tstr;
}


// Return the cursor offset into text.
//
int
QTtextEdit::get_insertion_point()
{
    QTextCursor c = textCursor();
    return (c.position());
}


// Set the cursor offset into text, -1 indicates end.
//
void
QTtextEdit::set_insertion_point(int posn)
{
    QTextCursor c = textCursor();
    if (posn < 0)
        c.movePosition(QTextCursor::End, QTextCursor::MoveAnchor);
    else {
        c.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
        if (posn) {
            c.movePosition(QTextCursor::NextCharacter,
                QTextCursor::MoveAnchor, posn);
        }
    }
    setTextCursor(c);
}


// Set the text in the text window, discarding any previous content.
//
void
QTtextEdit::set_chars(const char *str)
{
    setPlainText(str);
}


// Get text.

// Return the chars from start to end, -1 indicates end of text.
//
char *
QTtextEdit::get_chars(int start, int end)
{
    QByteArray qba = toPlainText().toLatin1();
    if (end < 0 || end > qba.length())
        end = qba.length();
    if (start < 0)
        start = 0;
    if (end < start) {
        int t = end;
        end = start;
        start = t;
    }
    char *str = new char[end - start + 1];
    int i = 0;
    while (start < end)
        str[i++] = qba[start++];
    str[i] = 0;
    return (str);
}


// Return the number of characters in the text.
//
int
QTtextEdit::get_length()
{
    return (toPlainText().toLatin1().size());
}


// Clipboard.

// Cut selected text to the clipboard.
//
void
QTtextEdit::cut_clipboard()
{
    cut();
    /*
    if (!has_selection())
        return;
    char *sel = get_selection();
    QClipboard *cb = QGuiApplication::clipboard();
    cb->setText(sel);
    delete [] sel;
    QTextCursor c = textCursor();
    c.removeSelectedText();
    setTextCursor(c);
    */
}


// Copy selected text to the clipboard.
//
void
QTtextEdit::copy_clipboard()
{
    copy();
    /*
    if (!has_selection())
        return;
    char *sel = get_selection();
    QClipboard *cb = QGuiApplication::clipboard();
    cb->setText(sel);
    delete [] sel;
    */
}


// Paste clipboard contents into text window.
//
void
QTtextEdit::paste_clipboard()
{
    paste();
    /*
    QClipboard *cb = QGuiApplication::clipboard();
    QString qs = cb->text();
    if (qs.isNull() || qs.isEmpty())
        return;
    QTextCursor c = textCursor();
    c.insertText(qs);
    setTextCursor(c);
    */
}


// Selection.

// Return true if the text window has a selection.
//
bool
QTtextEdit::has_selection()
{
    QTextCursor c = textCursor();
    return (c.position() != c.anchor());
}


// Return the selected text.
//
char *
QTtextEdit::get_selection()
{
    QTextCursor c = textCursor();
    if (c.position() == c.anchor())
        return (0);
    int s = c.position();
    int e = c.anchor();
    if (e < s) {
        int t = e;
        e = s;
        s = t;
    }
    char *sel = new char[e-s + 1];
    QByteArray qba = toPlainText().toLatin1();
    int i = 0;
    while (s < e)
        sel[i++] = qba[s++];
    sel[i] = 0;
    return (sel);
}


// Return the offsets of selected text.
//
void
QTtextEdit::get_selection_pos(int *strtp, int *endp)
{
    QTextCursor c = textCursor();
    if (strtp)
        *strtp = c.position();
    if (endp)
        *endp = c.anchor();
}


// Select the chars in the range, start=end deselects existing.
//
void
QTtextEdit::select_range(int start, int end)
{
    if (start == end) {
        QTextCursor c = textCursor();
        c.clearSelection();
        setTextCursor(c);
    }
    else {
        QTextCursor c = textCursor();
        c.movePosition(QTextCursor::Start, QTextCursor::MoveAnchor);
        if (start) {
            c.movePosition(QTextCursor::NextCharacter,
                QTextCursor::MoveAnchor, start);
        }
        if (end < 0)
            c.movePosition(QTextCursor::End, QTextCursor::KeepAnchor);
        else if (end > start) {
            c.movePosition(QTextCursor::NextCharacter,
                QTextCursor::KeepAnchor, end-start);
        }
        else {
            c.movePosition(QTextCursor::PreviousCharacter,
                QTextCursor::KeepAnchor, start-end);
        }
        setTextCursor(c);
    }
}


// Scrolling.

// Return the current scroll position.
//
int
QTtextEdit::get_scroll_value()
{
    QScrollBar *vsb = verticalScrollBar();
    int val = 0;
    if (vsb)
        val = (int)vsb->value();
    return (val);
}


// Set the scroll position.
//
void
QTtextEdit::set_scroll_value(int val)
{
    QScrollBar *vsb = verticalScrollBar();
    if (vsb)
        vsb->setValue(val);
}


// Change the val to keep line visible.
//
int
QTtextEdit::get_scroll_to_line_value(int line, int val)
{
    QTextCursor cur(document()->findBlockByLineNumber(line));
    moveCursor(QTextCursor::End);
    setTextCursor(cur);
//XXX fix this, should return new scroll posn but not sctually scroll there?
return (val);

/*
    GtkTextBuffer *tbf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
    GtkTextIter inewpos;
    gtk_text_buffer_get_iter_at_line(tbf, &inewpos, line);
    GdkRectangle rect;
    gtk_text_view_get_visible_rect(GTK_TEXT_VIEW(widget), &rect);
    int ly, lht;
    gtk_text_view_get_line_yrange(GTK_TEXT_VIEW(widget), &inewpos,
        &ly, &lht);
    if (ly < rect.y + 2 || ly + lht > rect.y + rect.height - 2) {
        int x, y;
        gtk_text_view_buffer_to_window_coords(GTK_TEXT_VIEW(widget),
            GTK_TEXT_WINDOW_WIDGET, 0, ly, &x, &y);
        val = y;
    }
    return (val);
*/
}


// Scroll the window to make pos (character offset, -1 indicates end)
// visible.
//
void
QTtextEdit::scroll_to_pos(int posn)
{
    set_insertion_point(posn);  // scrolls there automatically?

/*
    GtkTextBuffer *tbf = gtk_text_view_get_buffer(GTK_TEXT_VIEW(widget));
    GtkTextIter ipos;
    gtk_text_buffer_get_iter_at_offset(tbf, &ipos, pos);
    gtk_text_view_scroll_to_iter(GTK_TEXT_VIEW(widget), &ipos, .05, false,
        0, 0);
*/
}

