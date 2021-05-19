#include "number_widget.hpp"
using namespace genv;
using namespace std;

#include <iostream>

NumberWidget::NumberWidget
(int lx, int ly, int sx, int sy, int mn, int mx) :
Widget(lx, ly, sx, sy), mn(mn), mx(mx) {
    if (mn <= 0 && 0 <= mx) val = 0;
    else val = mn;
}

int NumberWidget::get_val() {
    return val;
}

void NumberWidget::set_val(int n) {
    val = n;
}

int NumberWidget::figure_count() {
    int c = 0;
    for (int temp_val = val; temp_val != 0; c++) temp_val /= 10;
    if (val < 0) return c + 1;
    else return c;
}

void NumberWidget::draw() {
    Widget::draw();
    int temp_val = val;
    int c = figure_count();
    if (temp_val < 0) temp_val *= -1;
    if (!val) v.figure(0, lx, ly, sx - 20, sy);
    else for (int i = 0; i < c; i++) {
        int figure = temp_val % 10;
        int temp_sx = (sx - 20)/c;
        int temp_sy = sy;
        if (2*temp_sx < sy) temp_sy = 2*temp_sx;
        else temp_sx = 0.5*temp_sy;
        int temp_lx = lx + sx - 20 - (i + 1)*(sx - 20)/c;
        int temp_ly = ly + (sy - temp_sy) / 2;
        if (val < 0 && i == c-1) {
            v.rectangle(lx + 5, ly + 0.5*sy - 0.05*temp_sy,
                        temp_sx - 10, 0.1*temp_sy);
        }
        else {
            v.figure(figure, temp_lx, temp_ly, temp_sx, temp_sy);
            temp_val = (temp_val - figure) / 10;
        }
    }
    v.increaser(lx + sx - 20, ly + 5, 15, 0.5*sy - 10);
    v.decreaser(lx + sx - 20, ly + 0.5*sy + 5, 15, 0.5*sy - 10);
}

void NumberWidget::handle(event ev) {
    if (ev.button == btn_left &&
        lx + sx - 20 < ev.pos_x &&
        ev.pos_x < lx + sx - 5 &&
        ly + 5 < ev.pos_y &&
        ev.pos_y < ly + 0.5*sy - 5 &&
        val != mx) {
            val++;
    }
    if (ev.button == btn_left &&
        lx + sx - 20 < ev.pos_x &&
        ev.pos_x < lx + sx - 5 &&
        ly + 0.5*sy + 5 < ev.pos_y &&
        ev.pos_y < ly + sy - 5 &&
        val != mn) {
            val--;
    }

    /*
    page_up   -> w
    page_down -> s
    fel       -> q
    le        -> a
    */
    if (ev.keycode == 0x71 && val != mx)    val++;
    if (ev.keycode == 0x61 && val != mn)    val--;
    if (ev.keycode == 0x77 && val < mx - 9) val += 10;
    if (ev.keycode == 0x73 && val > mn + 9) val -= 10;
    if (ev.keycode == 0x65 && val < mx - 99) val += 100;
    if (ev.keycode == 0x64 && val > mn + 99) val -= 100;
    if (ev.keycode == 0x72 && val < mx - 999) val += 1000;
    if (ev.keycode == 0x66 && val > mn + 999) val -= 1000;
}
