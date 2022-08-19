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
        bool existe= false;
        while(temp!=NULL){
            if(temp->NombreCategoria==categoria){
                temp->productos->IngresandoProducto(id, categoria, precio, nombre, desconocido);
                existe = true;
                break;
            }
            temp=temp->siguiente;    
        }
        if(!existe){
            nuevo->productos->IngresandoProducto(id, categoria, precio, nombre, desconocido);
            temp->siguiente= nuevo;
        }
    }
}

