#include "Forme.h"

Forme::Forme() : p_pos(0), p_color(0), reflexion(0)
{
	p_pos = new Point();
	p_color = new Couleur();
}

Forme::Forme(Point p, Couleur c, double r) : p_pos(0), p_color(0), reflexion(r)
{
	p_pos = new Point(p);
	p_color = new Couleur(c);
}

Forme::~Forme()
{
    delete p_pos;
    delete p_color;
}

std::ostream& operator<<(std::ostream& os, const Forme& f)
{
	os << *f.getPt() << "\t" << *f.getCol() << "Reflex : " << f.reflexion << std::endl;
	return os;
}
