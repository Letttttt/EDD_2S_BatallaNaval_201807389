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

void ListaUsuarios::Graficando() {
    string grafica = "digraph G{\n node[shape=box3d];\n rankdir=\"LR\"; \n label=\"Usuarios\";";
    string nodos;
    string ruta;
    NodoUsuario*temp = principio;
    int cont = 0;
    while (cont < contador) {
        nodos += "node" + cont + "[label=\"Nickname " + temp->user->Nickname + "\n Contraseña: " + temp->user->Password + "\n Edad: " + to_string(temp->user->Edad) + "\"];\n";
        if (temp->siguiente != principio) {
            ruta += "node" + to_string(cont) + "->node" + to_string(cont + 1) + ";\n";
        } else {
            ruta += "node" + to_string(cont) + "->node0" + ";\n";
        }
        cont++;
        temp = temp->siguiente;
    }
    grafica += nodos + ruta + "}";
    cout << grafica << endl;
    ofstream mostrargrafica;
    mostrargrafica.open("ReporteUsuario.dot", ios::out);
    if (mostrargrafica.fail()) {
        cout << "No se creó el archivo.";
        exit(1);
    }
    mostrargrafica << grafica;
    mostrargrafica.close();
    system("dot -Tpng ReporteUsuario.dot -o ReporteUsuario.png");



}