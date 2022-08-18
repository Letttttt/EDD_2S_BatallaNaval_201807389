
#include "Pila.h"
#include <string>
using namespace std;

struct NodoPila{
    int x;
    int y;
    
    Nodo* siguiente;
}*principio;

Pila::Pila() {
}

void Pila::IngresandoPila(int x, int y) {
    NodoPila*nuevo=new NodoPila();
    nuevo->x=x;
    nuevo->y=y;
    if(principio==NULL){
        principio=nuevo;
    }else{
        nuevo->siguiente=principio;
        principio=nuevo;
    }
}

