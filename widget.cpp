#include "graphics.hpp"
#include "widget.hpp"
#include "screen.hpp"
using namespace genv;

Widget::Widget(int lx, int ly, int sx, int sy) :
active(0), lx(lx), ly(ly), sx(sx), sy(sy) {
    S.append(this);
}

void Widget::set_active(bool active) {
    this->active = active;
}

void Widget::draw() {
    if (active) v.active_background(lx, ly, sx, sy);
    else v.inactive_background(lx, ly, sx, sy);
}

bool Widget::is_selected(int mx, int my) {
    return lx < mx && mx < lx + sx && ly < my && my < ly + sy;
}
