#ifndef PILA_H
#define PILA_H
#include <iostream>
#include <string>
#include "Nodo.h"
using namespace std;

class Pila {
public:
    Nodo*principio4;

    Pila() {
        principio4 = NULL;
    }
    void IngresandoPila(int, int);
    void MostrarPila();
};

#endif /* PILA_H */

