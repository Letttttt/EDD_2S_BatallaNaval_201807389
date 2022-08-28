#ifndef MENU_H
#define MENU_H
#include "ListaUsuarios.h"
#include "Tienda.h"
#include "Tutorial.h"
#include "Pila.h"
#include <cstring>

using namespace std;

class Menu {
    ListaUsuarios*usuarios = new ListaUsuarios();
    Tienda*productos = new Tienda();
    Tutorial*tutorial = new Tutorial();
public:
    Menu();
    void Mostrar();
    void RegistrarUsuario();
    void Login();
    void Reportes();
private:

};

#endif /* MENU_H */

