#include "Camera.h"


Camera::Camera() : p_pos(0)
{
	p_pos = new Point();
}

Camera::Camera(Point p) : p_pos(0)
{
	p_pos = new Point(p.getX(), p.getY(), p.getZ());
}

Camera::~Camera()
{
	delete p_pos;
}

std::ostream& operator<<(std::ostream& os, const Camera& c)
{
	os << "Camera\n\t" << *c.getPt() << std::endl;
	return os;
}
