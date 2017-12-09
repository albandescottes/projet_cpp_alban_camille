#include "Point.h"


Point::~Point()
{
    //dtor
}

std::ostream& operator<<(std::ostream& os, const Point& pt)  
{  
    os << "pt("<< pt.x << ";" << pt.y << ";" << pt.z << ")" << std::endl;  
    return os;  
} 
