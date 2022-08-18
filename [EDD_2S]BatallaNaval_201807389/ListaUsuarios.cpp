#include "ListaUsuarios.h"
#include <iostream>
#include <string>

struct Usuario {
    string Nickname;
    string Password;
    int Monedas;
    int Edad;
};

struct Nodo {
    Usuario user;
    Nodo* siguiente;
    Nodo* atras;
} *principio, *ultimo;

ListaUsuarios::ListaUsuarios() {
}

void ListaUsuarios::Ingresar(string Nickname, string Password, int Monedas, int Edad) {
    Usuario* ingresando = new Usuario();
    ingresando->Nickname = Nickname;
    ingresando->Password = Password;
    ingresando->Monedas = Monedas;
    ingresando->Edad = Edad;
    Nodo* nuevo = new Nodo();
    nuevo->user = ingresando;
    ingresando = NULL;

    if (principio == NULL) {
        principio = ultimo = nuevo;
        principio->siguiente = ultimo;
        ultimo->atras = principio;
    } else {
        if (!BuscarUsuario(Nickname)) {
            ultimo->siguiente = nuevo;
            nuevo->atras = ultimo;
            ultimo = nuevo;
            principio->atras = ultimo;
        }
    }
}

bool ListaUsuarios::BuscarUsuario(string Nickname) {
    Nodo*temp = principio;
    while (temp != NULL) {
        if (temp->user->Nickname == Nickname) {
            return true;
        }
    }
    return false;

}

