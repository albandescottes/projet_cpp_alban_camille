#include "Forme.h"

#ifndef SPHERE_H
#define SPHERE_H


class Sphere : public Forme
{
    public:
    	Sphere();
        Sphere(Point p, Couleur c, double ref, double ray);
        ~Sphere();
        friend std::ostream& operator<<(std::ostream& os, const Sphere& sp);
        double getRayon() { return rayon; };
        void setRayon(double r) { rayon = r; };
        bool between (Point * p1, Point * p2);
    protected:
    private:
        double rayon;
};

#endif // SPHERE_H
