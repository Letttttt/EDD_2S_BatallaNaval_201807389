#ifndef MENU_H
#define MENU_H
#include "ListaUsuarios.h"
#include "Tienda.h"
#include "Tutorial.h"


using namespace std;

class Menu {
    ListaUsuarios*usuarios = new ListaUsuarios();
    Tienda*productos = new Tienda();
    Tutorial*tutorial = new Tutorial();
public:
    Menu();
    void Mostrar();
private:

};

#endif /* MENU_H */

