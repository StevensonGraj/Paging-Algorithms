/*  Author: Didier Stevenson Calvache Grajales
    Date: March 2021
    <didiermaxilo3@gmail.com>
 */
#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int main(){

    int i;
    int op=0;
    int cantmarcos;
    int referencias;
    char paginaActual;
    char *paginas;
    char *fallos;
    char *marcos;
    int *auxmarcos;
    char **tablaMarcos;

    while(op != 4){
        while(op > 4 || op < 1){
            cout << "Eliga el Algoritmo de Paginación que desea usar:\n" <<
                "1. FIFO\n"
                "2. LRU\n"
                "3. NRU\n"
                "4. Salir\n"
                "Ingrese el numero: ";
            cin >> op;

            if(op == 4){ break;}
            if (op > 4 || op < 1) {
                system("cls");
                cout << "\n\n\t\t=================== NO HA INGRESADO UNA OPCION VALIDA =================== \n\n";
            }
        }

        if (op == 4) { break; }
        
        cout << "\nAhora ingrese los MARCOS de Página que desea tener: ";
        cin >> cantmarcos;
        auxmarcos = new int[cantmarcos];
        marcos = new char[cantmarcos];
        
        cout << "\nIngrese la cantidad de REFERENCIAS de Páginas que desea tener: ";
        cin >> referencias;
        paginas = new char[referencias];
        fallos = new char[referencias];

        //Se crea la matriz para los marcos
        tablaMarcos = new char*[cantmarcos];
        for(i = 0; i < cantmarcos; i++){
            tablaMarcos[i] = new char [referencias];
        }

        //INGRESA LAS REFERENCIAS DE PAG 1 A 1
        for (i = 0; i < referencias; i++){
            cout << "\nIngrese la REFERENCIA #"<<i+1<<": ";
            cin >> paginaActual;
            paginas[i] = paginaActual;
        }

        int menor = 0;

        switch(op){
            case 1:
                cout << "========================== FIFO ==========================";
                cout << "\nTiempo: \t";
                for (i = 0; i < referencias; i++){
                    cout << i + 1 << "\t";
                }

                cout << "\nReferencia: \t";
                for (i = 0; i < referencias; i++){
                    cout << paginas[i] << "\t";
                }
                cout << "\n";

                for(i = 0; i < referencias; i++){
                    for(int i2 = 0; i2 < cantmarcos; i2++){
                        paginaActual = paginas[i];
                        bool esta = false;
                        for(int j = 0; j < cantmarcos; j++){
                            if(marcos[j] == paginaActual){
                                esta = true;
                            }
                        }
                        if(esta){
                            break;
                        }
                        
                        for(int j = 0; j < cantmarcos; j++){
                            if (auxmarcos[menor] > auxmarcos[j]){
                                menor = j;
                            }
                        }
                        marcos[menor] = paginaActual;
                        auxmarcos[menor] = i;
                        fallos[i] = 'F';

                        for(int k = i;  k < referencias ;  k++){
                            tablaMarcos[menor][k] = paginaActual;
                        }
                    }
                }
                for(i = 0; i < cantmarcos; i++){
                    cout << "\nM" << i+1<< "\t\t";
                    for (int i2 = 0; i2 < referencias; i2++){
                        cout << tablaMarcos[i][i2] << "\t";
                    }
                }

                cout << "\n\nFallos: \t";
                for (i = 0; i < referencias; i++){
                    cout << fallos[i] << "\t";
                }
                cout << "\n";

                break;
            case 2:
                cout << "========================== LRU ==========================";
                cout << "\nTiempo: \t";
                for (i = 0; i < referencias; i++) {
                    cout << i + 1 << "\t";
                }

                cout << "\nReferencia: \t";
                for (i = 0; i < referencias; i++) {
                    cout << paginas[i] << "\t";
                }
                cout << "\n";

                for(i = 0; i < referencias; i++){
                    for(int i2 = 0; i2 < cantmarcos; i2++){
                        paginaActual = paginas[i];

                        bool esta = false;
                        for(int j = 0; j < cantmarcos; j++) {
                            if (marcos[j] == paginaActual) {
                                esta = true;
                                menor = j;
                            }
                        }
                        if(esta){
                            auxmarcos[menor] += 1;
                            break;
                        }

                        for(int j = 0; j < cantmarcos; j++){
                            if(auxmarcos[menor] > auxmarcos[j]){
                                menor = j;
                            }
                        }
                        marcos[menor] = paginaActual;
                        
                        auxmarcos[menor] += 1;
                        fallos[i] = 'F';

                        for (int k = i; k < referencias; k++) {
                            tablaMarcos[menor][k] = paginaActual;
                        }
                        break;
                    }
                }
                for (i = 0; i < cantmarcos; i++) {
                    cout << "\nM" << i + 1 << "\t\t";
                    for (int i2 = 0; i2 < referencias; i2++) {
                        cout << tablaMarcos[i][i2] << "\t";
                    }
                }

                cout << "\n\nFallos: \t";
                for (i = 0; i < referencias; i++) {
                    cout << fallos[i] << "\t";
                }
                cout << "\n";

                break;
            case 3:
                for(i = 0; i < cantmarcos; i++){
                    auxmarcos[i] = -1;
                }
                
                cout << "========================== NRU ==========================";
                cout << "\nTiempo: \t";
                for (i = 0; i < referencias; i++){
                    cout << i + 1 << "\t";
                }

                cout << "\nReferencia: \t";
                for (i = 0; i < referencias; i++){
                    cout << paginas[i] << "\t";
                }
                cout << "\n";

                for(i = 0; i < referencias; i++){
                    for(int i2 = 0; i2 < cantmarcos; i2++){
                        paginaActual = paginas[i];

                        bool esta = false;
                        for(int j = 0; j < cantmarcos; j++){
                            if (marcos[j] == paginaActual){
                                menor = j;
                                esta = true;
                            }
                        }
                        if(esta){
                            for(int j = 0; j < cantmarcos; j++){
                            if(auxmarcos[j] == -1){
                            }else{
                                auxmarcos[j] -= 1;
                                if(auxmarcos[j] == 0){
                                    auxmarcos[j] = 1;
                                }
                            }
                        }
                            auxmarcos[menor] = 4;
                            break;
                        }
                        for(int j = 0; j < cantmarcos; j++){
                            if(auxmarcos[menor] > auxmarcos[j]){
                                menor = j;
                            }
                        }
                        marcos[menor] = paginaActual;

                        for(int j = 0; j < cantmarcos; j++){
                            if(auxmarcos[j] == -1){
                            }else{
                                auxmarcos[j] -= 1;
                                if(auxmarcos[j] == 0){
                                    auxmarcos[j] = 1;
                                }
                            }
                        }
                        auxmarcos[menor] = 4;
                        fallos[i] = 'F';

                        for (int k = i; k < referencias; k++){
                            tablaMarcos[menor][k] = paginaActual;
                        }
                        break;
                    }
                }
                for(i = 0; i < cantmarcos; i++){
                    cout << "\nM" << i + 1 << "\t\t";
                    for (int i2 = 0; i2 < referencias; i2++){
                        cout << tablaMarcos[i][i2] << "\t";
                    }
                }

                cout << "\n\nFallos: \t";
                for(i = 0; i < referencias; i++){
                    cout << fallos[i] << "\t";
                }
                cout << "\n";
                break;
        default:
            break;
        }

        op = 0;
        system("pause");
        system("cls");
    }
}