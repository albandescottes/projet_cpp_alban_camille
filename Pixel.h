#include "Point.h"
#include "Couleur.h"
 

#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
    public:
        Pixel();
        Pixel(Point p, Couleur c);
        ~Pixel();
        friend std::ostream& operator<<(std::ostream& os, const Pixel& pi);
        Point * getPt() const {return this->p_pos;};
        Couleur * getCol() const {return this->p_color;};
        void setPt(Point * pt) { p_pos = pt;}; 
        void setCol(Couleur * col) { p_color = col;}; 
    protected:
    private:
        Point *p_pos;
        Couleur *p_color;
};

#endif // PIXEL_H
