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
    if(principio1==NULL){
        principio1=nuevo;
    }else{
        NodoProducto*temp=principio1;
        while(temp->siguiente==NULL){
            temp=temp->siguiente;
        }
        temp->siguiente=nuevo;
    }
}

