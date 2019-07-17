#pragma once
#include <windows.h>
#include <conio.h>
#include <vector>
#include <iostream>

#include "graphics.h"



static int score = 0;

//Kich thuoc map
static const int MIN_X = 3;
static const int MAX_X = 366;
static const int MIN_Y = 30;
static const int MAX_Y = 460;

//Khai bao xong quen mat de lam gi :)). Hinh nhu chua dung
static const int D_UP = -1;
static const int D_LEFT = -1;
static const int D_RIGHT = 1;
static const int D_DOWN = 1;

//Ball
static const int BALL_SPEED = 1;
static const int BALL_X = 200;
static const int BALL_Y = 300;
static const int BALL_R = 8;

