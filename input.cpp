#include "input.h"


		
void InputCache :: gatherInput()
{
	SDL_PollEvent(NULL);
	keyboard_state = (Uint8 *)SDL_GetKeyboardState(NULL);
}
		
int InputCache :: getKeyPressed(int scan_code)
{
	return keyboard_state[scan_code];
}
