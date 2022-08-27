
#ifndef TUTORIAL_H
#define TUTORIAL_H
#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;

class Tutorial {
public:
    Nodo*principio2;
    Tutorial(){
        principio2=NULL;
    }
    void IngresandoTutorial(int, int);
    void MostrarTutorial();

};

#endif /* TUTORIAL_H */

