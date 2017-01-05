#ifndef CAMERA_H
#define CAMERA_H

#include <string>
#include <vector>

class Camera
{
	public:
		
	int x;
	int y;
	int camera_index;
	std :: string name;
	
	Camera(std ::string name, int x, int y, int index);
	~Camera();
	
	void setAsActive();
	
};


void start_cameras();

void create_camera(std :: string name, int x, int y, int b_set_as_active);

void destroy_camera(std :: string name);

void move_camera_to(Camera *camera, int x, int y, int b_smooth);

Camera *get_camera(std :: string name);

Camera *get_active_camera();



#endif /* ifndef CAMERA_H */
