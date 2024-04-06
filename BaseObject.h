#pragma once
#include<SDL.h>
#include<SDL_image.h>
#include<string>

using namespace std;

class BaseObject {
public:
	BaseObject();
	~BaseObject();
	void SetRect(const int& x, const int& y) {
		rect_.x = x,
		rect_.y = y,
		rect_.w = 20,
		rect_.h = 20;
	}
	SDL_Rect GetRect() const {
		return rect_;
	}

	virtual bool loadImg(string path, SDL_Renderer* screen);
	void Render(SDL_Renderer* des, const SDL_Rect* clip);
	void Show(SDL_Renderer* des);
	void Free();
protected:
	SDL_Texture* p_object_;
	SDL_Rect rect_;
};
