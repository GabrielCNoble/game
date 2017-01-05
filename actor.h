#ifndef ACTOR_H
#define ACTOR_H

#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include "input.h"
#include "framebuffer.h"

#include "SDL2/SDL_rect.h"

enum ACTOR_STATES
{
	ACTOR_IDLE = 1,
	ACTOR_FLYING = 2,
	ACTOR_JUMPED = 4,
	ACTOR_MOVING_LEFT=8,
	ACTOR_MOVING_RIGHT=16,
	ACTOR_JUST_LANDED=32
};

enum ACTOR_TYPE
{
	ACTOR_PLAYER=1,
	ACTOR_MONSTER1=2,
	ACTOR_MONSTER2=3
};

class Actor
{
	
	public:
		
		std :: string name;
		SDL_Rect rect;
		float x;
		float y;
		float dx;
		float dy;
		int bm_state;
		int type;
		
		float life;
		int timer1;
		int timer2;
		
		char r;
		char g;
		char b;
		char align;
	
		Actor(std :: string name, int x, int y, int w, int h, char r, char g, char b, int type, float life);
		~Actor();
	
};

void start_actors();

void end_actors();

void create_actor(std :: string name, int x, int y, int w, int h, char r, char g, char b, int type, float life);

void create_player(std :: string name, int x, int y);

void create_monster(std ::string name, int x, int y, int monster_type);

void destroy_actor(std :: string name);

void get_player_input(InputCache *input);

void process_actors();

void draw_actors(Framebuffer *framebuffer);

#endif /* ifndef ACTOR_H */
















