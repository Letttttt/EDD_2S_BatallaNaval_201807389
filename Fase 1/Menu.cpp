#include "Menu.h"
#include <iostream>
#include <string>
#include <fstream>
#include "dnc/JSON.hpp"

using namespace std;
using JSON = dnc::JSON;

Menu::Menu() {
}

void Menu::Mostrar() {

    int opcion;
    string ruta;

    JSON probando;
    probando.parseFromFile("proyecto.json");
    probando.parse(probando.toString());
    cout << probando.toString() << endl;
    
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
            case 1:
                cout << "\n\n Ingrese el nombre del archivo: \n\n";
                cin>>ruta;
                break;
            case 2:
                cout << "\n\n Ingrese los datos del registro: \n\n";
                break;
            case 3:
                cout << "\n\n LOGIN \n\n";

                break;
            case 4:
                cout << "\n\n REPORTES \n\n";
                break;
            case 5:
                cout << "\n\n El programa finalizó \n\n";
                break;
            default:
                cout << "\n\n Por favor, ingrese una opción correcta: \n\n";
        }
    } while (opcion != 5);
}

