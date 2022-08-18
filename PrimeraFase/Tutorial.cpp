
#include "Tutorial.h"
#include <string>
using namespace std;

struct Nodo{
    int x;
    int y;
    Nodo* siguiente;
}*principio;

Tutorial::Tutorial() {
}

void Tutorial::IngresandoTutorial(int x, int y) {
    Nodo* nuevo= new Nodo();
    nuevo->x=x;
    nuevo->y=y;
    if(principio==NULL){
        principio=nuevo;
    }else{
        Nodo*temp= principio;
        while(temp->siguiente!=NULL){
            temp=temp->siguiente;
        }
        temp->siguiente=nuevo;
    }
}

