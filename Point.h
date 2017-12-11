#include <iostream> 

#ifndef POINT_H
#define POINT_H


class Point
{
    public:
        Point() : x(0), y(0), z(0) {};
        Point(double xx, double yy, double zz) : x(xx), y(yy), z(zz) {};
        Point(Point const& pt);
        virtual ~Point();
        friend std::ostream& operator<<(std::ostream& os, const Point& pt);
        double getX() {return x;};
        double getY() {return y;};
        double getZ() {return z;};
        void setX(double xx) { x = xx;}; 
        void setY(double yy) { y = yy;}; 
        void setZ(double zz) { z = zz;}; 
    protected:
    private:
        double x, y, z;
};

#endif // POINT_H
