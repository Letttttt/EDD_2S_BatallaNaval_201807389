#ifndef NODOUSUARIO_H
#define NODOUSUARIO_H
#include <iostream>
#include "Usuario.h"

class NodoUsuario {
public:
    Usuario* user;
    NodoUsuario* siguiente;
    NodoUsuario* atras;

    NodoUsuario() {
        siguiente = atras = NULL;
    }
};

#endif /* NODOUSUARIO_H */

