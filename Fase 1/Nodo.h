#ifndef NODO_H
#define NODO_H
#include <iostream>
using namespace std;

class Nodo {
public:
    int x;
    int y;
    Nodo* siguiente;
    Nodo(){
        siguiente=NULL;
    }
};

#endif /* NODO_H */

