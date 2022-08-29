
#include "Tutorial.h"
#include <string>

void Tutorial::IngresandoTutorial(int x, int y) {
    Nodo* nuevo = new Nodo();
    nuevo->x = x;
    nuevo->y = y;
    if (principio2 == NULL) {
        principio2 = nuevo;
    } else {
        Nodo*temp = principio2;
        while (temp->siguiente != NULL) {
            temp = temp->siguiente;
        }
        if (BuscarCoordenadas(x, y) == false) {
            temp->siguiente = nuevo;
        }
    }
}

void Tutorial::MostrarTutorial() {
    Nodo*temp = principio2;
    cout << "Dimensión: Ancho: " << temp->x << ", Alto: " << temp->y << endl;
    while (temp != NULL) {
        temp = temp->siguiente;
        if (temp != NULL) {
            cout << "Coordenadas: x: " << temp->x << ", y: " << temp->y << endl;
        }
    }
}

void Tutorial::Graficando() {
    cout << "Empezando a elaborar la imágen..." << endl;
    string grafica = "digraph G{\n node[shape=box3d];\n rankdir=\"LR\"; \n label=\"Tutorial\";";
    string nodos = "";
    string ruta = "";
    Nodo*temp = principio2;
    while (temp != NULL) {
        cout << "Generando los nodos del tutorial..." << endl;
        if (temp == principio2) {
            nodos += "nodeP[label=\"Dimensión de la tabla: \n Ancho: " + to_string(temp->x) + "\n Alto: " + to_string(temp->y) + "\"];\n";
            if (temp->siguiente != NULL) {
                nodos += "node" + to_string(temp->siguiente->x) + "_" + to_string(temp->siguiente->y) + "[label=\"Coordenada\n eje x: " + to_string(temp->siguiente->x) + "\n eje y: " + to_string(temp->siguiente->y) + "\"];\n";
                ruta = "nodeP->node" + to_string(temp->siguiente->x) + "_" + to_string(temp->siguiente->y) + ";\n";
                temp = temp->siguiente;
            }

        } else {
            nodos += "node" + to_string(temp->x) + "_" + to_string(temp->y) + "[label=\"Coordenada\n eje x: " + to_string(temp->x) + "\n eje y: " + to_string(temp->y) + "\"];\n";
        }
        if (temp->siguiente != NULL) {
            ruta += "node" + to_string(temp->x) + "_" + to_string(temp->y) + "->node" + to_string(temp->siguiente->x) + "_" + to_string(temp->siguiente->y) + ";\n";
        }
        temp = temp->siguiente;
    }
    grafica += nodos + ruta + "}";
    cout << "Generando imágen PNG..." << endl;
    ofstream mostrargrafica;
    mostrargrafica.open("ReporteTutorial.dot", ios::out);
    if (mostrargrafica.fail()) {
        cout << "No se creó el archivo.";
        exit(1);
    }
    mostrargrafica << grafica;
    mostrargrafica.close();
    system("dot -Tpng ReporteTutorial.dot -o ReporteTutorial.png");
}

bool Tutorial::BuscarCoordenadas(int x, int y) {
    Nodo*temp = principio2;
    while (temp != NULL) {
        temp = temp->siguiente;
        if (temp != NULL) {
            if (temp->x == x && temp->y == y) {
                return true;
            }

        }
    }
    return false;
}