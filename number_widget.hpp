#ifndef NUMBER_WIDGET_H_INCLUDED
#define NUMBER_WIDGET_H_INCLUDED

#include "graphics.hpp"
#include "widget.hpp"

class NumberWidget : public Widget {
private:
    int mn, val, mx;
    int figure_count();
public:
    NumberWidget(int lx, int ly, int sx, int sy, int mn, int mx);
    virtual int get_val();
    void set_val(int n);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // NUMBER_WIDGET_H_INCLUDED
