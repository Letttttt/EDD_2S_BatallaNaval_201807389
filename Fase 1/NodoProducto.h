
#ifndef NODOPRODUCTO_H
#define NODOPRODUCTO_H
#include <string>
#include <iostream>
using namespace std;

class NodoProducto {
public:
    string id;
    string categoria;
    double precio;
    string nombre;
    string desconocido;
    NodoProducto* siguiente;

    NodoProducto() {
        siguiente = NULL;
    }
};
#endif /* NODOPRODUCTO_H */

