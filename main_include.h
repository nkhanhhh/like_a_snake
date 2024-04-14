#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<iostream>
#include<algorithm>
#include<string>
#include "BaseObject.h"
#include<SDL_ttf.h>
#include<SDL_video.h>
#include<SDL_render.h>
#include<SDL_pixels.h>
#include<SDL_mixer.h>
#include<Windows.h>

extern BaseObject g_background;
extern SDL_Renderer* renderer;
extern SDL_Window* window;
extern SDL_Event event;

extern SDL_Renderer* rd_food;
extern SDL_Rect berry[50];

extern SDL_Rect snake[100];
extern SDL_Renderer* rd_snake;
extern UINT32 score;

extern SDL_Rect wall[1000];

extern int dir;
extern bool running;
const int min_ = 0;
const int max_x = 800;
const int max_y = 600;
extern int size_snake;
extern int size_wall;

#define size_snake_auto 2

enum Direction 
{
	UP, DOWN, LEFT, RIGHT
};