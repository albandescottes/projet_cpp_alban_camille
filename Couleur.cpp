#include "Couleur.h"

Couleur::Couleur(Couleur const& col) : r(col.r), g(col.g), b(col.b)
{

}

Couleur::~Couleur()
{
    //dtor
}

std::ostream& operator<<(std::ostream& os, const Couleur& c)  
{  
    os << "RGB : "<< c.r << "|" << c.g << "|" << c.b;  
    return os;  
} 

void Couleur::add (Couleur * c) {
	r=std::min(255, r+c->getR());
	g=std::min(255, g+c->getG());
	b=std::min(255, b+c->getB());
}
