#pragma once
#include "Utilities.h"
class Bar
{
    public:
        Bar();
        Bar(int sx, int ex, int sy, int ey);
        void move(int);
        int getStartX();
        int getStartY();
        int getEndX();
        int getEndY();
        ~Bar();
        void draw();
    private:
        int start_x, end_x, start_y, end_y;
};
