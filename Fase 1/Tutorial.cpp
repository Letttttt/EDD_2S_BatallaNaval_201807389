
#include "Tutorial.h"
#include <string>
using namespace std;

struct Nodo{
    int x;
    int y;
    Nodo* siguiente;
}*principio2;

Tutorial::Tutorial() {
}

void Tutorial::IngresandoTutorial(int x, int y) {
    Nodo* nuevo= new Nodo();
    nuevo->x=x;
    nuevo->y=y;
    if(principio2==NULL){
        principio2=nuevo;
    }else{
        Nodo*temp= principio2;
        while(temp->siguiente!=NULL){
            temp=temp->siguiente;
        }
        temp->siguiente=nuevo;
    }
}

