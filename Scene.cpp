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

