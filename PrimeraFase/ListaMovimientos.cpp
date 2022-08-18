#include "ListaMovimientos.h"
struct NodoMovimiento{
    string NombreMovimiento;
    Pila* movimientos;
    Nodo* siguiente;
}*principio;

ListaMovimientos::ListaMovimientos() {
}


void ListaMovimientos::IngresandoMovimientos(string NombreMovimiento, Pila* movimientos) {
    NodoMovimiento*nuevo=NodoMovimiento();
    nuevo->NombreMovimiento=NombreMovimiento;
    nuevo->movimientos=movimientos;
    if(principio!=NULL){
        principio=nuevo;
    }else{
        nuevo->siguiente=principio;
        principio=nuevo;
    }
}

