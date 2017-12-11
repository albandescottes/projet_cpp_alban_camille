#include "Point.h"
#include "Camera.h"
#include "Ecran.h"
#include "Sphere.h"
#include "Lumiere.h"
#include "Couleur.h"
#include <vector>
#include <typeinfo>
#include <fstream>
#include <cmath>

#ifndef SCENE_H
#define SCENE_H


class Scene
{
    public:
        Scene();
        Scene(Camera c, Ecran e, Lumiere l, Couleur b);
        ~Scene();
        friend std::ostream& operator<<(std::ostream& os, const Scene& s);
        Camera * getCam() const { return this->p_cam; };
        Lumiere * getLight() const { return this->p_lum; };
        Ecran * getScreen() const { return this->p_ecran; };
        Couleur * getCol() const { return this->p_background; };
        void setCam(Camera * c) { p_cam = c; };
        void setLight(Lumiere * l) { p_lum = l; };
        void setScreen(Ecran * e) { p_ecran = e; };
        void setBack(Couleur * c) { p_background = c; };
        void addShape(Sphere * s);
        
        int parseFile();
        static Point parsePoint(std::string l);
        static Couleur parseColor(std::string l);
        static Lumiere * parseLight(std::string l);
        void parseSphere(std::string l);
        bool meet(Point * p1, Point * p2, bool verbose, Couleur * col);
        void traceRay(bool verbose);
        void writeFile();
    protected:
    private:
        Camera *p_cam;
        Ecran *p_ecran;
        Lumiere *p_lum;
        Couleur *p_background;
        std::vector<Sphere*> shape;
};

#endif // SCENE_H
