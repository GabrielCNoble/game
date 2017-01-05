#include "camera.h"
#include "actor.h"

std :: vector <Camera> cameras;

int active_camera_index = -1;


Camera :: Camera(std :: string name, int x, int y, int index)
{
	this->x = x;
	this->y = y;
	this->camera_index = index;
	this->name = name;
}

Camera :: ~Camera()
{
	
}

void Camera :: setAsActive()
{
	active_camera_index = camera_index;
}

void start_cameras()
{
	cameras.clear();
}

void create_camera(std :: string name, int x, int y, int b_set_as_active)
{
	Camera c(name, x, y, cameras.size());
	cameras.push_back(c);
	
	if(b_set_as_active)
	{
		cameras[cameras.size()-1].setAsActive();
	}
	
}

void destroy_camera(std :: string name)
{
	std :: vector <Camera> :: iterator it = cameras.begin();
	for(;it != cameras.end(); it++)
	{
		if(it->name == name)
		{
			cameras.erase(it);
			break;
		}
	}
}

void move_camera_to(Camera *camera, int x, int y, int b_smooth)
{
	
	if(b_smooth)
	{
		camera->x += (x - 400 - camera->x)*0.06;
		camera->y += (y - 300 - camera->y)*0.06;
	}
	else
	{
		camera->x = x-400;
		camera->y = y-300;
	}
}

Camera *get_camera(std :: string name)
{
	std :: vector <Camera> :: iterator it = cameras.begin();
	for(;it != cameras.end(); it++)
	{
		if(it->name == name)
		{
			return &cameras[it->camera_index];
		}
	}
}

Camera *get_active_camera()
{
	return &cameras[active_camera_index];
}













