#ifndef SOUND_H
#define SOUND_H

#include <string>
#include "SDL2/SDL_mixer.h"


class Sound
{
	public:
		Mix_Chunk sound_data;
		std :: string name;
		int used_channel;
		int volume;
		
		Sound();
		Sound(std :: string name, int b_load_data);
		Sound(Mix_Chunk *sound_data, std :: string name);
		
		void setSoundData(Mix_Chunk *sound_data);
		void play(int b_loop);
		void pause();
		void resume();
		void stop();
		void setVolume(int volume);
};



#endif /* SOUND_H */
