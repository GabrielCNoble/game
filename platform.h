#ifndef PLATFORM_H
#define PLATFORM_H

#include <string>
#include <vector>
#include "SDL2/SDL_rect.h"
#include "framebuffer.h"

class Platform
{
	public:
		SDL_Rect rect;
		std :: string name;
		char r;
		char g;
		char b;
		char a;
		
		Platform(std :: string name, int x, int y, int w, int h, char r, char g, char b);
		~Platform();
};

void start_platforms();

void create_platform(std :: string name, int x, int y, int w, int h, char r, char g, char b);

void destroy_platform(std :: string name);

void draw_platforms(Framebuffer *framebuffer);


#endif /* ifndef PLATFORM_H */
