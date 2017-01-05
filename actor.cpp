#include "actor.h"
#include <iostream>
#include "platform.h"
#include "camera.h"



#define GRAVITY 0.9
#define MOVE_SPEED 1.0
#define MAX_SPEED 18.0
#define AIR_FRICTION 0.99
#define GROUND_FRICTION 0.92
#define JUMP_SPEED 20.0

std :: vector <Actor> actors;

extern std :: vector <Platform> platforms;

int player_index=-1;

Actor :: Actor(std :: string name, int x, int y, int w, int h, char r, char g, char b, int type, float life)
{
	this->name = name;
	this->r=r;
	this->g=g;
	this->b=b;
	this->x=x;
	this->y=y;
	this->type = type;
	this->life = life;
	rect.x = x;
	rect.y = y;
	rect.w = w;
	rect.h = h;
	dx = 0.0;
	dy = 0.0;
	bm_state = ACTOR_IDLE;
}


Actor :: ~Actor()
{
	
}

void start_actors()
{
	actors.clear();
}


void create_actor(std :: string name, int x, int y, int w, int h, char r, char g, char b, int type, float life)
{
	if(type != ACTOR_PLAYER) actors.push_back(Actor(name, x, y, w, h, r, g, b, type, life));
	else if(player_index == -1)
	{
		player_index=actors.size();
		actors.push_back(Actor(name, x, y, w, h, r, g, b, type, life));
	}
	else
	{
		std :: cout << "player already exists!!" << std :: endl;
	}
}


void create_player(std :: string name, int x, int y)
{
	create_actor(name, x, y, 40, 40, 255, 0, 0, ACTOR_PLAYER, 100.0);
}

void create_monster(std ::string name, int x, int y, int monster_type)
{
	if(monster_type != ACTOR_PLAYER)
	{
		switch(monster_type)
		{
			case ACTOR_MONSTER1:
				create_actor(name, x, y, 40, 20, 0, 255, 0, ACTOR_MONSTER1, 50.0);
			break;
			
			case ACTOR_MONSTER2:
				create_actor(name, x, y, 40, 60, 0, 0, 255, ACTOR_MONSTER2, 150.0);
			break;
		}
		
	}
	else
	{
		std :: cout << "player is not a monster!" << std :: endl;
	}
	
}


void destroy_actor(std :: string name)
{
	std :: vector <Actor> :: iterator it = actors.begin();
	for(;it != actors.end(); it++)
	{
		if(it->name == name)
		{
			actors.erase(it);
			break;
		}
	}	
}

void get_player_input(InputCache *input)
{
	char up = input->getKeyPressed(SDL_SCANCODE_UP);
	char left = input->getKeyPressed(SDL_SCANCODE_LEFT);
	char right = input->getKeyPressed(SDL_SCANCODE_RIGHT);
	
	
	if(actors[player_index].bm_state&ACTOR_JUMPED)
	{
		actors[player_index].bm_state &= ~ACTOR_JUMPED;
	}
	if(left)
	{
		actors[player_index].bm_state &= ~(ACTOR_IDLE|ACTOR_MOVING_RIGHT);
		actors[player_index].bm_state |= ACTOR_MOVING_LEFT;
	}
	else
	{
		actors[player_index].bm_state &= ~ACTOR_MOVING_LEFT;
	}
	if(right)
	{
		actors[player_index].bm_state &= ~(ACTOR_IDLE|ACTOR_MOVING_LEFT);
		actors[player_index].bm_state |= ACTOR_MOVING_RIGHT;
	}
	else
	{
		actors[player_index].bm_state &= ~ACTOR_MOVING_RIGHT;
	}
	if(up && !(actors[player_index].bm_state&ACTOR_FLYING))
	{
		actors[player_index].bm_state &= ~ACTOR_IDLE;
		actors[player_index].bm_state |= ACTOR_JUMPED;
	}
	else if(!(up || left || right || (actors[player_index].bm_state&ACTOR_FLYING)))
	{
		actors[player_index].bm_state = ACTOR_IDLE;
	}
	
}



void process_actors()
{
	int i;
	int c = actors.size();
	int j;
	int k = platforms.size();
	int l;
	
	Camera *active_camera = get_active_camera();
	
	for(i = 0; i<c; i++)
	{
		
		if(!(actors[i].bm_state&ACTOR_IDLE))
		{
			if(actors[i].bm_state&ACTOR_MOVING_LEFT)
			{
				actors[i].dx -= MOVE_SPEED;
				if(actors[i].dx < -MAX_SPEED) actors[i].dx = -MAX_SPEED; 
			}
			if(actors[i].bm_state&ACTOR_MOVING_RIGHT)
			{
				actors[i].dx += MOVE_SPEED;
				if(actors[i].dx > MAX_SPEED) actors[i].dx = MAX_SPEED; 
			}
			
			if(actors[i].bm_state&ACTOR_JUMPED && !(actors[i].bm_state&ACTOR_FLYING))
			{
				actors[i].dy = -JUMP_SPEED;
				actors[i].bm_state |= ACTOR_FLYING;
			}
			
		}
		
		actors[i].y += actors[i].dy;
		actors[i].x += actors[i].dx;
		
		
		if(fabs(actors[i].dy) > 2.0 * MOVE_SPEED)
		{
			actors[i].bm_state |= ACTOR_FLYING;
		}
		
		/* actor-platform collision */
		for(j = 0; j < k; j++)
		{
			if((int)actors[i].x < platforms[j].rect.x + platforms[j].rect.w && 
			   (int)actors[i].x + actors[i].rect.w > platforms[j].rect.x)
			{
			   	if((int)actors[i].y + actors[i].rect.h > platforms[j].rect.y && 
				   (int)actors[i].y +actors[i].rect.h < platforms[j].rect.y + platforms[j].rect.h)
				{
					actors[i].y = platforms[j].rect.y - actors[i].rect.h;
					actors[i].dy = 0.0;
					actors[i].bm_state &= ~ACTOR_FLYING;
				}
				
				else if((int)actors[i].y < platforms[j].rect.y + platforms[j].rect.h && 
						(int)actors[i].y + actors[i].rect.h > platforms[j].rect.y + platforms[j].rect.h)
				{
					actors[i].y = platforms[j].rect.y + platforms[j].rect.h;
					actors[i].dy = 0.0;
				}
			}
			
			if((int)actors[i].y+actors[i].rect.h>600)
			{
				actors[i].y = 600 - actors[i].rect.h;
				actors[i].dy = 0.0;
				actors[i].bm_state &= ~ACTOR_FLYING;
			}
			
		}
		
		/* actor-actor collision */
		for(l = 0; l < c; l++)
		{
			if(l == i) continue;
			
			if(actors[i].rect.x + actors[i].rect.w > actors[l].rect.x &&
			   actors[i].rect.x < actors[l].rect.x)
			{
				if(actors[i].rect.y + actors[i].rect.h > actors[l].rect.y &&
				   actors[i].rect.y < actors[l].rect.y + actors[l].rect.h)
				{
					actors[i].x = actors[l].rect.x - actors[i].rect.w;
					actors[i].dx = 0.0; 	
				}
				  	
			}
			
			else if(actors[i].rect.x < actors[l].rect.x + actors[l].rect.w &&
			   		actors[i].rect.x + actors[i].rect.w > actors[l].rect.x + actors[l].rect.w)
			{
				if(actors[i].rect.y + actors[i].rect.h > actors[l].rect.y &&
				   actors[i].rect.y < actors[l].rect.y + actors[l].rect.h)
				{
					actors[i].x = actors[l].rect.x + actors[l].rect.w;
					actors[i].dx = 0.0; 	
				}
			}
			
		}
		
		actors[i].dy += GRAVITY;
		if(actors[i].bm_state & ACTOR_FLYING)
		{
			actors[i].dx *= AIR_FRICTION;
		}
		else
		{
			actors[i].dx *= GROUND_FRICTION;
		}
		
		actors[i].rect.x = (int) actors[i].x;
		actors[i].rect.y = (int) actors[i].y;
		
		switch(actors[i].type)
		{
			case ACTOR_PLAYER:
			
			break;
			
			case ACTOR_MONSTER1:
				
				if(actors[player_index].rect.y < actors[i].rect.y)
				{
					actors[i].bm_state &= ~ACTOR_IDLE;
					actors[i].bm_state |= ACTOR_JUMPED;
				}
				else
				{
					actors[i].bm_state |= ACTOR_IDLE;
					actors[i].bm_state &= ~ACTOR_JUMPED;
				}
			break;
			
			case ACTOR_MONSTER2:
				
				if(actors[player_index].rect.y < actors[i].rect.y)
				{
					actors[i].bm_state &= ~ACTOR_IDLE;
					actors[i].bm_state |= ACTOR_JUMPED;
				}
				else
				{
					actors[i].bm_state |= ACTOR_IDLE;
					actors[i].bm_state &= ~ACTOR_JUMPED;
				}
				
				if(actors[player_index].rect.x + actors[player_index].rect.w < actors[i].rect.x-10)
				{
					actors[i].bm_state &= ~ACTOR_IDLE;
					actors[i].bm_state |= ACTOR_MOVING_LEFT;
					actors[i].bm_state &= ~ACTOR_MOVING_RIGHT;
				}
				else if(actors[player_index].rect.x > actors[i].rect.x + actors[i].rect.w + 10)
				{
					actors[i].bm_state &= ~ACTOR_IDLE;
					actors[i].bm_state |= ACTOR_MOVING_RIGHT;
					actors[i].bm_state &= ~ACTOR_MOVING_LEFT;
				}
				else
				{
					actors[i].bm_state &= ~(ACTOR_MOVING_RIGHT|ACTOR_MOVING_LEFT);
					actors[i].bm_state |= ACTOR_IDLE;
				}
			break;
		}
		
	}
	
	move_camera_to(active_camera, actors[player_index].x, actors[player_index].y, 1);
	
}




void draw_actors(Framebuffer *framebuffer)
{
	int i;
	int c=actors.size();
	for(i=0; i<c; i++)
	{
		framebuffer->drawRectFlat(&actors[i].rect, actors[i].r, actors[i].g, actors[i].b);
	}
}
















