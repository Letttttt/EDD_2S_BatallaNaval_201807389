#include "Menu.h" 
#include <iostream>
#include <string>
#include <fstream>
#include "json/json.h"
#include "jsoncpp.cpp"

                


Menu::Menu() {
}

void Menu::Mostrar() {

    int opcion;
    string ruta;

    /*JSON probando;
    probando.parseFromFile("proyecto.json");
    probando.parse(probando.toString());
    cout << probando.toString() << endl;*/
    
    do {
        cout << "\n#**************** MENÚ ***************#";
        cout << "\n#                                     #";
        cout << "\n# 1. Carga Masiva de información      #";
        cout << "\n# 2. Registrar Usuario                #";
        cout << "\n# 3. Login                            #";
        cout << "\n# 4. Reportes                         #";
        cout << "\n# 5. Salir del juego                  #";
        cout << "\n#*************************************#";
        cout << "\n\n Ingrese una opción: ";
        cin >> opcion;
        cout << opcion << endl;
        switch (opcion) {
            case 1:{
                
                cout << "\n Ingrese el nombre del archivo: ";
                cin>>ruta;  
                cout << ruta<< endl;
                ifstream archivo(ruta);
                Json::Value datosJson;
                Json::Reader lector;
                lector.parse(archivo, datosJson);
                const Json::Value users = datosJson["usuarios"];
                const Json::Value productoTienda = datosJson["articulos"];
                const Json::Value movimientos= datosJson["tutorial"]["movimientos"];
                
                for(int i=0; i<users.size(); ++i){
                    cout << users[i]["nick"].asString()<< endl;
                    usuarios->Ingresar(users[i]["nick"].asString(), users[i]["password"].asString(), stoi(users[i]["monedas"].asString()), stoi(users[i]["edad"].asString()));
                    
                }
//                usuarios->MostrarElementos();
                for(int i=0; i<productoTienda.size(); ++i){
                    cout << productoTienda[i]["categoria"].asString()<< endl;
                    productos->IngresandoProducto(stoi(productoTienda[i]["id"].asString()),productoTienda[i]["categoria"].asString(), stod(productoTienda[i]["precio"].asString()),productoTienda[i]["nombre"].asString(), productoTienda[i]["src"].asString());
                }
                for(int i=0; i<movimientos.size(); ++i){
                    cout << movimientos[i]["x"].asString()<< endl;
                }
                
                break;
            }
            case 2:{
                cout << "\n\n Ingrese los datos del registro: \n\n";
                break;
                
            }
            case 3:{
                cout << "\n\n LOGIN \n\n";

                break;
            }
            case 4:{
                cout << "\n\n REPORTES \n\n";
                break;
            }
            case 5:{
                cout << "\n\n El programa finalizó. \n\n";
                break;
            }
            default:{
                cout << "\n\n Por favor, ingrese una opción correcta: \n\n";
            }
        }
    } while (opcion != 5);
}

