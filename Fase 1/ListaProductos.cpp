#include "ListaProductos.h"
#include <string>

void ListaProductos::IngresandoProducto(string id, string categoria, double precio, string nombre, string desconocido) {
    NodoProducto* nuevo = new NodoProducto();
    nuevo->id = id;
    nuevo->categoria = categoria;
    nuevo->precio = precio;
    nuevo->nombre = nombre;
    nuevo->desconocido = desconocido;
    if (principio1 == NULL) {
        principio1 = nuevo;
    } else {
        NodoProducto*temp = principio1;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevo;
    }
}

void ListaProductos::MostrarProducto() {
    NodoProducto*temp = principio1;
    int contador=1;
    while (temp != NULL) {
        cout << contador << ") "<< "El producto es: " << temp->nombre << " Precio: " << temp->precio << endl;
        temp = temp->siguiente;
        contador++;
    }
}
