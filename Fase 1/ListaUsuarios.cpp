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
    cout << "Empezando a elaborar la imágen..." << endl;
    string grafica = "digraph G{\n node[shape=box3d];\n rankdir=\"LR\"; \n label=\"Usuarios\";";
    string nodos;
    string ruta;
    NodoUsuario*temp = principio;
    int cont = 0;
    while (cont < contador) {
        cout << "Generando nodos..." << endl;
        nodos += "node" + to_string(cont) + "[label=\"Nickname: " + temp->user->Nickname + "\n Contraseña: " + temp->user->Password + "\n Edad: " + to_string(temp->user->Edad) + "\"];\n";
        if ((cont + 1) < contador) {
            ruta += "node" + to_string(cont) + "->node" + to_string(cont + 1) + " [dir=\"both\"];\n";
        } else {
            ruta += "node" + to_string(cont) + "->node0" + " [dir=\"both\"];\n";
        }
        cont++;
        temp = temp->siguiente;
    }
    grafica += nodos + ruta + "}";
    cout << "Generando imágen PNG..." << endl;
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

void ListaUsuarios::OrdenamientoDes() {
    NodoUsuario*temp = principio;
    int cont = 0;
    while (cont < contador) {
        NodoUsuario*temp2 = principio;
        int cont2 = 0;
        while (cont2 < contador) {
            cout << "Ordenando usuario..." << endl;
            if (temp != temp2 && temp->user->Edad > temp2->user->Edad) {
                Usuario* aux = temp->user;
                temp->user = temp2->user;
                temp2->user = aux;
                aux = NULL;
            }
            cont2++;
            temp2 = temp2->siguiente;
        }
        cont++;
        temp = temp->siguiente;
    }
}

void ListaUsuarios::OrdenamientoAsc() {
    NodoUsuario*temp = principio;
    int cont = 0;
    while (cont < contador) {
        NodoUsuario*temp2 = principio;
        int cont2 = 0;
        while (cont2 < contador) {
            cout << "Ordenando usuario..." << endl;
            if (temp != temp2 && temp->user->Edad < temp2->user->Edad) {
                Usuario* aux = temp->user;
                temp->user = temp2->user;
                temp2->user = aux;
                aux = NULL;
            }
            cont2++;
            temp2 = temp2->siguiente;
        }
        cont++;
        temp = temp->siguiente;
    }
}