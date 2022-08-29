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
            case 1:
            {

                cout << "\n Ingrese el nombre del archivo: ";
                cin>>ruta;
                cout << ruta << endl;
                ifstream archivo(ruta);
                Json::Value datosJson;
                Json::Reader lector;
                lector.parse(archivo, datosJson);
                const Json::Value users = datosJson["usuarios"];
                const Json::Value productoTienda = datosJson["articulos"];
                const Json::Value movimientos = datosJson["tutorial"]["movimientos"];

                for (int i = 0; i < users.size(); ++i) {
                    cout << "Ingresando usuario..." << endl;
                    usuarios->Ingresar(users[i]["nick"].asString(), users[i]["password"].asString(), stoi(users[i]["monedas"].asString()), stoi(users[i]["edad"].asString()));

                }

                for (int i = 0; i < productoTienda.size(); ++i) {
                    cout << "Ingresando producto..." << endl;
                    productos->IngresandoProductoT(productoTienda[i]["id"].asString(), productoTienda[i]["categoria"].asString(), stod(productoTienda[i]["precio"].asString()), productoTienda[i]["nombre"].asString(), productoTienda[i]["src"].asString());
                }
                cout << "Ingresando tutorial..." << endl;
                tutorial->IngresandoTutorial(stoi(datosJson["tutorial"]["ancho"].asString()), stoi(datosJson["tutorial"]["alto"].asString()));
                for (int i = 0; i < movimientos.size(); ++i) {
                    cout << "Ingresando datos de tutorial..." << endl;
                    tutorial->IngresandoTutorial(stoi(movimientos[i]["x"].asString()), stoi(movimientos[i]["y"].asString()));
                }
                break;
            }
            case 2:
            {
                RegistrarUsuario();
                break;

            }
            case 3:
            {
                Login();
                break;
            }
            case 4:
            {
                Reportes();
                break;
            }
            case 5:
            {
                cout << "\n\n El programa finalizó. \n\n";
                break;
            }
            default:
            {
                cout << "\n\n Por favor, ingrese una opción correcta: \n\n";
            }
        }
    } while (opcion != 5);
}

void Menu::RegistrarUsuario() {
    int opcion;
    string nick;
    string pass;
    int edad;
    string registro;
    string respuesta1 = "si";
    string respuesta2 = "no";


    do {
        cout << "***  Registrando usuario  ***" << endl;
        cout << "Escriba su Nickname: ";
        cin >> nick;
        cout << nick << endl;
        cout << "Escriba su edad: ";
        cin >> edad;
        cout << edad << endl;
        cout << "Escriba su contraseña: " << endl;
        cin >> pass;
        cout << "\n#¿Estás seguro de los datos ingresados?#";
        cout << "\n#                                      #";
        cout << "\n# Si                                   #";
        cout << "\n# No                                   #";
        cout << "\n#**************************************#";
        cout << "\n\n Ingrese una opción: ";
        cin >> registro;
        cout << registro << endl;
        if (strcasecmp(registro.c_str(), respuesta1.c_str()) == 0 || strcasecmp(registro.c_str(), respuesta2.c_str()) == 0) {
            if (strcasecmp(registro.c_str(), respuesta1.c_str()) == 0) {
                usuarios->Ingresar(nick, pass, 0, edad);
            } else {
                opcion = 2;
            }
        } else {
            opcion = 2;
            cout << "No escriba opciones fuera de rango." << endl;
        }
        if (opcion != 2) {
            cout << "\n#*** ¿Desea registrar otro usuario? ***#";
            cout << "\n#                                      #";
            cout << "\n# 1. Sí                                #";
            cout << "\n# 2. No                                #";
            cout << "\n#**************************************#";
            cout << "\n\n Ingrese una opción: ";
            cin >> opcion;
            cout << opcion << endl;
        }

        if (opcion < 0 || opcion > 2) {
            cout << "No escriba opciones fuera de rango." << endl;

        }
    } while (opcion != 2);
}

void Menu::Login() {
    bool sesion = false;
    string decision;
    string nick;
    string pass;
    int edad;
    NodoUsuario* auxsesion;
    int opcion;

    do {
        cout << "***  Login  ***" << endl;
        cout << "Escriba el usuario: ";
        cin >> nick;
        cout << nick << endl;
        cout << "Escriba su contraseña: " << endl;
        cin >> pass;
        auxsesion = usuarios->VerificarLogin(nick, pass);
        if (auxsesion == NULL) {
            cout << "Fallo de credenciales." << endl;
            cout << "\n#***** ¿Desea intentar logearse? ******#";
            cout << "\n#                                      #";
            cout << "\n# 1. Sí                                #";
            cout << "\n# 2. No                                #";
            cout << "\n#**************************************#";
            cout << "\n\n Ingrese una opción: ";
            cin >> opcion;
            cout << opcion << endl;
            if (opcion < 0 || opcion > 2) {
                cout << "No escriba opciones fuera de rango." << endl;

            } else if (opcion == 2) {
                sesion = true;
            }


        } else {
            sesion = true;
        }
    } while (sesion == false);

    if (auxsesion != NULL) {
        do {
            cout << "\n#    Usuario: " + auxsesion->user->Nickname;
            cout << "\n#                                     #";
            cout << "\n# 1. Editar información               #";
            cout << "\n# 2. Eliminar cuenta                  #";
            cout << "\n# 3. Ver tutorial                     #";
            cout << "\n# 4. Ver articulos de la tienda       #";
            cout << "\n# 5. Realizar movimientos             #";
            cout << "\n# 6. Salir al menu principal          #";
            cout << "\n#*************************************#";
            cout << "\n\n Ingrese una opción: ";
            cin >> opcion;
            cout << opcion << endl;

            switch (opcion) {
                case 1:
                {
                    cout << "\n#******* ¿Qué desea modificar? ********#";
                    cout << "\n#                                      #";
                    cout << "\n# 1. Nickname                          #";
                    cout << "\n# 2. Edad                              #";
                    cout << "\n# 3. Contraseña                        #";
                    cout << "\n#**************************************#";
                    cout << "\n\n Ingrese una opción: ";
                    cin >> opcion;
                    cout << opcion << endl;

                    switch (opcion) {
                        case 1:
                        {
                            cout << "Escriba el nuevo Nickname: ";
                            cin >> nick;
                            cout << nick << endl;
                            auxsesion->user->Nickname = nick;
                            break;
                        }
                        case 2:
                        {
                            cout << "Escriba la nueva edad: ";
                            cin >> edad;
                            cout << edad << endl;
                            auxsesion->user->Edad = edad;
                            break;

                        }
                        case 3:
                        {
                            cout << "Escriba la nueva contraseña: ";
                            cin >> pass;
                            cout << pass << endl;
                            auxsesion->user->Password = sha256(pass);
                            break;
                        }
                        default:
                        {
                            cout << "\n\n Por favor, ingrese una opción correcta: \n\n";
                        }

                    }

                    break;
                }
                case 2:
                {
                    cout << "\n#¿Está seguro que quiere eliminar la cuenta?#";
                    cout << "\n#                                           #";
                    cout << "\n# 1. Sí                                     #";
                    cout << "\n# 2. No                                     #";
                    cout << "\n#*******************************************#";
                    cout << "\n\n Ingrese una opción: ";
                    cin >> opcion;
                    cout << opcion << endl;
                    if (opcion < 0 || opcion > 2) {
                        cout << "No escriba opciones fuera de rango." << endl;
                    } else if (opcion == 1) {
                        opcion = 6;
                        usuarios->contador--;
                        if (auxsesion == usuarios->principio) {
                            if (usuarios->principio->siguiente != usuarios->principio) {
                                usuarios->principio = usuarios->principio->siguiente;
                                usuarios->ultimo->siguiente = usuarios->principio;
                                usuarios->principio->atras = usuarios->ultimo;
                            } else {
                                usuarios->principio = NULL;
                                usuarios->ultimo = NULL;
                            }
                        } else if (auxsesion == usuarios->ultimo) {
                            usuarios->ultimo = usuarios->ultimo->atras;
                            usuarios->principio->atras = usuarios->ultimo;
                            usuarios->ultimo->siguiente = usuarios->principio;
                        } else {
                            NodoUsuario* auxatras = auxsesion->atras;
                            NodoUsuario* auxsiguiente = auxsesion->siguiente;
                            auxatras->siguiente = auxsiguiente;
                            auxsiguiente->atras = auxatras;
                        }
                        auxsesion = NULL;
                    }

                    break;

                }
                case 3:
                {
                    tutorial->MostrarTutorial();
                    break;
                }
                case 4:
                {
                    productos->MostrarTienda();
                    break;
                }
                case 5:
                {
                    int x;
                    int y;
                    auxsesion->user->Monedas++;
                    Pila* nuevom = new Pila();
                    do {
                        cout << " *** Escriba sus coordenadas: " << endl;
                        cout << "Ingrese coordenada en x: ";
                        cin >> x;
                        cout << x << endl;
                        cout << "Ingrese coordenada en y: ";
                        cin >> y;
                        cout << y << endl;
                        nuevom->IngresandoPila(x, y);
                        cout << " *** ¿Desea ingresar otra coordenada?" << endl;
                        cout << "1. Si" << endl;
                        cout << "2. No" << endl;
                        cin >> opcion;
                        cout << "La opción es: ";
                        cout << opcion << endl;
                    } while (opcion != 2);
                    cout << "Escriba el nombre de los movimientos: ";
                    cin >> decision;
                    cout << decision << endl;
                    auxsesion->user->movimientos.IngresandoMovimientos(decision, nuevom);
                    cout << "Su listado de movimientos se acaba de actualizar ..." << endl;
                    auxsesion->user->movimientos.MostrarMovimientos();
                    nuevom = NULL;
                    break;
                }
                default:
                {
                    cout << "\n\n Por favor, ingrese una opción correcta: \n\n";
                }

            }
        } while (opcion != 6);
    }
}

void Menu::Reportes() {
    int opcion;
    do {
        cout << "\n#*********** SECCIÓN DE REPORTES ***********#";
        cout << "\n#                                           #";
        cout << "\n# 1. Estructuras graficadas                 #";
        cout << "\n# 2. Lista usuarios ordenados               #";
        cout << "\n# 3. Lista articulos ordenados              #";
        cout << "\n# 4. Salir                                  #";
        cout << "\n#*******************************************#";
        cout << "\n\n Ingrese una opción: ";
        cin >> opcion;
        cout << opcion << endl;
        switch (opcion) {
            case 1:
            {
                usuarios->Graficando();
                tutorial->Graficando();
                productos->Graficando();
                break;
            }
            case 2:
            {
                do {
                    cout << "***      USUARIOS";
                    cout << "\n#Seleccione el ordenamiento que desea ver la lista#";
                    cout << "\n#                                                 #";
                    cout << "\n# 1. Forma ascendente                             #";
                    cout << "\n# 2. Forma descendente                            #";
                    cout << "\n# 3. Regresar al menú principal                   #";
                    cout << "\n#*************************************************#";
                    cout << "\n\n Ingrese una opción: ";
                    cin >> opcion;
                    cout << opcion << endl;
                    if (opcion < 0 || opcion > 3) {
                        cout << "No escriba opciones fuera de rango." << endl;
                    } else if (opcion == 1) {
                        usuarios->OrdenamientoAsc();
                        usuarios->Graficando();
                    } else if (opcion == 2) {
                        usuarios->OrdenamientoDes();
                        usuarios->Graficando();
                    }
                } while (opcion != 3);

                break;
            }
            case 3:
            {
                do {
                    cout << "***      ARTICULOS";
                    cout << "\n#Seleccione el ordenamiento que desea ver la lista#";
                    cout << "\n#                                                 #";
                    cout << "\n# 1. Forma ascendente                             #";
                    cout << "\n# 2. Forma descendente                            #";
                    cout << "\n# 3. Regresar al menú principal                   #";
                    cout << "\n#*************************************************#";
                    cout << "\n\n Ingrese una opción: ";
                    cin >> opcion;
                    cout << opcion << endl;
                    if (opcion < 0 || opcion > 3) {
                        cout << "No escriba opciones fuera de rango." << endl;
                    } else if (opcion == 1) {
                        productos->ReordenandoAsc();
                        productos->Graficando();
                    } else if (opcion == 2) {
                        productos->ReordenandoDes();
                        productos->Graficando();
                    }
                } while (opcion != 3);
                break;
            }
            case 4:
            {
                cout << "\n Regresando al menú principal. \n";
                break;
            }
            default:
            {
                cout << "\n\n Por favor, ingrese una opción correcta: \n\n";
            }
        }
    } while (opcion != 4);

}