#include "Snake.h"
#include "main_include.h"

void move() {
	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			running = false;
		}
		if ((event.key.keysym.sym == 's') && dir != UP) {
			dir = DOWN;
		}
		if (event.key.keysym.sym == 'w' && dir != DOWN) {
			dir = UP;
		}
		if (event.key.keysym.sym == 'a' && dir != RIGHT) {
			dir = LEFT;
		}
		if (event.key.keysym.sym == 'd' && dir != LEFT) {
			dir = RIGHT;
		}
	}

	switch (dir) {
	case DOWN:
		for (int i = size_snake; i > 0; i--) {
			snake[i] = snake[i - 1];
		}
		snake[0].y += 20;
		break;

	case UP:
		for (int i = size_snake; i > 0; i--) {
			snake[i] = snake[i - 1];
		}
		snake[0].y -= 20;
		break;

	case LEFT:
		for (int i = size_snake; i > 0; i--) {
			snake[i] = snake[i - 1];
		}
		snake[0].x -= 20;
		break;

	case RIGHT:
		for (int i = size_snake; i > 0; i--) {
			snake[i] = snake[i - 1];
		}
		snake[0].x += 20;
		break;
	}
}

void draw_snake() {
	for (int i = 0; i < size_snake; i++) {
		if (i == 0) {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(renderer, &snake[0]);
		}
		else {
			SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
			SDL_RenderFillRect(renderer, &snake[i]);
		}
	}
}

void eat() {
	size_snake++;
	score += 10;
}