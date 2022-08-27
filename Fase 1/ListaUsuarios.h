
#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <string>
#include "Usuario.h"
#include "NodoUsuario.h"

using namespace std;

class ListaUsuarios {
    int contador = 0;
public:
    NodoUsuario*principio, *ultimo;

    ListaUsuarios() {
        principio = ultimo = NULL;
    }
    void Ingresar(string, string, int, int);
    bool BuscarUsuario(string);
    void MostrarElementos();

};

#endif /* LISTAUSUARIOS_H */

