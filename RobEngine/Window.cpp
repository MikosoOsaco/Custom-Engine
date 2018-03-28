#include "Window.h"

Window::Window(const std::string &title, int width, int height) :
	title(title), width(width), height(height) //set parameters to our local variables
{
	windowClosed = false; //closed is false

	if (!init()) //if init doesnt work, close window
	{
		windowClosed = true;
	}
}

Window::Window()
{
	//default values
	width = 800;
	height = 600;
	title = "no title";
	windowClosed = false; //closed is false

	if (!init()) //if init doesnt work, close window
	{
		windowClosed = true;
	}
}

Window::~Window()
{
	//close everything
	windowClosed = true;
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_GL_DeleteContext(SDLGLContext);
	//IMG_Quit();
	SDL_Quit();
}

bool Window::init()
{
	//error checks as we initialize
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		std::cerr << "Failed to init SDL\n";
		return false;
	}

	int imgTypes = IMG_INIT_JPG | IMG_INIT_PNG | IMG_INIT_TIF | IMG_INIT_WEBP;
	if (!(IMG_Init(imgTypes)) & imgTypes)
	{
		std::cerr << "Failed to init SDL_IMAGE\n";
		return false;
	}

	window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height,SDL_WINDOW_OPENGL);

	if (window == nullptr)
	{
		std::cerr << "Failed to create window!\n";
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr)
	{
		std::cerr << "Failed to create renderer\n";
		return false;
	}

	//Create an SDL/GL context
	//Pass in the window you created above to bind it to the context
	SDLGLContext = SDL_GL_CreateContext(window);

	//Set the Attributes that will be used within the window
	SetAttributes();


	//if everything worked, return true
	return true;
}

void Window::SetAttributes() {

	//Ignore any depricated functions
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	//Set up the version of OpenGL that will be used (3.3 covers MOST computers)
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
	//Creates a double buffer within the game
	//This allows one surface to render in the background
	//The buffers then swap when the back on is filled,
	//and the process repeats
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	//This sets up the depth buffer
	//This will help the GPU determine which objects are in front of others (perspective)
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 32);

}

SDL_Window* Window::getWindow() const {
	return window;
}

void Window::pollEvents()
{
	while (SDL_PollEvent(&event))
	{
		//check for window events
		switch (event.type)
		{
		case SDL_QUIT:
			//close window if X is pressed
			windowClosed = true;
			break;

		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
				//close window if escape is pressed
			case SDLK_ESCAPE:
				windowClosed = true;
				break;
			}
			break;

		default:
			break;
		}
	}
}

void Window::clear() const
{
	//SDL_RenderPresent(renderer);	//puts renderer to screen

	//SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	//SDL_RenderClear(renderer);		//puts color on renderer
}