#include "platform.h"


std :: vector <Platform> platforms;





Platform :: Platform(std :: string name, int x, int y, int w, int h, char r, char g, char b)
{
	this->name = name;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	this->r = r;
	this->g = g;
	this->b = b;
}

Platform :: ~Platform()
{
	
}

void start_platforms()
{
	platforms.clear();
}


void create_platform(std :: string name, int x, int y, int w, int h, char r, char g, char b)
{
	Platform p(name, x, y, w, h, r, g, b);
	platforms.push_back(p);
}


void destroy_platform(std :: string name)
{
	std :: vector <Platform> :: iterator it = platforms.begin();
	for(;it != platforms.end(); it++)
	{
		if(it->name == name)
		{
			platforms.erase(it);
			break;
		}
	}	
}

void draw_platforms(Framebuffer *framebuffer)
{
	int i;
	int c = platforms.size();
	
	for(i = 0; i < c; i++)
	{
		framebuffer->drawRectFlat(&platforms[i].rect, platforms[i].r, platforms[i].g, platforms[i].b);
	}
}










