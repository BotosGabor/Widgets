#include <string>
#include <vector>
#include "graphics.hpp"
#include "screen.hpp"
#include "button.hpp"
#include "menu_widget.hpp"
#include "number_widget.hpp"
#include "text_box.hpp"
using namespace genv;
using namespace std;

extern const int X = 1000, Y = 1000;
Screen S;

void Screen::append(Widget* w) {
    widgets.push_back(w);
}

void Screen::event_loop() {

    // START WIDGET DECLARATIONS HERE
    MenuWidget* mw = new MenuWidget(0, 0, 500, 500);
    NumberWidget* nw = new NumberWidget(500, 0, 500, 500, -1000000, 1000000);
    Button* btn = new Button(0, 500, 500, 500, "Add value!");
    // END WIDGET DECLARATIONS HERE

    gout.open(X, Y);
    event ev;
    int focus = -1;
    do {

        // START BUTTON HANDLING HERE
        btn->set_f([&] {
            mw->append(to_string(nw->get_val()));
        });
        // END BUTTON HANDLING HERE

        if (ev.type == ev_mouse && ev.button == btn_left)
            for (size_t i = 0; i < widgets.size(); i++) {
                if (widgets[i]->is_selected(ev.pos_x, ev.pos_y)) {
                    focus = i;
                    widgets[i]->set_active(1);
                }
                else widgets[i]->set_active(0);
            }
        if (focus != -1) widgets[focus]->handle(ev);
        for (Widget* w : widgets) w->draw();
        gout << refresh;
    } while (gin >> ev && ev.keycode != key_escape);
}
