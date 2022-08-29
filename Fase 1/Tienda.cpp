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
    cout << " ***  Bienvenido a Tienda  *** " << endl;
    cout << " ***  Observe nuestros artículos por categoría: " << endl;
    cout << " --------------------------------------------------- " << endl;
    while (temp != NULL) {
        cout << "La categoria es: " << temp->NombreCategoria << endl;
        temp->productos.MostrarProducto();
        temp = temp->siguiente;
    }
}

void Tienda::Graficando() {
    cout << "Empezando a elaborar la imágen..." << endl;
    string grafica = "digraph G{\n node[shape=box3d];\n label=\"Artículos\";";
    string nodos;
    string ruta;
    string rank;
    int cont = 0;
    string nodo2;
    string ruta2;
    NodoCategoria* temp = principio3;
    while (temp != NULL) {
        cout << "Generando nodos de las categorías..." << endl;
        nodos += "node" + to_string(cont) + "[label=\"Categoría: " + temp->NombreCategoria + "\" group=1];\n";
        if (temp->siguiente != NULL) {
            ruta += "node" + to_string(cont) + "->node" + to_string(cont + 1) + ";\n";
        }
        if (temp->productos.principio1 != NULL) {
            rank += "{rank=same; node" + to_string(cont) + ";"; //colocar en fila 
            ruta2 += "node" + to_string(cont) + "->nodo" + temp->productos.principio1->id + ";\n";
            NodoProducto*temporal = temp->productos.principio1;
            while (temporal != NULL) {
                cout << "Generando nodos de los productos de la categoría..." << endl;
                nodo2 += "nodo" + temporal->id + "[label=\"Producto: " + temporal->nombre + "\nPrecio: " + to_string((round(temporal->precio * 100.0)) / 100.0) + "\"];\n";
                rank += "nodo" + temporal->id + ";";
                if (temporal->siguiente != NULL) {
                    ruta2 += "nodo" + temporal->id + "->nodo" + temporal->siguiente->id + ";\n";
                }
                temporal = temporal->siguiente;
            }
            rank += "}\n";
            grafica += nodos + ruta + nodo2 + ruta2 + rank;
            ruta2 = "";
            nodo2 = "";
            rank = "";
            nodos = "";
            ruta = "";
        }
        temp = temp->siguiente;
        cont++;
    }
    grafica += "}";
    cout << "Generando imágen PNG..." << endl;
    ofstream mostrargrafica;
    mostrargrafica.open("ReporteArticulos.dot", ios::out);
    if (mostrargrafica.fail()) {
        cout << "No se creó el archivo.";
        exit(1);
    }
    mostrargrafica << grafica;
    mostrargrafica.close();
    system("dot -Tpng ReporteArticulos.dot -o ReporteArticulos.png");
}

float Tienda::round(float var) {
    float value = (int(var * 100 + .5));
    return (float) value / 100;
}

void Tienda::ReordenandoAsc() {
    NodoCategoria* temp = principio3;
    while (temp != NULL) {
        cout << "Ordenando productos de la categoría..." << endl;
        temp->productos.OrdenamientoAsc();
        temp = temp->siguiente;
    }
}

void Tienda::ReordenandoDes() {
    NodoCategoria* temp = principio3;
    while (temp != NULL) {
        cout << "Ordenando productos de la categoría..." << endl;
        temp->productos.OrdenamientoDes();
        temp = temp->siguiente;
    }
}