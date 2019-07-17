#pragma once
#include<graphics.h>
class Brick
{
    public:
        Brick(int sx, int ex, int sy, int ey);
        void draw();
        void setStatus(bool status) {
            this->isNotBroken = status;
        }
        bool stillGood() {
            return this->isNotBroken;
        }
        int getStartX();
        int getStartY();
        int getEndX();
        int getEndY();
        ~Brick();
    private:
        int start_x, end_x, start_y, end_y;
        bool isNotBroken;
};
