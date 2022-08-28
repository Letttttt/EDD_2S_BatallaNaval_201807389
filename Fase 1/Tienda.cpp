#include "Tienda.h"
#include <string>

void Tienda::IngresandoProductoT(string id, string categoria, double precio, string nombre, string desconocido) {
    if (principio3 == NULL) {
        NodoCategoria* nuevo = new NodoCategoria();
        nuevo->NombreCategoria = categoria;
        nuevo->productos.IngresandoProducto(id, categoria, precio, nombre, desconocido);
        principio3 = nuevo;
    } else {
        NodoCategoria* temp = principio3;
        while (temp->siguiente != NULL) {
            if (temp->NombreCategoria == categoria) {
                temp->productos.IngresandoProducto(id, categoria, precio, nombre, desconocido);
                break;
            }
            temp = temp->siguiente;
        }
        if (temp->siguiente == NULL && temp->NombreCategoria == categoria) {
            temp->productos.IngresandoProducto(id, categoria, precio, nombre, desconocido);
        } else if (temp->siguiente == NULL && temp->NombreCategoria != categoria) {
            cout << temp->NombreCategoria << "- -" << categoria << endl;
            NodoCategoria* nuevo = new NodoCategoria();
            nuevo->NombreCategoria = categoria;
            nuevo->productos.IngresandoProducto(id, categoria, precio, nombre, desconocido);
            temp->siguiente = nuevo;
        }
    }
}
void Tienda::MostrarTienda() {
    NodoCategoria* temp = principio3;
    while (temp != NULL) {
        cout << "La categoria es: " << temp->NombreCategoria << endl;
        temp->productos.MostrarProducto();
        temp = temp->siguiente;
    }
}

