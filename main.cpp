#include "Point.h"
#include "Ecran.h"
#include "Scene.h"

#include <iostream>

using namespace std;

int main()
{
	// Point p1(0,0,0);
	// Point p2(90,110,30);
	// Point p3(200,200,0);
	// int res = 400;
	// Ecran *ecr = new Ecran();
	// ecr->setBLC(&p1);
	// ecr->setTLC(&p2);
	// ecr->setTRC(&p3);
	// ecr->setResolution(res);
	// ecr->printPixels();


	Scene *pSc = new Scene();
	if(1 == pSc->parseFile()){
		cerr << "shit\n";
	}

	pSc->traceRay(false);
	pSc->writeFile();
	
//	pSc->getScreen()->printPixelsValue();
//	pSc->getScreen()->printPixels();
//  cout << *pSc;
//  Point p1(0,0,0);
//  Point p2(0,1,0);
//  pSc->meet(p1,p2);
	return 0;
}
