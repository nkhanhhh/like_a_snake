#include "main_include.h"
#include "map_.h"\


void set_up_window() 
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	window = SDL_CreateWindow("Like a snake", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		max_x, // width
		max_y, // height
		0);

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}


void set_data() 
{
	
	
	
	// create map
	size_wall = 0;
	create_map();

	// snake head
	snake[0] = { 500 , 200 , 10 , 10 };

	// snake body
	size_snake = size_snake_auto;

	// create berries on map
	berry[0] = { 500 , 100 , 10 , 10 };

	// score
	score = 0;

	// setting newgame
	running = true;
	dir = DOWN;
}

