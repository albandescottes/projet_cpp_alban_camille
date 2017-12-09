#include "Couleur.h"

Couleur::~Couleur()
{
    //dtor
}

std::ostream& operator<<(std::ostream& os, const Couleur& c)  
{  
    os << "RGB : "<< c.r << "|" << c.g << "|" << c.b << std::endl;  
    return os;  
} 
