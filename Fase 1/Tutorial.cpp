
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
        temp->siguiente = nuevo;
    }
}

void Tutorial::MostrarTutorial() {
    Nodo*temp = principio2;
    while (temp != NULL) {
        cout << "Coordenadas: " << temp->x << " " << temp->y << endl;
        temp = temp->siguiente;
    }
}
