#include "BaseObject.h"
#include "main_include.h"
#include "setting_SDL2.h"
#include "Menu.h"
#include "Texture.h"
#include "Food.h"
#include "Snake.h"
#undef main
using namespace std;

int dir, size_snake, size_wall;
bool running;
UINT32 score;
SDL_Renderer* renderer;
SDL_Window* window;
SDL_Event event;
SDL_Rect berry[50], snake[100], wall[1000];
BaseObject g_background, g_food, g_wall;

void main() {
RESTART:
	set_data();
	bool test;

	test = g_background.loadImg("pics/backgrounds_in_game.png", renderer);
	if (test == false) {
		cout << "Can't load background!/n";
		return;
	}

	test = g_food.loadImg("pics/berry.png", renderer);
	if (test == false) {
		cout << "Can't load food!\n";
		return;
	}

	test = g_wall.loadImg("pics/wall.png", renderer);
	if (test == false) {
		cout << "Can't load wall!\n";
		return;
	}

	while (running) {
		move();
		if (snake[0].x == berry[0].x && snake[0].y == berry[0].y) {
			eat();
			create_food();
		}
		for (int i = 0; i < size_wall; i++) {
			if (snake[0].x == wall[i].x && snake[0].y == wall[i].y) {
				int ret_menu = ShowMenu(renderer, "Play again", "Exit", "pics/background_KO.png");
				switch (ret_menu) {
				case 1:
					goto EXIT;
				case 0:
					goto RESTART;
				}
			}
		}
		for (int i = 4; i < size_snake; i++) {
			if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
				int ret_menu = ShowMenu(renderer, "Play again", "Exit", "pics/background_KO.png");
				switch (ret_menu) {
				case 1:
					goto EXIT;
				case 0:
					goto RESTART;
				}
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		g_background.Render(renderer, NULL);

		draw_snake();
		g_food.SetRect(berry[0].x, berry[0].y);
		g_food.Render(renderer, NULL);

		for (int i = 0; i < size_wall; i++) {
			g_wall.SetRect(wall[i].x, wall[i].y);
			g_wall.Render(renderer, NULL);
		}

		string text = "Score:";
		string point = to_string(score);
		text += point;
		draw_textchange(text.c_str(), 560, 560);

		SDL_RenderPresent(renderer);
		SDL_Delay(100);
	}

EXIT:
	return;
}