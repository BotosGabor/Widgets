#ifndef VISUAL_HPP_INCLUDED
#define VISUAL_HPP_INCLUDED

class Visual {
public:
    void rectangle(int lx, int ly, int sx, int sy);
    void inactive_background(int lx, int ly, int sx, int sy);
    void active_background(int lx, int ly, int sx, int sy);
    void figure(int v, int lx, int ly, int sx, int sy);
    void increaser(int lx, int ly, int sx, int sy);
    void decreaser(int lx, int ly, int sx, int sy);
};

#endif // VISUAL_HPP_INCLUDED
