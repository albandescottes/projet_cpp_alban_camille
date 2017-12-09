#include "Point.h"
#include "Couleur.h"

#ifndef LUMIERE_H
#define LUMIERE_H


class Lumiere
{
    public:
        Lumiere();
        Lumiere(Point p, Couleur c);
        ~Lumiere();
        friend std::ostream& operator<<(std::ostream& os, const Lumiere& l);
        Point * getPt() const { return p_pos; };
        Couleur * getCol() const { return p_color; };
        void setPt(Point * pt) 
        { 
            std::cout << "lol" << std::endl;
            p_pos = pt;
            std::cout << "lol" << std::endl;
        };
        void setCol(Couleur  * col) { p_color = col; };
    protected:
    private:
        Point *p_pos;
        Couleur *p_color;
};

#endif // LUMIERE_H
