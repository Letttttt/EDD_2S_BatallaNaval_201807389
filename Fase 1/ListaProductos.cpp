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
    int contador = 1;
    while (temp != NULL) {
        cout << contador << ") " << "El producto es: " << temp->nombre << " Precio: " << ((round(temp->precio * 100.0)) / 100.0) << endl;
        temp = temp->siguiente;
        contador++;
    }
}

float ListaProductos::round(float var) {
    float value = (int(var * 100 + .5));
    return (float) value / 100;
}

void ListaProductos::OrdenamientoAsc() {
    NodoProducto*temp = principio1;
    while (temp != NULL) {
        NodoProducto*temp2 = principio1;
        while (temp2 != NULL) {
            cout << "Ordenando producto..." << endl;
            if (temp != temp2 && temp->precio < temp2->precio) {
                string id = temp->id;
                double precio=temp->precio;
                string nombre=temp->nombre;
                string desconocido=temp->desconocido;
                temp->id=temp2->id;
                temp->precio=temp2->precio;
                temp->nombre=temp2->nombre;
                temp->desconocido=temp2->desconocido;
                temp2->id=id;
                temp2->precio=precio;
                temp2->nombre=nombre;
                temp2->desconocido=desconocido;
            }
            temp2 = temp2->siguiente;
        }
        temp = temp->siguiente;
    }
}

void ListaProductos::OrdenamientoDes() {
    NodoProducto*temp = principio1;
    while (temp != NULL) {
        NodoProducto*temp2 = principio1;
        while (temp2 != NULL) {
            cout << "Ordenando producto..." << endl;
            if (temp != temp2 && temp->precio > temp2->precio) {
                string id = temp->id;
                double precio=temp->precio;
                string nombre=temp->nombre;
                string desconocido=temp->desconocido;
                temp->id=temp2->id;
                temp->precio=temp2->precio;
                temp->nombre=temp2->nombre;
                temp->desconocido=temp2->desconocido;
                temp2->id=id;
                temp2->precio=precio;
                temp2->nombre=nombre;
                temp2->desconocido=desconocido;
            }
            temp2 = temp2->siguiente;
        }
        temp = temp->siguiente;
    }
}