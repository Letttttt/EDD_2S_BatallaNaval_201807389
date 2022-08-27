
#ifndef LISTAPRODUCTOS_H
#define LISTAPRODUCTOS_H
#include <string>
#include <iostream>
#include "NodoProducto.h"
using namespace std;

class ListaProductos {
public:
    NodoProducto*principio1;
    ListaProductos(){
        principio1=NULL;
    }
    void IngresandoProducto(int, string, double, string, string);
    void MostrarProducto();

};

#endif /* LISTAPRODUCTOS_H */

