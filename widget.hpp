#ifndef WIDGET_H_INCLUDED
#define WIDGET_H_INCLUDED

#include "graphics.hpp"
#include "visual.hpp"

class Widget {
protected:
    bool active;
    int lx, ly, sx, sy;
    Visual v;
public:
    Widget(int lx, int ly, int sx, int sy);
    virtual void set_active(bool active);
    virtual void draw();
    virtual bool is_selected(int mx, int my);
    virtual void handle(genv::event ev) = 0;
};
                                                                                                                                                                                                                                                                  // https://www.youtube.com/watch?v=dQw4w9WgXcQ
#endif // WIDGET_H_INCLUDED
