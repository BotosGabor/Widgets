#include <math.h>
#include <list>
#include "graphics.hpp"
#include "visual.hpp"
using namespace genv;
using namespace std;

bool operator == (int x, const list<int> l) {
    for (int elem : l) if (x == elem) return true;
    return false;
}

void Visual::rectangle(int lx, int ly, int sx, int sy) {
    gout << move_to(lx, ly) << box(sx, sy);
}

void Visual::inactive_background(int lx, int ly, int sx, int sy) {
    gout << color(192,24,24);
    rectangle(lx, ly, sx, sy);
    gout << color(16,16,16);
    rectangle(lx+2, ly+2, sx-4, sy-4);
}

void Visual::active_background(int lx, int ly, int sx, int sy) {
    gout << color(24,192,24);
    rectangle(lx, ly, sx, sy);
    gout << color(16,16,16);
    rectangle(lx+2, ly+2, sx-4, sy-4);
}

void Visual::figure(int v, int lx, int ly, int sx, int sy) {
    gout << color(192,24,24);
    if (v == list<int>({0,2,3,5,6,7,8,9})) //SECTOR A
        rectangle(lx + 5, ly + 5, sx - 10, 0.1*sy);
    if (v == list<int>({0,1,2,3,4,7,8,9})) //SECTOR B
        rectangle(lx + 0.8*sx - 5, ly + 5, 0.2*sx + 1, 0.55*sy - 5);
    if (v == list<int>({0,1,3,4,5,6,7,8,9})) //SECTOR C
        rectangle(lx + 0.8*sx - 5, ly + 0.45*sy, 0.2*sx + 1, 0.55*sy - 5);
    if (v == list<int>({0,2,3,5,6,8,9})) //SECTOR D
        rectangle(lx + 5, ly + 0.9*sy - 5, sx - 10, 0.1*sy);
    if (v == list<int>({0, 2, 6, 8})) //SECTOR E
        rectangle(lx + 5, ly + 0.45*sy, 0.2*sx, 0.55*sy - 5);
    if (v == list<int>({0,4,5,6,8,9})) //SECTOR F
        rectangle(lx + 5, ly + 5, 0.2*sx, 0.55*sy - 5);
    if (v == list<int>({2,3,4,5,6,8,9})) //SECTOR G
        rectangle(lx + 5, ly + 0.45*sy, sx - 10, 0.1*sy);
}

void Visual::increaser(int lx, int ly, int sx, int sy) {
    gout << color(240, 240, 240);
    for (int i = 0; i < sx; i++)
        for (int j = 0; j < sy; j++)
            if (fabs(0.5*sx - i) <= sx*j/sy)
                gout << move_to(lx + i, ly + j) << dot;
}

void Visual::decreaser(int lx, int ly, int sx, int sy) {
    gout << color(240, 240, 240);
    for (int i = 0; i < sx; i++)
        for (int j = 0; j < sy; j++)
            if (fabs(0.5*sx - i) <= sx*(sy - j)/sy)
                gout << move_to(lx + i, ly + j) << dot;
}
