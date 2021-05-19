#ifndef BUTTON_HPP_INCLUDED
#define BUTTON_HPP_INCLUDED

#include <functional>
#include "widget.hpp"

class Button : public Widget {
    bool pressed;
    std::string message;
    std::function<void()> f;
public:
    Button(int lx, int ly, int sx, int sy, std::string message);
    void set_active(bool active);
    void set_f(std::function<void()> f);
    virtual void draw();
    virtual void handle(genv::event ev);
};

#endif // BUTTON_HPP_INCLUDED
