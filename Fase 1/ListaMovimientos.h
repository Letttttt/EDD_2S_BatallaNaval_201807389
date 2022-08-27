
#ifndef LISTAMOVIMIENTOS_H
#define LISTAMOVIMIENTOS_H
#include <string>
#include <iostream>
#include "NodoMovimiento.h"
#include "Pila.h"


using namespace std;

class ListaMovimientos {
public:
    NodoMovimiento*principio5;

    ListaMovimientos() {
        principio5=NULL;
    }
    void IngresandoMovimientos(string, Pila*);
    void MostrarMovimientos();
};

#endif /* LISTAMOVIMIENTOS_H */

