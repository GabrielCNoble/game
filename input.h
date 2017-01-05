#ifndef INPUT_H
#define INPUT_H

#include "SDL2/SDL_keyboard.h"
#include "SDL2/SDL_events.h"



class InputCache
{
		Uint8 *keyboard_state;
	public:
		
		void gatherInput();
		
		int getKeyPressed(int scan_code);
	
};




#endif /* INPUT_H */
