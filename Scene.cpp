#include "Scene.h"

Scene::Scene() : p_cam(0), p_ecran(0), p_lum(0), p_background(0)
{
	p_cam = new Camera();
	p_ecran = new Ecran();
	p_lum = new Lumiere();
	p_background = new Couleur();
}

Scene::Scene(Camera c, Ecran e, Lumiere l, Couleur b) : p_cam(0), p_ecran(0), p_lum(0), p_background(0)
{
	p_cam = new Camera(c);
	p_ecran = new Ecran(e);
	p_lum = new Lumiere(l);
	p_background = new Couleur(b);
}

Scene::~Scene()
{
    delete p_cam;
    delete p_ecran;
    delete p_lum;
    delete p_background;
    
}

std::ostream& operator<<(std::ostream& os, const Scene& s)
{
	os << "Scene\n" << *s.getCam() << *s.getLight() << *s.getScreen() << "\t" << *s.getCol() << std::endl;
	os << "Formes :\n";
	if((int)s.shape.size() != 0){
		for(int i=0;i < (int)s.shape.size();i++){
			os << typeid(s.shape[i]).name() << " " << *s.shape[i];
		}
	}else{
		std::cout << "\t0 formes" << std::endl;
	}

	return os;
}

void Scene::addShape(Sphere * s)
{
	this->shape.push_back(s);
}

int Scene::parseFile()
{
	std::string name_file;
	std::ifstream file;
	std::string line;
	
	std::cout << "Which file do you want to open and parse ?" << std::endl ;
	std::cin >> name_file;
	
	int nb=0;
	
	file.open(name_file);
	if(file.is_open()){
		while(getline(file,line)){
			if(line[0] != '#' && line != ""){
				switch(nb){
					case 0 :

						this->setCam(new Camera( parsePoint(line) ) );
						std::cout << "... complete]\n";
						nb++;
						break;
					case 1 : 
						this->p_ecran->setTLC( new Point(parsePoint(line)) );
						std::cout << "... complete]\n";
						nb++;
						break;
					case 2 : 
						this->p_ecran->setTRC( new Point(parsePoint(line)) );
						std::cout << "... complete]\n";
						nb++;
						break;
					case 3 : 
						this->p_ecran->setBLC( new Point(parsePoint(line)) );
						std::cout << "... complete]\n";
						nb++;
						break;
					case 4 :
						this->p_ecran->setResolution(std::stoi(line));
						nb++;
						break;
					case 5 :
						this->setBack( new Couleur(parseColor(line)) );
						std::cout << "... complete]\n";
						nb++;
						break;
					case 6 :
						this->setLight( parseLight(line) ) ;
						std::cout << "... complete]\n";
						nb++;
						break;
					case 7 :
						this->parseSphere(line);
						std::cout << "... complete]\n";
						break;
					default :
						std::cout << "problem" << std::endl;
						break;
				}
			}
		}
	}
	
	file.close();
	std::cout << "[Parse file complete]" << std::endl;
	return 0;
}

Point Scene::parsePoint(std::string l)
{
	std::cout << "[Parse Point ...";
	std::string token;
	size_t pos = 0;
	std::vector<std::string> word;
	while ((pos = l.find(" ")) != std::string::npos){
		token = l.substr(0, pos);
		word.push_back(token);
		l.erase(0, pos + 1);
	}
	word.push_back(l);
	Point p(std::stoi(word[0]),std::stoi(word[1]),std::stoi(word[2]));
	return p;
}

Couleur Scene::parseColor(std::string l)
{
	std::cout << "[Parse Color ...";
	std::string token;
	size_t pos = 0;
	std::vector<std::string> word;
	while ((pos = l.find(" ")) != std::string::npos){
		token = l.substr(0, pos);
		word.push_back(token);
		l.erase(0, pos + 1);
	}
	word.push_back(l);
	Couleur c(std::stoi(word[0]),std::stoi(word[1]),std::stoi(word[2]));
	return c;
}

Lumiere * Scene::parseLight(std::string l)
{
	std::cout << "[Parse Light ...";
	std::string token;
	size_t pos = 0;
	std::vector<std::string> word;
	while ((pos = l.find(" ")) != std::string::npos){
		token = l.substr(0, pos);
		word.push_back(token);
		l.erase(0, pos + 1);
	}
	word.push_back(l);
	Point p(std::stoi(word[0]),std::stoi(word[1]),std::stoi(word[2]));
	Couleur c(std::stoi(word[3]),std::stoi(word[4]),std::stoi(word[5]));
	Lumiere * lum = new Lumiere(p,c);
	return lum;
}

void Scene::parseSphere(std::string l){
	std::cout << "[Parse Sphere ...";
	std::string token;
	size_t pos = 0;
	std::vector<std::string> word;
	word.clear();
	while ((pos = l.find(" ")) != std::string::npos){
		token = l.substr(0, pos);
		word.push_back(token);
		l.erase(0, pos + 1);
	}
	word.push_back(l);
	Point p(std::stoi(word[1]),std::stoi(word[2]),std::stoi(word[3]));
	double rad = std::stod(word[4]);
	Couleur c(std::stoi(word[5]), std::stoi(word[7]), std::stoi(word[6]));
	double ref = std::stod(word[8]);
	Sphere *sp = new Sphere(p,c,ref,rad);
	this->addShape(sp);
}


Couleur * Scene::meet(Point * p1, Point * p2, bool verbose) {
	if(verbose) { std::cout << *p1 << *p2 << std::endl; }
	
	Couleur * col = new Couleur(0,0,0);
	
	bool touche = false;
	bool eclaire = true;
	
	double xA = p1->getX();	double yA = p1->getY();	double zA = p1->getZ();

	double xB = p2->getX();	double yB = p2->getY();	double zB = p2->getZ();
	
	double xC ,yC,zC;
	
	double delta, r1, r2;
	/* On injecte l'equation parametrique dans l'equation de sphere.
	 * On résout ensuite cette equation du second degré avec un discriminant.
	 * En la développant on trouve les coef a, b et c :
	 */

	double a = (xB-xA)*(xB-xA) + (yB-yA)*(yB-yA) + (zB-zA)*(zB-zA);
	
	double b ,c ,r;
	
	//Sphere i;
	/* coordonnées du point final */
	double d = -1;
	Sphere *sph_tmp = NULL;
	
	Point * contact;

	for(int e=0;e < (int)this->shape.size();e++){
		
		//i = this->shape[e];
		
		xC = this->shape[e]->getPt()->getX();
		yC = this->shape[e]->getPt()->getY();
		zC = this->shape[e]->getPt()->getZ();
		
		r = this->shape[e]->getRayon();
		
		b =	2*(	(xB-xA)*(xA-xC) + (yB-yA)*(yA-yC) + (zB-zA)*(zA-zC) );
		c =	(xA-xC)*(xA-xC)	+ (yA-yC)*(yA-yC) + (zA-zC)*(zA-zC)	- (r * r);	

		delta = b*b - 4*a*c;
		if (delta>0) {

			r1 = (-b - sqrt(delta))/(2*a);
			r2 = (-b + sqrt(delta))/(2*a);
			
			if (d==-1 || (d>=0 && r1<d)) {
				if (r1>=0.001 && r1<r2) {
					d=r1;
					sph_tmp = this->shape[e];
					touche = true;
				}
			}
			else if (d==-1 || (d>=0 && r2<d)) {
				if (r2>=0.001 && r2<r1) {
					r2=d;
					sph_tmp = this->shape[e];
					touche = true;
				}
			}
			
			//touche = true;
		}
		else if (delta == 0 ) { 
			
			r1 = b/(2*a);
			
			if (d==-1 || (d>=0 && r1<d)) {
				if (r1>=0.001) {
					d=r1;
					sph_tmp = this->shape[e];
					touche = true;
				}
			}
			if(verbose) { std::cout << "1 racine" << std::endl; }
			//touche = true;
		}
		else { 
			if(verbose) { std::cout << "0 racine" << std::endl; } 
		}

	}
	
	if (!touche){
		col->setR(this->getCol()->getR());	col->setG(this->getCol()->getG());	col->setB(this->getCol()->getB());
	}

	else {
		contact  = new Point(xA+d*(xB-xA), yA+d*(yB-yA), zA+d*(zB-zA));
		for(int e=0;e < (int)this->shape.size();e++){
			if (this->shape[e]->between(contact, this->getLight()->getPt() )) {
				col->setR(0);
				col->setG(0);
				col->setB(0);
				eclaire = false;
				break;
			}
		}
	}
	


	if(touche && eclaire){
		//std::cout<<sph_tmp<<std::endl;
		col->setR( std::max(-1 * (1-sph_tmp->getRef()) * Point::calculCos(sph_tmp->getPt(), contact, this->getLight()->getPt()) * (sph_tmp->getCol()->getR() * this->getLight()->getCol()->getR())/255 , 0.0));
		col->setG( std::max(-1 * (1-sph_tmp->getRef()) * Point::calculCos(sph_tmp->getPt(), contact, this->getLight()->getPt()) * (sph_tmp->getCol()->getG() * this->getLight()->getCol()->getG())/255 , 0.0));
		col->setB( std::max(-1 * (1-sph_tmp->getRef()) * Point::calculCos(sph_tmp->getPt(), contact, this->getLight()->getPt()) * (sph_tmp->getCol()->getB() * this->getLight()->getCol()->getB())/255 , 0.0));
	}

	//std::cout<<"OKOKOKOK"<<std::endl;
	
	if (touche) {
		double xI = contact->getX() - xB;
		double yI = contact->getY() - yB;
		double zI = contact->getZ() - zB;

		double normeI = sqrt(xI*xI + yI*yI + zI*zI);
		xI/=-normeI;
		yI/=-normeI;
		zI/=-normeI;

	
		double xN = contact->getX() - sph_tmp->getPt()->getX();
		double yN = contact->getY() - sph_tmp->getPt()->getY();
		double zN = contact->getZ() - sph_tmp->getPt()->getZ();

		xN/=sph_tmp->getRayon();
		yN/=sph_tmp->getRayon();
		zN/=sph_tmp->getRayon();

		double scalaireIN = xI*xN + yI*yN + zI*zN;
	
		double xV = contact->getX() + 2*scalaireIN*xN - xI;
		double yV = contact->getY() + 2*scalaireIN*yN - yI;
		double zV = contact->getZ() + 2*scalaireIN*zN - zI;
	
		Point * nouveauPoint = new Point(xV, yV, zV);
		//std::cout << *nouveauPoint << std::endl;
		Couleur* ct = meet(contact, nouveauPoint, false);
		//std::cout << ct->getR() <<","<<ct->getG()<<","<<ct->getB()<<std::endl;
		if ((ct->getR()>0 || ct->getG()>0 || ct->getB()>0) && sph_tmp->getRef()>0) {
			col->add(sph_tmp->getRef(),ct);
		}	
	}
	
	
	//std::cout << "lol" << std::endl;
	return col;
}

void Scene::traceRay(bool verbose)
{
	Couleur *temp =  NULL;
	for(int i = 0; i < this->getScreen()->getRes() ; i++){
        for(int j = 0; j < this->getScreen()->getRes() ; j++){

			temp  = this->meet( this->getCam()->getPt() , this->getScreen()->getPixel(i,j)->getPt() , verbose);	
        	
        		//std::cout << "touche une sphere en [" << i << "][" << j << "]"<< std::endl; 
        		this->getScreen()->getPixel(i,j)->getCol()->setR(temp->getR());
        		this->getScreen()->getPixel(i,j)->getCol()->setG(temp->getG());
        		this->getScreen()->getPixel(i,j)->getCol()->setB(temp->getB());
        }
	}       
}

void Scene::writeFile()
{
	 std::ofstream fichier;
	 fichier.open("image.ppm", std::ios::out | std::ios::trunc);  //déclaration du flux et ouverture du fichier
        
        if(fichier)  // si l'ouverture a réussi
        {
            fichier << "P3\n" << this->getScreen()->getRes() << " " << this->getScreen()->getRes() << "\n255\n";
            for(int i = 0; i < this->getScreen()->getRes() ; i++){
      			for(int j = 0; j < this->getScreen()->getRes() ; j++){
					fichier << this->getScreen()->getPixel(i,j)->getCol()->getR() <<
            		 " " << this->getScreen()->getPixel(i,j)->getCol()->getG() <<
            		 " " << this->getScreen()->getPixel(i,j)->getCol()->getB() << " ";
            	}
            	fichier << "\n";
            }
            fichier.close();  // on referme le fichier
        }
}
