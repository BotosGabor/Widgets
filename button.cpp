#include "graphics.hpp"
#include "button.hpp"
using namespace genv;
using namespace std;

Button::Button(int lx, int ly, int sx, int sy, string message) :
Widget(lx, ly, sx, sy), pressed(0), message(message), f({}) {}

void Button::set_active(bool active) {
    this->active = active;
}

void Button::set_f(function<void()> f) {
    this->f = f;
}

void Button::draw() {
    if (pressed) v.active_background(lx, ly, sx, sy);
    else v.inactive_background(lx, ly, sx, sy);
    gout << color(224,224,224)
         << move_to(lx + 0.5*sx - 0.5*gout.twidth(message),
                    ly + 0.5*sy + 0.5*gout.cascent() - gout.cdescent())
         << text(message);
}

void Button::handle(event ev) {
    if (ev.button == btn_left) f();
    if (ev.button == btn_left || (pressed && ev.type == ev_mouse)) pressed = 1;
    if (ev.button < 0) pressed = 0;
}
