#include "Tienda.h"
#include <string>
#include "ListaProductos.h"

struct NodoCategoria{
    string NombreCategoria;
    ListaProductos*productos=new ListaProductos();
    NodoCategoria* siguiente;
}*principio3;

Tienda::Tienda() {
}


void Tienda::IngresandoProducto(int id, string categoria, double precio, string nombre, string desconocido) {
    NodoCategoria* nuevo= new NodoCategoria();
    nuevo->NombreCategoria=categoria;    
    if(principio3== NULL) {
        nuevo->productos->IngresandoProducto(id, categoria, precio, nombre, desconocido);
        principio3=nuevo;
    }else{
        NodoCategoria* temp= principio3;
        while(temp->siguiente!=NULL){
            if(temp->NombreCategoria==categoria){
                temp->productos->IngresandoProducto(id, categoria, precio, nombre, desconocido);
                break;
            }
            temp=temp->siguiente;    
        }
        if(temp->siguiente==NULL && temp->NombreCategoria==categoria){
            temp->productos->IngresandoProducto(id, categoria, precio, nombre, desconocido);
        }else if(temp->siguiente==NULL && temp->NombreCategoria!=categoria){
        nuevo->productos->IngresandoProducto(id, categoria, precio, nombre, desconocido);
        temp->siguiente=nuevo;
        }
    }
}

