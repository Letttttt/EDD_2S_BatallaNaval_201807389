
#include "Pila.h"
#include <string>
using namespace std;

void Pila::IngresandoPila(int x, int y) {
    Nodo*nuevo=new Nodo();
    nuevo->x=x;
    nuevo->y=y;
    if(principio4==NULL){
        principio4=nuevo;
    }else{
        nuevo->siguiente=principio4;
        principio4=nuevo;
    }
}

void Pila::MostrarPila(){
    Nodo*temp=principio4;
    while(temp!=NULL){
        cout << "Coordenadas: " << temp->x +" " << temp->y << endl;
        temp=temp->siguiente;
    }
}


