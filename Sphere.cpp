#include "Sphere.h"

Sphere::Sphere()  : Forme() , rayon(0)
{

}

Sphere::Sphere(Point p, Couleur c, double ref, double ray)  : Forme(p,c,ref) , rayon(ray)
{

}

Sphere::~Sphere()
{
    delete p_pos;
    delete p_color;
}

std::ostream& operator<<(std::ostream& os, const Sphere& s)
{
	os << *s.getPt() << "\t" << *s.getCol() << "Reflex : " << s.reflexion  << " Radius : "<< s.rayon << std::endl;
	return os;
}
