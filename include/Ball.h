#pragma once

#include "Utilities.h"
#include "Brick.h"
#include "Bar.h"



using namespace std;

class Ball
{
    public:
        Ball();
        Ball(int , int , int ,int);
        void move();
        void inv_x();
        void inv_y();
        void draw();
        void checkBrick(vector<Brick>&, Bar, bool&);
        ~Ball();
    private:
        int x;
        int y;
        int radius;
        int x_direct;
        int y_direct;
};

