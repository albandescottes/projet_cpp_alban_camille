#include "Lumiere.h"

Lumiere::Lumiere() : p_pos(0), p_color(0) 
{
	p_pos = new Point();
	p_color = new Couleur();
}

Lumiere::Lumiere(Point p, Couleur c) : p_pos(0), p_color(0) 
{
	p_pos = new Point(p);
	p_color = new Couleur(c);
}

Lumiere::~Lumiere()
{
	delete p_pos;
	delete p_color;
}

std::ostream& operator<<(std::ostream& os, const Lumiere& l)
{
	os << "Light\t" << *l.getPt() << "\t" << *l.getCol() << std::endl;
	return os;
}
