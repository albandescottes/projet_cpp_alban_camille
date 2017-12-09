#include "Point.h"
#include "Couleur.h"

#ifndef FORME_H
#define FORME_H


class Forme
{
    public:
        Forme();
        Forme(Point p, Couleur c, double r);
        ~Forme();
        friend std::ostream& operator<<(std::ostream& os, const Forme& f);
        Point * getPt() const { return this->p_pos; };
        Couleur * getCol() const { return this->p_color; };
        double getRef() { return reflexion; };
        void setPt(Point * pt) { p_pos = pt; };
        void setCol(Couleur * col) { p_color = col; };
        void setRef(double ref) { reflexion = ref; };
    protected:
		Point *p_pos;
        Couleur *p_color;
        double reflexion;
    private:

};

#endif // FORME_H
