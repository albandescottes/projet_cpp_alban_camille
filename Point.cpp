#include "Point.h"

Point::Point(Point const& pt) : x(pt.x), y(pt.y) , z(pt.z)
{
	
}

Point::~Point()
{
    //dtor
}

std::ostream& operator<<(std::ostream& os, const Point& pt)  
{  
    os << "pt("<< pt.x << ";" << pt.y << ";" << pt.z << ")";  
    return os;  
} 



double Point::calculCos(Point * centre, Point * surface, Point * lum){
	double vect = ((centre->getX() - surface->getX()) * (lum->getX() - surface->getX()) 
		+ (centre->getY() - surface->getY()) * (lum->getY() - surface->getY())
		+ (centre->getZ() - surface->getZ()) * (lum->getZ() - surface->getZ()) );
		
	double prod1 = sqrt((centre->getX() - surface->getX()) * (centre->getX() - surface->getX()) 
		+ (centre->getY() - surface->getY()) * (centre->getY() - surface->getY())
		+ (centre->getZ() - surface->getZ()) * (centre->getZ() - surface->getZ()) );

	double prod2 = sqrt((lum->getX() - surface->getX()) * (lum->getX() - surface->getX()) 
		+ (lum->getY() - surface->getY()) * (lum->getY() - surface->getY())
		+ (lum->getZ() - surface->getZ()) * (lum->getZ() - surface->getZ()) );
	return vect / (prod1 * prod2);
}
