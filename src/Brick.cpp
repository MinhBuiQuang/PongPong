#include "Brick.h"

Brick::Brick(int sx, int ex, int sy, int ey)
{
    this->start_x = sx;
    this->end_x = ex;
    this->start_y = sy;
    this->end_y = ey;
    this->isNotBroken = true;
}

void Brick::draw() {
    setcolor(RED);
    setfillstyle(SOLID_FILL, YELLOW);
    rectangle(start_x, start_y, end_x, end_y);
    floodfill(start_x + 1, start_y + 1, RED);
}

int Brick::getStartX() {
    return this->start_x;
}

int Brick::getStartY() {
    return this->start_y;
}
int Brick::getEndX() {
    return this->end_x;
}
int Brick::getEndY() {
    return this->end_y;
}

Brick::~Brick()
{
    //dtor
}
