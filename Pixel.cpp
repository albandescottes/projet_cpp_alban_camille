#include "Pixel.h"

Pixel::Pixel() : p_pos(0), p_color(0) 
{
	p_pos = new Point();
	p_color = new Couleur();
}

Pixel::Pixel(Point p, Couleur c) : p_pos(0), p_color(0)
{
	p_pos = new Point(p);
	p_color = new Couleur(c);
}

Pixel::~Pixel()
{
	delete p_pos;
    delete p_color;
}

std::ostream& operator<<(std::ostream& os, const Pixel& pi)
{
	os << "Pixel\t" << *pi.getPt() << "\t" << *pi.getCol() << std::endl;
	return os;
}
