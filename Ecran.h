#include "Pixel.h"

#ifndef ECRAN_H
#define ECRAN_H


class Ecran
{
    public:
        Ecran();
        Ecran(Point a, Point b, Point c, int r);
        ~Ecran();
        friend std::ostream& operator<<(std::ostream& os, const Ecran& ec);
        Point * getTLC() const { return this->p_TLC; };
        Point * getTRC() const { return this->p_TRC; };
        Point * getBLC() const { return this->p_BLC; };
        int getRes() { return resolution; };
        void setTLC(Point *a) { p_TLC = a; };
        void setTRC(Point *a) { p_TRC = a; };
        void setBLC(Point *a) { p_BLC = a; };
        void setResolution(int r) { resolution = r; };
    protected:
    private:
        Point *p_TLC, *p_TRC, *p_BLC;
        int resolution;
        Pixel **pixels;
};

#endif // sg
