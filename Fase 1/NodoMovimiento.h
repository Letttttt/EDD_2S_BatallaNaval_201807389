#ifndef NODOMOVIMIENTO_H
#define NODOMOVIMIENTO_H
#include <string>
#include "Pila.h"

using namespace std;

class NodoMovimiento {
public:
    string NombreMovimiento;
    Pila* movimientos;
    NodoMovimiento* siguiente;

    NodoMovimiento() {
        siguiente = NULL;
    }
};
#endif /* NODOMOVIMIENTO_H */

