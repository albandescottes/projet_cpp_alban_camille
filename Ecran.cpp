#include "Ecran.h"

Ecran::Ecran(): p_TLC(0), p_TRC(0), p_BLC(0), resolution(0)
{

}

Ecran::Ecran(Point a, Point b, Point c, int r) : p_TLC(0), p_TRC(0), p_BLC(0), resolution(r)
{
	p_TLC = new Point(a);
	p_TRC = new Point(b);
	p_BLC = new Point(c);
    pixels = new Pixel*[r];
    for(int i = 0; i < r; i++){
       pixels[i] = new Pixel[r];
    }

    for(int i = 0; i < this->getRes() ; i++){
        for(int j = 0; j < this->getRes() ; j++){
            pixels[i][j].setPt(new Point( ((a.getX() + ((double)i/r)*(b.getX() - a.getX()) + ((double)j/r)* (c.getX() - a.getX())) + 0.5)/r,
                ((a.getY() + ((double)i/r)*(b.getY() - a.getY()) + ((double)j/r)* (c.getY() - a.getY())) + 0.5)/r,
                ((a.getZ() + ((double)i/r)*(b.getZ() - a.getZ()) + ((double)j/r)* (c.getZ() - a.getZ())) + 0.5)/r));
            pixels[i][j].setCol(new Couleur());
        }
    }
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

void Ecran::setResolution(int r)
{ 
    resolution = r;
    pixels = new Pixel*[r];
    for(int i = 0; i < r; i++){
       pixels[i] = new Pixel[r];
    }
    //std::cout << *p_TLC << "|" << *p_TRC << "|" << *p_BLC << std::endl;
    for(int i = 0; i < this->getRes() ; i++){
        for(int j = 0; j < this->getRes() ; j++){
            pixels[i][j].setPt(new Point( p_TLC->getX() + ((double)i /r)*(p_TRC->getX() - p_TLC->getX()) + ((double)j/r)* (p_BLC->getX() - p_TLC->getX()),
                p_TLC->getY() + ((double)i/r)*(p_TRC->getY() - p_TLC->getY()) + ((double)j/r)* (p_BLC->getY() - p_TLC->getY()),
                p_TLC->getZ() + ((double)i/r)*(p_TRC->getZ() - p_TLC->getZ()) + ((double)j/r)* (p_BLC->getZ() - p_TLC->getZ())));
            pixels[i][j].setCol(new Couleur());
			
        }
    }
}

void Ecran::printPixels()
{
    for(int i = 0; i < this->getRes() ; i++){
        for(int j = 0; j < this->getRes() ; j++){
            std::cout << "pixel[" << i << "]["<< j <<"] "<< pixels[i][j] << std::endl;
        }
    }    
}

void Ecran::printPixelsValue()
{
    for(int i = 0; i < this->getRes() ; i++){
        for(int j = 0; j < this->getRes() ; j++){
            if( pixels[i][j].getCol()->getR() == 80 && pixels[i][j].getCol()->getG() == 80 && pixels[i][j].getCol()->getB() == 100 ){
                std::cout << "_";
            }
            else{
                std::cout << "W";
            }
        }
        std::cout << std::endl;
    }    
}


void Ecran::freeEcran()
{
    for(int i=0; this->getRes(); i++){
        delete[] pixels[i];
    }
    delete[] pixels;   
}
