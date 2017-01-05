#include "sound.h"


Sound :: Sound()
{
	used_channel = -1;
}

Sound :: Sound(std :: string name, int b_load_data)
{
	this->name = name;
	if(b_load_data)
	{
		
	}

	used_channel = -1;
}
Sound :: Sound(Mix_Chunk *sound_data, std :: string name)
{
	this->name = name;
	this->sound_data = *sound_data;
	used_channel = -1;
}
		
void Sound :: setSoundData(Mix_Chunk *sound_data)
{
	this->sound_data = *sound_data;
}

void Sound :: play(int b_loop)
{
	used_channel = (-1, sound_data, b_loop);
}

void Sound :: pause()
{
	Mix_Pause(used_channel);
}

void Sound :: resume()
{
	Mix_Resume(used_channel);
}

void Sound :: stop()
{
	Mix_HaltChannel(used_channel);
}

void Sound :: setVolume(int volume)
{
	Mix_VolumeChunk(&sound_data, volume);
	this->volume = volume;
}























