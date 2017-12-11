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
