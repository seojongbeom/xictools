
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

#include "qtcanvas_x.h"

#ifdef WITH_X11
#include <QX11Info>
#include <QColormap>
#include <QPixmap>
#include <QPainter>

#include <X11/Xutil.h>


using namespace qtinterf;

//XXXextern Drawable qt_x11Handle(const QPaintDevice *pd);

GC QTcanvas_x::com_gc = 0;
QColor QTcanvas_x::com_fg;
QColor QTcanvas_x::com_bg;
QColor QTcanvas_x::com_ghost;

QTcanvas_x::QTcanvas_x(bool use_common, QWidget *prnt) : QWidget(prnt)
{
    setMouseTracking(true);
    setMinimumWidth(50);
    setMinimumHeight(50);

    // GRmultiPt uses short integers.
    GRmultiPt::set_short_data(true);

//    da_display = x11Info().display();
    da_display = QX11Info::display();
    da_pixmap = 0;
    da_fore = 0;
    da_direct = false;
    if (use_common) {
        da_fg = &com_fg;
        da_bg = &com_bg;
        da_ghost = &com_ghost;
        if (!com_gc)
            com_gc = XCreateGC(da_display, winId(), 0, 0);
        da_gc = com_gc;
    }
    else {
        da_fg = &da_fg_bak;
        da_bg = &da_bg_bak;
        da_ghost = &da_ghost_bak;
        da_gc = XCreateGC(da_display, winId(), 0, 0);
    }
}


//
// The drawing interface.
//

void
QTcanvas_x::draw_direct(bool direct)
{
    if (direct) {
        da_fore = winId();
        da_direct = true;
    }
    else if (da_pixmap) {
//XXX        da_fore = qt_x11Handle(da_pixmap);
        da_direct = false;
    }
}


// Paint the screen window from the pixmap.
//
void
QTcanvas_x::update()
{
    repaint(0, 0, width(), height());
}


// Flood with the background color.
//
void
QTcanvas_x::clear()
{
    XSetForeground(da_display, da_gc, QColormap::instance().pixel(*da_bg));
    XFillRectangle(da_display, da_fore, da_gc, 0, 0, width(), height());
}


void
QTcanvas_x::clear_area(int x0, int y0, int w, int h)
{
    if (w <= 0)
        w = width() - x0;
    if (h <= 0)
        h = height() - y0;
    XSetForeground(da_display, da_gc, QColormap::instance().pixel(*da_bg));
    XFillRectangle(da_display, da_fore, da_gc, x0, y0, w, h);
}


// Set the foreground rendering color.
//
void
QTcanvas_x::set_foreground(unsigned int pix)
{
    da_fg->setRgb(pix);
    XSetForeground(da_display, da_gc, QColormap::instance().pixel(*da_fg));
}


// Set the background rendering color.
//
void
QTcanvas_x::set_background(unsigned int pix)
{
    da_bg->setRgb(pix);
    XSetBackground(da_display, da_gc, QColormap::instance().pixel(*da_bg));
}


// Draw one pixel.
//
void
QTcanvas_x::draw_pixel(int x0, int y0)
{
    XDrawPoint(da_display, da_fore, da_gc, x0, y0);
}


// Draw multiple pixels.
//
void
QTcanvas_x::draw_pixels(GRmultiPt *p, int n)
{
    XDrawPoints(da_display, da_fore, da_gc, (XPoint*)p->data(), n,
        CoordModeOrigin);
}


// Set the current line texture, used when da_line_mode = 0;
//
void
QTcanvas_x::set_linestyle(const GRlineType *lineptr)
{
    if (!lineptr || !lineptr->mask || lineptr->mask == -1) {
        XSetLineAttributes(da_display, da_gc, 0, LineSolid,
            CapButt, JoinMiter);
        return;
    }
    XSetLineAttributes(da_display, da_gc, 0, LineOnOffDash,
        CapButt, JoinMiter);

    XSetDashes(da_display, da_gc, lineptr->offset,
        (char*)lineptr->dashes, lineptr->length);
}


// Draw a line.
//
void
QTcanvas_x::draw_line(int x1, int y1, int x2, int y2)
{
    XDrawLine(da_display, da_fore, da_gc, x1, y1, x2, y2);
}


// Draw a connected line set.
//
void
QTcanvas_x::draw_polyline(GRmultiPt *p, int n)
{
    if (n < 2)
        return;
    XDrawLines(da_display, da_fore, da_gc, (XPoint*)p->data(), n,
        CoordModeOrigin);
}


// Draw multiple lines.
//
void
QTcanvas_x::draw_lines(GRmultiPt *p, int n)
{
    if (n < 1)
        return;
    XDrawSegments(da_display, da_fore, da_gc, (XSegment*)p->data(), n);
}


void
QTcanvas_x::define_fillpattern(GRfillType *fillp)
{
    if (!fillp)
        return;
    if (fillp->xPixmap()) {
        XFreePixmap(da_display, (Pixmap)fillp->xPixmap());
        fillp->setXpixmap(0);
    }
    if (fillp->hasMap()) {
        fillp->setXpixmap((void*)(long)XCreateBitmapFromData(da_display,
            winId(), (char*)fillp->map(), fillp->nX(), fillp->nY()));
    }
}


void
QTcanvas_x::set_fillpattern(const GRfillType *fillp)
{
    if (!fillp || !fillp->xPixmap())
        XSetFillStyle(da_display, da_gc, FillSolid);
    else {
        XSetFillStyle(da_display, da_gc, FillStippled);
        XSetStipple(da_display, da_gc, (Pixmap)fillp->xPixmap());
    }
}


// Draw a box, using current fill.
//
void
QTcanvas_x::draw_box(int x1, int y1, int x2, int y2)
{
    if (x1 > x2) {
        int temp = x1;
        x1 = x2;
        x2 = temp;
    }
    if (y1 > y2) {
        int temp = y1;
        y1 = y2;
        y2 = temp;
    }
    XFillRectangle(da_display, da_fore, da_gc, x1, y1, x2-x1 + 1, y2-y1 + 1);
}


// Draw multiple boxes, using current fill.
//
void
QTcanvas_x::draw_boxes(GRmultiPt *p, int n)
{
    XFillRectangles(da_display, da_fore, da_gc, (XRectangle*)p->data(), n);
}


// Draw a filled arc.
//
void
QTcanvas_x::draw_arc(int x0, int y0, int radius, int, double theta1, double theta2)
{
    if (theta1 >= theta2)
        theta2 = 2 * M_PI + theta2;
    int t1 = (int)(64 * (180.0 / M_PI) * theta1);
    int t2 = (int)(64 * (180.0 / M_PI) * theta2 - t1);
    if (t2 == 0)
        return;
    int dim = 2*radius;
    XDrawArc(da_display, da_fore, da_gc, x0 - radius, y0 - radius,
        dim, dim, t1, t2);
}


// Draw a filled polygon.
//
void
QTcanvas_x::draw_polygon(GRmultiPt *p, int n)
{
    XFillPolygon(da_display, da_fore, da_gc, (XPoint*)p->data(), n, Complex,
        CoordModeOrigin);
}


void
QTcanvas_x::draw_zoid(int yl, int yu, int xll, int xul, int xlr, int xur)
{
    if (yl >= yu)
        return;
    XPoint points[5];
    int n = 0;
    points[n].x = xll;
    points[n].y = yl;
    n++;
    points[n].x = xul;
    points[n].y = yu;
    n++;
    if (xur > xul) {
        points[n].x = xur;
        points[n].y = yu;
        n++;
    }
    points[n].x = xlr;
    points[n].y = yl;
    n++;
    if (xll < xlr) {
        points[n].x = xll;
        points[n].y = yl;
        n++;
    }
    if (n >= 4)
        XFillPolygon(da_display, da_fore, da_gc, points, n, Convex,
            CoordModeOrigin);
}


void
QTcanvas_x::draw_image(const GRimage *image, int xx, int yy, int w, int h)
{
    // Pure-X version, may have slightly less overhead than the gtk
    // code, but does not use SHM.  I can't see any difference
    // with/without SHM anyway.

/*XXX
    QX11Info info;

    XImage *im = XCreateImage(da_display, (Visual*)info.visual(),
        info.appDepth(), ZPixmap, 0, 0, w, h, 32, 0);
    im->data = (char*)malloc(im->bytes_per_line * im->height);

    for (int i = 0; i < h; i++) {
        int yd = i + yy;
        if (yd < 0)
            continue;
        if ((unsigned int)yd >= image->height())
            break;
        unsigned int *lptr = image->data() + yd*image->width();
        for (int j = 0; j < w; j++) {
            int xd = j + xx;
            if (xd < 0)
                continue;
            if ((unsigned int)xd >= image->width())
                break;
            XPutPixel(im, j, i, lptr[xd]);
        }
    }

    XPutImage(da_display, da_fore, da_gc, im, 0, 0, xx, yy, w, h);
    XDestroyImage(im);
*/
}


// Set the font used for rendering in the drawing area.
//
void
QTcanvas_x::set_font(QFont *fnt)
{
    setFont(*fnt);
}


// Return the pixel width of len characters in str when rendered with
// the given font.
//
int
QTcanvas_x::text_width(QFont *fnt, const char *str, int len)
{
    QFontMetrics fm(*fnt);
    return (fm.width(QString(str), len));
}


// Return the width and height of the string as rendered in the
// current font.
//
void
QTcanvas_x::text_extent(const char *str, int *w, int *h)
{
    if (!str)
        str = "x";
    if (w)
        *w = 0;
    if (h)
        *h = 0;
    const QFont &f = font();
    QFontMetrics fm(f);
    if (w)
        *w = fm.width(QString(str));
    if (h)
        *h = fm.height();
}


// Draw text, at most len characters from str if len >= 0.
//
void
QTcanvas_x::draw_text(int x0, int y0, const char *str, int len)
{
    QPaintDevice *pd;
    if (da_direct) {
//XXX        setAttribute(Qt::WA_PaintOutsidePaintEvent, true);
// Apparently this attribute no longer exists.
        // This allows drawing outside of a paint event.
        // WARNING: doesn't work on OS X.
        pd = this;
    }
    else {
        pd = da_pixmap;
        if (!pd)
            return;
    }

    QPainter p(pd);
    p.setFont(font());
    QString qs(str);
    if (len >= 0)
        qs.truncate(len);
    QPen pen;
    pen.setColor(*da_fg);
    p.setPen(pen);
    p.drawText(x0, y0, qs);
//    if (da_direct)
//        setAttribute(Qt::WA_PaintOutsidePaintEvent, false);
}


void
QTcanvas_x::set_xor_mode(bool set)
{
    if (set) {
        da_ghost_fg.setRgb(da_ghost->rgb() ^ da_bg->rgb());
        XSetFunction(da_display, da_gc, GXxor);
        XSetForeground(da_display, da_gc,
            QColormap::instance().pixel(da_ghost_fg));
        draw_direct(true);
    }
    else {
        XSetFunction(da_display, da_gc, GXcopy);
        XSetForeground(da_display, da_gc,
            QColormap::instance().pixel(*da_fg));
        draw_direct(false);
    }
}


void
QTcanvas_x::set_ghost_color(unsigned int pixel)
{
    da_ghost->setRgb(pixel);
}
// End of exported interface


void
QTcanvas_x::resizeEvent(QResizeEvent *ev)
{
    // This is an (undocumented?) hook in qpixmap_x11.cpp that forces
    // the XPixmap to a certain depth.  Without this, when running
    // remotely from Linux it was observed that the QPixmap is created
    // with a depth not equal to the screen depth.

//XXX    extern int qt_x11_preferred_pixmap_depth;
//XXX
//    qt_x11_preferred_pixmap_depth = QX11Info::appDepth();
//XXXqt_x11_preferred_pixmap_depth = 24;

    if (!da_gc)
        da_gc = XCreateGC(da_display, winId(), 0, 0);
    delete da_pixmap;
    da_pixmap = new QPixmap(ev->size());
    da_pixmap->fill(Qt::black);
    draw_direct(da_direct);
    emit resize_event(ev);

//XXX    qt_x11_preferred_pixmap_depth = 0;
}


void
QTcanvas_x::paintEvent(QPaintEvent *ev)
{
    if (!da_pixmap)
        return;
    QPainter p(this);
    QVector<QRect> rects = ev->region().rects();
    for (int i = 0; i < rects.size(); i++) {
        QRect r = rects.at(i);
        p.drawPixmap(r, *da_pixmap, r);
    }

    // The application can handle this to draw highlighting that is
    // not in the pixmap.  In some applications, it is desirable to
    // keep highlighting out of the pixmap, since it can be very
    // expensive to erase the highlighting.
    //
    emit paint_event(ev);
}


void
QTcanvas_x::mousePressEvent(QMouseEvent *ev)
{
    emit press_event(ev);
}


void
QTcanvas_x::mouseReleaseEvent(QMouseEvent *ev)
{
    emit release_event(ev);
}


void
QTcanvas_x::mouseMoveEvent(QMouseEvent *ev)
{
    emit motion_event(ev);
}


void
QTcanvas_x::keyPressEvent(QKeyEvent *ev)
{
    emit key_press_event(ev);
}


void
QTcanvas_x::keyReleaseEvent(QKeyEvent *ev)
{
    emit key_release_event(ev);
}


void
QTcanvas_x::enterEvent(QEvent *ev)
{
    emit enter_event(ev);
}


void
QTcanvas_x::leaveEvent(QEvent *ev)
{
    emit leave_event(ev);
}


void
QTcanvas_x::dragEnterEvent(QDragEnterEvent *ev)
{
    emit drag_enter_event(ev);
}


void
QTcanvas_x::dropEvent(QDropEvent *ev)
{
    emit drop_event(ev);
}

#endif

