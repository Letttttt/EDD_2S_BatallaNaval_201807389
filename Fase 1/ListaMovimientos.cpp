#include "ListaMovimientos.h"

void ListaMovimientos::IngresandoMovimientos(string NombreMovimiento, Pila* movimientos) {
    NodoMovimiento*nuevo = new NodoMovimiento();
    nuevo->NombreMovimiento = NombreMovimiento;
    nuevo->movimientos = movimientos;
    if (principio5 != NULL) {
        principio5 = nuevo;
    } else {
        nuevo->siguiente = principio5;
        principio5 = nuevo;
    }
}

void ListaMovimientos::MostrarMovimientos() {
    NodoMovimiento*temp = principio5;
    while (temp != NULL) {
        cout << temp->NombreMovimiento << endl;
        temp = temp->siguiente;
    }
}
