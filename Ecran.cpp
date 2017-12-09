#include "Ecran.h"

Ecran::Ecran(): p_TLC(0), p_TRC(0), p_BLC(0), resolution(0)
{

}

Ecran::Ecran(Point a, Point b, Point c, int r) : p_TLC(0), p_TRC(0), p_BLC(0), resolution(r)
{
	p_TLC = new Point(a);
	p_TRC = new Point(b);
	p_BLC = new Point(c);
    //pixels = new Pixel*[r];
    //for(int i = 0; i < r; ++i)
    //    pixels[i] = new Pixel[r];
}

Ecran::~Ecran()
{
    delete p_TLC;
    delete p_TRC;
    delete p_BLC;
}

std::ostream& operator<<(std::ostream& os, const Ecran& ec)  
{  
    os << "Ecran\n\tTLC "<< *ec.getTLC() << "\tTRC " << *ec.getTRC() << "\tBLC " << *ec.getBLC() << "\tResol : " << ec.resolution <<std::endl;  
    return os;  
} 
