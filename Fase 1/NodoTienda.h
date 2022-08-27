#ifndef NODOTIENDA_H
#define NODOTIENDA_H
#include <string>
#include <iostream>
#include "ListaProductos.h"

using namespace std;

class NodoCategoria {
    public:
        string NombreCategoria;
        ListaProductos productos;
        NodoCategoria* siguiente;
        NodoCategoria(){
            siguiente= NULL;
        }
    private:
};

#endif /* NODOTIENDA_H */
