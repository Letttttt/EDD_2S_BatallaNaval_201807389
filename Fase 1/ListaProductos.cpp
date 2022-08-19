#include "ListaProductos.h"
#include <string>

struct NodoProducto{
    int id;
    string categoria;
    double precio;
    string nombre;
    string desconocido;
    NodoProducto* siguiente;
}*principio1;


ListaProductos::ListaProductos() {
}


void ListaProductos::IngresandoProducto(int id, string categoria, double precio, string nombre, string desconocido) {
    NodoProducto* nuevo = new NodoProducto();
    nuevo->id=id;
    nuevo->categoria=categoria;
    nuevo->precio=precio;
    nuevo->nombre=nombre;
    nuevo->desconocido=desconocido;
}

