#include "Ball.h"
Ball::Ball()
{
    this->x = BALL_X;
    this->y = BALL_Y;
    this->radius = BALL_R;
    x_direct = 1;
    y_direct = -1;
}

Ball::Ball(int x, int y, int r, int speed = BALL_SPEED)
{
    this->x = x;
    this->y = y;
    this->radius = r;
    x_direct = speed;
    y_direct = speed;
}
void Ball::move() {
    x += x_direct;
    y += y_direct;
}

void Ball::inv_x() {
    x_direct *= -1;
}
void Ball::inv_y() {
    y_direct *= -1;
}

void Ball::checkBrick(vector<Brick>& bricks, Bar mbar, bool& isNotOver) {
    bool isNotHit = true;
    for(int i = 0; i < bricks.size(); i++) {
        if(bricks[i].stillGood() && x >= bricks[i].getStartX() && x <= bricks[i].getEndX()
           && y + radius >= bricks[i].getStartY()
           && y - radius <= bricks[i].getEndY()) {

            isNotHit = false;
            bricks[i].setStatus(false);
            score++;
            break;
        }
    }
    if(isNotHit) {
        if(x - radius <= MIN_X && y - radius >= MIN_Y && y - radius <= MAX_Y) {
            x_direct *= -1;

        }
        if(x + radius >= MAX_X && y - radius >= MIN_Y && y - radius <= MAX_Y) {
            x_direct *= - 1;
        }
        if(y - radius <= MIN_Y && x - radius >= MIN_X && x - radius <= MAX_X) {
            y_direct *= -1;
        }
        if(y + radius >= mbar.getStartY() && y - radius <=  mbar.getEndY()) {
            if(x + radius >= mbar.getStartX() && x - radius <= mbar.getEndX()) {
                y_direct *= -1;
            } else {
                isNotOver = false;
            }
        }
    } else {
        y_direct *= -1;
    }
}

void Ball::draw() {
    setcolor(GREEN);
    setfillstyle(SOLID_FILL, LIGHTGREEN);
    circle(x, y , radius);
    floodfill(x + 1, y + 1, GREEN);
}
Ball::~Ball()
{
    //dtor
}
