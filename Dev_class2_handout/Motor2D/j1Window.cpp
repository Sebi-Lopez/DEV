#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Window.h"

#include "SDL/include/SDL.h"


j1Window::j1Window() : j1Module()
{
	window = NULL;
	screen_surface = NULL;
	name.create("window");
}

// Destructor
j1Window::~j1Window()
{
}

// Called before render is available
bool j1Window::Awake(pugi::xml_node& config)
{
	LOG("Init SDL window & surface");
	bool ret = true;

	if(SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		LOG("SDL_VIDEO could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	else
	{
		//Create window
		Uint32 flags = SDL_WINDOW_SHOWN;

		width = App->node_document.child("Window").child("WIDTH").attribute("width").as_uint();
		height = App->node_document.child("Window").child("HEIGHT").attribute("height").as_uint();
		scale = App->node_document.child("Window").child("SCALE").attribute("scale").as_uint();

		if (App->node_document.child("Window").child("FULLSCREEN").attribute("fullscreen").as_bool())
		{
			flags |= SDL_WINDOW_FULLSCREEN;
		}

		if(App->node_document.child("Window").child("BORDERLESS").attribute("borderless").as_bool())
		{
			flags |= SDL_WINDOW_BORDERLESS;
		}

		if(App->node_document.child("Window").child("RESIZABLE").attribute("resizable").as_bool())
		{
			flags |= SDL_WINDOW_RESIZABLE;
		}

		if(App->node_document.child("Window").child("FULLSCREEN_WINDOW").attribute("fullscreen_window").as_bool())
		{
			flags |= SDL_WINDOW_FULLSCREEN_DESKTOP;
		}

		window = SDL_CreateWindow(App->node_document.child("Window").child_value("TITLE"), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, flags);

		if (window == NULL)
		{
			LOG("Window could not be created! SDL_Error: %s\n", SDL_GetError());
			ret = false;
		}
		else
		{
			//Get window surface
			screen_surface = SDL_GetWindowSurface(window);

			// TODO 4: Read the title of the app from the XML
			// and set directly the window title using SetTitle()
			SetTitle(App->node_document.child_value("name"));
		}
	}

	return ret;
}

// Called before quitting
bool j1Window::CleanUp()
{
	LOG("Destroying SDL window and quitting all SDL systems");

	//Destroy window
	if(window != NULL)
	{
		SDL_DestroyWindow(window);
	}

	//Quit SDL subsystems
	SDL_Quit();
	return true;
}

// Set new window title
void j1Window::SetTitle(const char* new_title)
{
	//title.create(new_title);
	SDL_SetWindowTitle(window, new_title);
}

void j1Window::GetWindowSize(uint& width, uint& height) const
{
	width = this->width;
	height = this->height;
}

uint j1Window::GetScale() const
{
	return scale;
}