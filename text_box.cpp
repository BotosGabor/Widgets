#include "graphics.hpp"
#include "text_box.hpp"
using namespace genv;
using namespace std;

TextBox::TextBox(int lx, int ly, int sx) :
Widget(lx, ly, sx, gout.cascent() + gout.cdescent() + 10), val(""), shift(0) {}

string TextBox::get_val() {
    return val;
}

int TextBox::max_letters() {
    return (sx-10)/gout.twidth(".");
}

void TextBox::draw() {
    Widget::draw();
    gout << color(192,24,24) << move_to(lx+5, ly+gout.cascent()+5)
         << text(val.substr(shift, max_letters()+shift));
}

void TextBox::handle(event ev) {
    if (ev.keycode == key_backspace && !val.empty()) val.pop_back();
    else if (ev.type == ev_key && 0 < ev.keycode) val += ev.keycode;
    if (size_t(max_letters()) < val.length())
        shift = val.length() - max_letters();
}

void TextBox::dump() {
    val = "";
}
