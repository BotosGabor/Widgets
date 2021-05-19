#ifndef SCREEN_HPP_INCLUDED
#define SCREEN_HPP_INCLUDED

#include <vector>
#include "widget.hpp"

class Screen {
private:
    std::vector<Widget*> widgets;
public:
    void append(Widget* w);
    void event_loop();
};

extern const int X, Y;
extern Screen S;

#endif // SCREEN_HPP_INCLUDED
