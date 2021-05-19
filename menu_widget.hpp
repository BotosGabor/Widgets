#ifndef MENU_WIDGET_H_INCLUDED
#define MENU_WIDGET_H_INCLUDED

#include <vector>
#include "graphics.hpp"
#include "widget.hpp"

class MenuWidget : public Widget {
    std::vector<std::string> options;
    int active_row, x_shift, y_shift;
    int max_row_count();
    int max_col_count();
    int max_len_count();
    int row_height();
public:
    MenuWidget(int lx, int ly, int sx, int sy);
    MenuWidget(int lx, int ly, int sx, int sy, std::vector<std::string>& sv);
    int get_active_row();
    std::string get_val();
    void append(std::string option);
    void dump();
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // MENU_WIDGET_H_INCLUDED
