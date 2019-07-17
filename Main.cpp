#include "Brick.h"
#include "Bar.h"
#include "Ball.h"
#include "Utilities.h"

using namespace std;

#define VK_W 0x57
#define VK_A 0x41
#define VK_S 0x53
#define VK_D 0x44

int menu_idx =  1;
int section = 0;
int main_menu_num = 3;
int maxX, maxY;
int page = 0;
vector<Brick> bricks;
Bar mybar;
Ball myBall;
void showMainMenu() {
    settextstyle(0, HORIZ_DIR, 5);
    outtextxy(40, 100, "Nhom 4 - Pong");
    settextstyle(0, HORIZ_DIR, 3);
    if(menu_idx == 1)
        setcolor(RED);
    else setcolor(WHITE);
    outtextxy(175, 200, "Start Game");
    if(menu_idx == 2)
        setcolor(RED);
    else setcolor(WHITE);
    outtextxy(125, 250,  "Custom setting");
    if(menu_idx == 3)
        setcolor(RED);
    else setcolor(WHITE);
    outtextxy(258, 300, "Exit");
    setcolor(WHITE);
}

void controlMainMenu() {
    while(true) {
        char key = '\0';
        if(kbhit())
            key = getch();
            if(key == 'w' && menu_idx > 1) {
                menu_idx -= 1;
            } else if(key == 's' && menu_idx < main_menu_num) {
                menu_idx += 1;
            } else if(key == ' ') {
                if(menu_idx == 1) {

                } else if(menu_idx == 2) {

                } else if(menu_idx == 3) {
                    break;
                }else {

                }
            }
        showMainMenu();
    }
}

void initBricks() {
    int x1 = 10;
	int x2 = 70;
	int y1 = 35;
	int y2 = 45;

	for(int k=0;k<10;k++)
	{
		for(int i=0;i<5;i++)
		{
			x1 = 25 + (i*4) + (i* 60);
			x2 = 85 + (i*4) + (i* 60);
			y1 = 35 + (k*4) + (k* 10);
			y2 = 45 + (k*4) + (k* 10);
            Brick brick(x1, x2, y1, y2);
			bricks.push_back(brick);
		}
	}
}

void drawBricks() {
    for(int i = 0; i < bricks.size(); i++) {
        if(bricks[i].stillGood()) {
            bricks[i].draw();
        }
    }
}


void drawMap() {
    setcolor(WHITE);
    line(MIN_X,MIN_Y,MIN_X, MAX_Y);
	line(MIN_X,MIN_Y,MAX_X, MIN_Y);
	line(MAX_X,MIN_Y,MAX_X, MAX_Y);
	line(MIN_X,MAX_Y,MAX_X, MAX_Y);
}

int main() {
	int gd = DETECT;
	int gm;
	initgraph(&gd, &gm, "C:\\TC\\BGI");
	//controlMainMenu();
    initBricks();
	//drawBricks();
	//controlMainMenu();
	maxX = getmaxx();
	maxY = getmaxy();
    mybar = Bar(MAX_X*2/20, MAX_X*7/20, MAX_Y - 30 , MAX_Y - 20);
    bool isNotOver = true;
    while(isNotOver) {
        cout << isNotOver << endl;
        setactivepage(page);
        setvisualpage(1-page);
        cleardevice();
        if(kbhit()) {
            if(GetAsyncKeyState(VK_A)) {
                mybar.move(-3);
            } else if(GetAsyncKeyState(VK_D)) {
                mybar.move(3);
            }
        }

        drawBricks();
        myBall.draw();
        mybar.draw();
        myBall.move();
        myBall.checkBrick(bricks, mybar, isNotOver);
        drawMap();
        page = 1 - page;
    }

//	for(int i = 0; i < maxX; i++) {
//        setcolor(GREEN);
//        setfillstyle(SOLID_FILL, GREEN);
//        circle(80 + i, 80, 50);
//        floodfill(80 + i, 80, GREEN);
//        delay(40);
//        cleardevice();
//	}

	getch();
	closegraph();
}
