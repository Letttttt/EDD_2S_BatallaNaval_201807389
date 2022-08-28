
#ifndef TIENDA_H
#define TIENDA_H
#include <string>
#include <iostream>
#include "NodoTienda.h"

using namespace std;

class Tienda {
public:
    NodoCategoria*principio3;
    Tienda(){
        principio3=NULL;
    }
    void IngresandoProductoT(string, string, double, string, string);
    void MostrarTienda();
};

#endif /* TIENDA_H */

