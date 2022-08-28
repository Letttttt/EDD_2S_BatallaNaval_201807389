#include "ListaUsuarios.h"
#include <iostream>
#include <string>

void ListaUsuarios::Ingresar(string Nickname, string Password, int Monedas, int Edad) {
    Usuario* ingresando = new Usuario();
    ingresando->Nickname = Nickname;
    ingresando->Password = sha256(Password);
    ingresando->Monedas = Monedas;
    ingresando->Edad = Edad;
    NodoUsuario* nuevo = new NodoUsuario();
    nuevo->user = ingresando;
    ingresando = NULL;

    if (principio == NULL) {
        principio = ultimo = nuevo;
        principio->siguiente = ultimo;
        ultimo->atras = principio;
        contador++;

    } else {

        if (BuscarUsuario(Nickname) == false) {
            ultimo->siguiente = nuevo;
            nuevo->atras = ultimo;
            ultimo = nuevo;
            principio->atras = ultimo;
            contador++;
        }
    }
}

bool ListaUsuarios::BuscarUsuario(string Nickname) {
    NodoUsuario*temp = principio;
    int cont = 0;
    while (cont < contador) {
        if (temp->user->Nickname == Nickname) {
            return true;
        }
        cont++;
        temp = temp->siguiente;
    }
    return false;

}

void ListaUsuarios::MostrarElementos() {
    NodoUsuario*temp = principio;
    int cont = 0;
    while (cont < contador) {
        cout << temp->user->Nickname << " " << temp->user->Password << endl;
        cont++;
        temp = temp->siguiente;
    }
}

NodoUsuario* ListaUsuarios::VerificarLogin(string nick, string pass) {
    NodoUsuario*temp = principio;
    int cont = 0;
    while (cont < contador) {
        if (temp->user->Nickname == nick && temp->user->Password == sha256(pass)) {
            return temp;
        }
        cont++;
        temp = temp->siguiente;
    }
    return NULL;
} 