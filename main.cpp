#include "main.h"



int main(int argc, char **argv) 
{
	if(SDL_Init(SDL_INIT_EVERYTHING)<0)
	{
		std :: cout << "failed to start SDL\n";
		return -1;
	}
	
	Mix_Init(MIX_INIT_FLAC | MIX_INIT_MOD | MIX_INIT_MP3 | MIX_INIT_OGG);
	
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 1, 4096);
	
	SDL_Rect r;
	
	r.h=100;
	r.w=100;
	r.x=400;
	r.y=200;

	Framebuffer fb("game", 800, 600);
	fb.setRenderDrawColor(0, 0, 0);
	InputCache input;
	
	
	
	start_actors();
	start_platforms();
	start_cameras();
	
	//create_actor("actor", 400, 200, 50, 50, 255, 0, 0, true);
	create_platform("platform", 400, 400, 100, 50, 255, 255, 255);
	create_platform("platform", 600, 300, 100, 50, 255, 255, 255);
	create_platform("platform", 800, 200, 100, 50, 255, 255, 255);
	//create_actor("actor2", 470, 150, 50, 50, 0, 255, 0, false);
	create_player("player", 800, 150);
	
	for(int i = 0; i<20; i++)
	{
		create_monster("monster" + i, 470 + 200*i, 250, ACTOR_MONSTER2);
	}
	/*create_monster("monster", 470, 250, ACTOR_MONSTER2);
	create_monster("monster2", 570, 250, ACTOR_MONSTER2);
	create_monster("monster3", 770, 250, ACTOR_MONSTER2);
	create_monster("monster4", 970, 250, ACTOR_MONSTER2);
	create_monster("monster5", 1170, 250, ACTOR_MONSTER2);
	create_monster("monster6", 1370, 250, ACTOR_MONSTER2);
	create_monster("monster7", 1570, 250, ACTOR_MONSTER2);
	create_monster("monster7", 1770, 250, ACTOR_MONSTER2);
	create_monster("monster7", 1970, 250, ACTOR_MONSTER2);*/
	create_camera("camera", 0, 0, 1);
	
	for(int i = 0; i<20; i++)
	{
		create_platform("platform", 900 + i*100, 200, 100, 50, 255, 255, 255);
	}
	
	for(int i = 0; i<20; i++)
	{
		create_platform("platform", 3000 + i*100, 600 - i*20, 100, 50, 255, 255, 255);
	}
	
	for(int i = 0; i<20; i++)
	{
		create_platform("platform", 5000 + i*100, 200, 100, 50, 255, 255, 255);
	}
	
	do
	{
		input.gatherInput();
		fb.clearRender();

		get_player_input(&input);
		process_actors();
		draw_actors(&fb);
		draw_platforms(&fb);
		fb.swapBuffers();
		
	}while(!input.getKeyPressed(SDL_SCANCODE_ESCAPE));
	

	return 0;
}









