
#include "Pila.h"
#include <string>
using namespace std;

struct NodoPila{
    int x;
    int y;
    
    NodoPila* siguiente;
}*principio4;

Pila::Pila() {
}

void Pila::IngresandoPila(int x, int y) {
    NodoPila*nuevo=new NodoPila();
    nuevo->x=x;
    nuevo->y=y;
    if(principio4==NULL){
        principio4=nuevo;
    }else{
        nuevo->siguiente=principio4;
        principio4=nuevo;
    }
}

