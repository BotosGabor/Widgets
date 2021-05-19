#ifndef TEXT_BOX_H_INCLUDED
#define TEXT_BOX_H_INCLUDED

#include "widget.hpp"

class TextBox : public Widget {
    std::string val;
    int shift;
public:
    TextBox(int lx, int ly, int sx);
    virtual std::string get_val();
    int max_letters();
    virtual void draw();
    virtual void handle(genv::event ev);
    void dump();
};

#endif // TEXT_BOX_H_INCLUDED
