#include "Bar.h"


Bar::Bar() {

}

Bar::Bar(int sx, int ex, int sy, int ey)
{
    this->start_x = sx;
    this->end_x = ex;
    this->start_y = sy;
    this->end_y = ey;
}

void Bar::move(int speed) {
    if(start_x + speed > MIN_X && end_x + speed < MAX_X) {
        start_x += speed;
        end_x   += speed;
    }
}

int Bar::getStartX() {
    return this->start_x;
}

int Bar::getStartY() {
    return this->start_y;
}
int Bar::getEndX() {
    return this->end_x;
}
int Bar::getEndY() {
    return this->end_y;
}

void Bar::draw() {
    setcolor(WHITE);
    setfillstyle(SOLID_FILL, WHITE);
    bar(start_x, start_y, end_x, end_y);
    floodfill(start_x + 1, start_y + 1, WHITE);
}
Bar::~Bar()
{
    //dtor
}
