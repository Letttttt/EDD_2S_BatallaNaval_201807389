#include "ListaMovimientos.h"
struct NodoMovimiento{
    string NombreMovimiento;
    Pila* movimientos;
    NodoMovimiento* siguiente;
}*principio5;

ListaMovimientos::ListaMovimientos() {
}


void ListaMovimientos::IngresandoMovimientos(string NombreMovimiento, Pila* movimientos) {
    NodoMovimiento*nuevo= new NodoMovimiento();
    nuevo->NombreMovimiento=NombreMovimiento;
    nuevo->movimientos=movimientos;
    if(principio5!=NULL){
        principio5=nuevo;
    }else{
        nuevo->siguiente=principio5;
        principio5=nuevo;
    }
}

