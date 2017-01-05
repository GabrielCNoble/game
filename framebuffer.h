#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include <string>

#include "SDL2/SDL_rect.h"
#include "SDL2/SDL_video.h"
#include "SDL2/SDL_render.h"



class Framebuffer
{
		SDL_Window *window;
		SDL_Renderer *renderer;
		
		int width;
		int height;
		char cr;
		char cg;
		char cb;
		char align;
	
	public:
		
		/* Constructor */
		Framebuffer(std :: string name, int width, int height);
		/* Destructor */
		~Framebuffer();
		
		void setRenderDrawColor(char r, char g, char b);
		
		void clearRender();
		
		void swapBuffers();
		
		void drawRectFlat(SDL_Rect *rect, char r, char g, char b);
		
			
};





#endif /* ifndef FRAMEBUFFER_H */

