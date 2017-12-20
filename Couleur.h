#include <iostream>

#ifndef COULEUR_H
#define COULEUR_H


class Couleur
{
    public:
        Couleur() : r(0) , g(0), b(0) {};
        Couleur(int red, int green, int blue) : r(red), g(green), b(blue) {};
        Couleur( Couleur const& col);
        virtual ~Couleur();
        friend std::ostream& operator<<(std::ostream& os, const Couleur& c);
        int getR() {return r;};
        int getG() {return g;};
        int getB() {return b;};
        void setR(int red) { r = red;}; 
        void setG(int green) { g = green;}; 
        void setB(int blue) { b = blue;}; 
        void add(Couleur * c);
    protected:
    private:
        int r;
        int g;
        int b;
};

#endif // COULEUR_H
