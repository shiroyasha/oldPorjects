#include <cairo/cairo.h>
#include <cairo/cairo-xlib.h>
#include <X11/Xlib.h>

#include <iostream>

void showxlib()
{
    Display *dpy;
    Window rootwin;
    Window win;
    XEvent e;
    int scr;
    cairo_surface_t *cs;

    cairo_t *cr;

    if( !( dpy=XOpenDisplay(NULL ) ) )
    {
        std::cout << "Error creating display" << std::endl;
        return;
    }

    scr=DefaultScreen(dpy);
    rootwin=RootWindow(dpy, scr);

    win = XCreateSimpleWindow(dpy, rootwin, 1, 1, 640, 480, 0,
                              BlackPixel(dpy, scr), BlackPixel(dpy, scr));

    XStoreName(dpy, win, "hello");
    XSelectInput(dpy, win, ExposureMask|ButtonPressMask);
    XMapWindow(dpy, win);

    cs = cairo_xlib_surface_create(dpy, win, DefaultVisual(dpy, 0), 640, 480);

    cr = cairo_create(cs);

    while(1)
    {
        XNextEvent(dpy, &e);
        if( e.type==Expose && e.xexpose.count<1 )
        {
            cairo_paint(cr);
        }
        else if(e.type==ButtonPress)
        {
            break;
        }
    }

    cairo_surface_destroy(cs);
    XCloseDisplay(dpy);
}

int main()
{
    showxlib();

    return 0;
}
