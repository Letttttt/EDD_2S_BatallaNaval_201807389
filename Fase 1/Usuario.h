
#ifndef USUARIO_H
#define USUARIO_H
#include <string>
#include "ListaMovimientos.h"

using namespace std;

class Usuario {
public:
    string Nickname;
    string Password;
    int Monedas;
    int Edad;
    ListaMovimientos movimientos;

    Usuario() {
    }

private:

};

#endif /* USUARIO_H */

