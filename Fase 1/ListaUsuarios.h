
#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <string>
#include "Usuario.h"
#include "NodoUsuario.h"
#include "sha256.h"

using namespace std;

class ListaUsuarios {
    
public:
    int contador = 0;
    NodoUsuario*principio, *ultimo;

    ListaUsuarios() {
        principio = ultimo = NULL;
    }
    void Ingresar(string, string, int, int);
    bool BuscarUsuario(string);
    void MostrarElementos();
    NodoUsuario* VerificarLogin(string, string);

};

#endif /* LISTAUSUARIOS_H */

