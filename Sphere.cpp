#include "Sphere.h"

Sphere::Sphere()  : Forme() , rayon(0)
{

}

Sphere::Sphere(Point p, Couleur c, double ref, double ray)  : Forme(p,c,ref) , rayon(ray)
{

}

Sphere::~Sphere()
{
    delete p_pos;
    delete p_color;
}

std::ostream& operator<<(std::ostream& os, const Sphere& s)
{
	os << *s.getPt() << "\t" << *s.getCol() << "Reflex : " << s.reflexion  << " Radius : "<< s.rayon << std::endl;
	return os;
}


/* renvoie true s'il n'y a pas d'obstacle entre le point de la sphere concerné et la lumière
 * false sinon
 */
bool Sphere::between(Point * p1, Point * p2) {
	
	bool clear = false;
	
	double xA = p1->getX();
	double yA = p1->getY();
	double zA = p1->getZ();

	double xB = p2->getX();
	double yB = p2->getY();
	double zB = p2->getZ();
	
	double xC = this->getPt()->getX();
	double yC = this->getPt()->getY();
	double zC = this->getPt()->getZ();
	
	/* On injecte l'equation parametrique dans l'equation de sphere.
	 * On résout ensuite cette equation du second degré avec un discriminant.
	 * En la développant on trouve les coef a, b et c :
	 */

	double a = (xB-xA)*(xB-xA) + (yB-yA)*(yB-yA) + (zB-zA)*(zB-zA);
	
	double r = this->getRayon();
	
	double b =	2*(	(xB-xA)*(xA-xC) + (yB-yA)*(yA-yC) + (zB-zA)*(zA-zC) );
	double c =	(xA-xC)*(xA-xC)	+ (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC)	- (r * r);	

	double delta = b*b - 4*a*c;
	
	if (delta > 0) {
		double r1 = (-b - sqrt(delta))/(2*a);
		double r2 = (-b + sqrt(delta))/(2*a);
		
		if ((r1>0.001 && r1<sqrt(a)) && (r2>0.001 && r2<=sqrt(a))){
			clear = true;
		}
	}
	
	else if (delta == 0) {
		double r1 = (-b - sqrt(delta))/(2*a);
					
		if (r1>0.001 && r1<sqrt(a)) {
			clear = true;
		}
	}
	
	return clear;
}
