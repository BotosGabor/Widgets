#include "menu_widget.hpp"
using namespace genv;
using namespace std;

MenuWidget::MenuWidget(int lx, int ly, int sx, int sy) :
Widget(lx, ly, sx, sy), options({}), active_row(-1), x_shift(0), y_shift(0) {}

MenuWidget::MenuWidget(int lx, int ly, int sx, int sy, vector<string>& sv) :
Widget(lx, ly, sx, sy), options(sv), active_row(-1), x_shift(0), y_shift(0) {}

int MenuWidget::get_active_row() {
    return active_row;
}

string MenuWidget::get_val() {
    if (active_row != -1)
        return options[active_row];
    else
        return "";
}

void MenuWidget::append(string option) {
    options.push_back(option);
}

void MenuWidget::dump() {
        options.erase(options.begin() + active_row);
        if (size_t(active_row) == options.size()) active_row--;
        if (size_t(y_shift) > options.size() - max_row_count()) y_shift--;
}

int MenuWidget::max_row_count() {
    return (sy - 10) / row_height();
}

int MenuWidget::max_col_count() {
    return (sx - 10) / (gout.twidth("."));
}

int MenuWidget::max_len_count() {
    int mx = 0;
    for (string str : options) if (size_t(mx) < str.size()) mx = str.size();
    return mx;
}

int MenuWidget::row_height() {
    return gout.cascent() + gout.cdescent() + 5;
}

void MenuWidget::draw() {
    Widget::draw();
    for (int i = 0; size_t(i) < options.size() && i < max_row_count(); i++) {
        if (i + y_shift == active_row) {
            gout << color(36, 36, 36)
                 << move_to(lx + 2, ly + 6 + i * row_height() - gout.cdescent())
                 << box(sx - 4, row_height());
        }
        gout << color(192, 24, 24)
             << move_to(lx + 5, ly + i * row_height() + gout.cascent() + 5)
             << text(options[i + y_shift].substr(x_shift, max_col_count()));
    }
}

void MenuWidget::handle(event ev) {
    if (ev.keycode == key_delete && active_row != -1) // DELETE OPTION
        dump();
    else if (ev.keycode == 0x61 && x_shift) // SCROLL LEFT
        x_shift--;
    else if (ev.keycode == 0x64 &&
             x_shift < max_len_count() - max_col_count()) // SCROLL RIGHT
        x_shift++;
    else if (ev.button == btn_wheelup && y_shift) // SCROLL UP
        y_shift--;
    else if (ev.button == btn_wheeldown &&
             size_t(max_row_count()) < options.size() &&
             size_t(y_shift) < options.size() - max_row_count()) // SCROLL DOWN
        y_shift++;
    else if (ev.button == btn_left &&
        size_t(y_shift + (ev.pos_y - ly) / row_height()) < options.size()) // CHOOSE
        active_row = y_shift + (ev.pos_y - ly) / row_height();
}
