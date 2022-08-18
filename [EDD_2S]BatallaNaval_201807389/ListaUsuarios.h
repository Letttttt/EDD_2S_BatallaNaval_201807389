
#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <string>
using namespace std;

class ListaUsuarios {
public:
    ListaUsuarios();
    void Ingresar(string, string, int, int);
    bool BuscarUsuario(string);

};

#endif /* LISTAUSUARIOS_H */

