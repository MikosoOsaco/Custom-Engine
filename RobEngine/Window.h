#pragma once
#include <string>
#include "SDL\SDL2-2.0.4\include\SDL.h"
#include "SDL\SDL2_image-2.0.1\include\SDL_image.h"
#include <iostream>

class Window
{
public:
	//create windows
	Window();
	Window(const std::string &title, int width, int height);
	//destroy window
	~Window();

	void SetAttributes();
	SDL_Window* getWindow() const;

	//window event
	SDL_Event event;
	void pollEvents();
	void clear() const;

	//check if window is closed
	inline bool isClosed() const { return windowClosed; }

private:
	int width; //window width
	int height; //window height
	std::string title; //window title

	bool windowClosed; //is window closed

	bool init(); //private init everything
	SDL_Window *window = nullptr;
	SDL_GLContext  SDLGLContext;



protected:
	SDL_Renderer *renderer = nullptr;
};