
#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <string>
using namespace std;

class ListaUsuarios {
    int contador=0;
public:
    ListaUsuarios();
    void Ingresar(string, string, int, int);
    bool BuscarUsuario(string);
    void MostrarElementos();

};

#endif /* LISTAUSUARIOS_H */

