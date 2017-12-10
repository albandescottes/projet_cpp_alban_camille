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
