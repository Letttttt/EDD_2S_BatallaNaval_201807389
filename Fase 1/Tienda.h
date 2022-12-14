
#ifndef TIENDA_H
#define TIENDA_H
#include <string>
#include <iostream>
#include <fstream>
#include "NodoTienda.h"
#include "NodoProducto.h"

using namespace std;

class Tienda {
public:
    NodoCategoria*principio3;
    Tienda(){
        principio3=NULL;
    }
    void IngresandoProductoT(string, string, double, string, string);
    void MostrarTienda();
    void Graficando();
    float round(float);
    void ReordenandoAsc();
    void ReordenandoDes();
};

#endif /* TIENDA_H */

