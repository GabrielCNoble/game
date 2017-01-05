#include "framebuffer.h"
#include "camera.h"

extern std :: vector <Camera> cameras;
extern int active_camera_index;

Framebuffer :: Framebuffer(std :: string name, int width, int height)
{

	window=SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, 0);
	renderer=SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
	this->width=width;
	this->height=height;
	return;
	
}

Framebuffer :: ~Framebuffer()
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	return;
}

void Framebuffer :: setRenderDrawColor(char r, char g, char b)
{
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	cr=r;
	cg=g;
	cb=b;
}
		
void Framebuffer :: clearRender()
{
	SDL_RenderClear(renderer);
}
		
void Framebuffer :: swapBuffers()
{
	SDL_RenderPresent(renderer);
}

void Framebuffer :: drawRectFlat(SDL_Rect *rect, char r, char g, char b)
{
	SDL_Rect rc = *rect;
	
	rc.x -= cameras[active_camera_index].x;
	rc.y -= cameras[active_camera_index].y;
	
	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderFillRect(renderer, &rc);
	SDL_SetRenderDrawColor(renderer, cr, cg, cb, 255);
}



















