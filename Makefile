EXEC = main
SOURCES = main.cpp Couleur.cpp Pixel.cpp Point.cpp Forme.cpp Sphere.cpp Camera.cpp Lumiere.cpp Scene.cpp Ecran.cpp  
OBJECTS = $(SOURCES:.cpp=.o)
CC = g++
CFLAGS = -Wall -g -Wextra -Werror -std=c++11

.PHONY: default clean
 
default: $(EXEC)
 
Couleur.o: Couleur.cpp Couleur.h
Pixel.o: Pixel.cpp Pixel.h
Point.o: Point.cpp Point.h
Forme.o : Forme.cpp Forme.h
Sphere.o: Sphere.cpp Sphere.h
Camera.o: Camera.cpp Camera.h
Lumiere.o: Lumiere.cpp Lumiere.h
Scene.o: Scene.cpp Scene.h
Ecran.o: Ecran.cpp Ecran.h



%.o: %.cpp
	$(CC) $< $(CFLAGS) -o $@ -c 
 
$(EXEC): $(OBJECTS)
	$(CC) -o $@ $^
 
clean:
	rm -rf $(EXEC) $(OBJECTS) $(SOURCES:.cpp=.cpp~) $(SOURCES:.cpp=.hpp~) Makefile~

exec:
	./$(EXEC)
