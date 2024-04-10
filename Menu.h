#pragma once
#include<iostream>
#include "main_include.h"

#ifndef  TEXT_OBJECT_H
#define TEXT_OBJECT_H


int ShowMenu(SDL_Renderer* g_screen,
	const string& menu1,
	const string& menu2,
	const string& img_name);

class TextObject {
private:
	string str_val;
	SDL_Color text_color;
	SDL_Texture* texture_;
	int width;
	int height;
public:
	TextObject();
	~TextObject();

	enum TextColor {
		RED_TEXT = 0,
		WHITE_TEXT = 1,
		BLACK_TEXT = 2,
	};

	bool loadFromRendererText(TTF_Font* gFont, SDL_Renderer* screen);
	void Free();

	void setColor(Uint32 red, Uint32 green, Uint32 blue);
	void setColor(int type);

	void RenderText(SDL_Renderer* screen, int x, int y);

	int getWidth() const {
		return width;
	}
	int getHeight() const {
		return height;
	}

	void SetText(const string& text) {
		str_val = text;
	}
	string GetText() const {
		return str_val;
	}
};

#endif 
