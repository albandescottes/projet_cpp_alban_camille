#include "Point.h"

#ifndef CAMERA_H
#define CAMERA_H


class Camera
{
    public:
    	Camera();
        Camera(Point p);
        ~Camera();
        friend std::ostream& operator<<(std::ostream& os, const Camera& c);
        Point * getPt() const { return this->p_pos; };
        void setPt(Point * pt) { p_pos = pt; };
    protected:
    private:
        Point *p_pos;
};

#endif // CAMERA_H
