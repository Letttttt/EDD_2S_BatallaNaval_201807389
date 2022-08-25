#ifndef MENU_H
#define MENU_H
#include "ListaUsuarios.h"
#include "Tienda.h"
#include "ListaMovimientos.h"


using namespace std;


class Menu {
    ListaUsuarios*usuarios=new ListaUsuarios();
Tienda*productos=new Tienda();
ListaMovimientos*tutorial=new ListaMovimientos();
public:
    
    Menu();
    void Mostrar();
private:

};

#endif /* MENU_H */

