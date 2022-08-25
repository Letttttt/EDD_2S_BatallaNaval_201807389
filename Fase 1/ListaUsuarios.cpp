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
    Usuario* user;
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
        contador++;
        
    } else {
        
        if (BuscarUsuario(Nickname)== false) {
            ultimo->siguiente = nuevo;
            nuevo->atras = ultimo;
            ultimo = nuevo;
            principio->atras = ultimo;
            contador++;
        }
    }
}

bool ListaUsuarios::BuscarUsuario(string Nickname) {
    Nodo*temp = principio;
    int cont=0;
    while (cont<contador) {
        if (temp->user->Nickname == Nickname) {
            return true;
        }
        cont++;
        temp=temp->siguiente;
    }
    return false;

}

void ListaUsuarios::MostrarElementos(){
Nodo*temp = principio;
    int cont=0;
    while (cont<contador) {
        cout << temp->user->Monedas <<"acá pasa"<< endl;
        cont++;
        temp=temp->siguiente;
    }
}

