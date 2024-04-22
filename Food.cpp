#include "Food.h"
#include "main_include.h"


void create_food() 
{
	int x, y;
	srand(time(NULL));
re_check:
	x = rand() % (760 - 20 + 1 ) + 20;
	y = rand() % (500 - 20 + 1 ) + 20;
	if (x % 20 == 0 && y % 20 == 0) 
	{
		for (int i = 0; i < size_snake; i++) 
		{
			if (x == snake[i].x && y == snake[i].y) 
			{
				goto re_check;
			}
		}
		berry[0] = { x , y , 10 , 10 };
	}
	else 
	{
		goto re_check;
	}
}

	void draw_food() 
	{
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &berry[0]);
	}
