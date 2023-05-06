//Jeferson Alexis Suchite Chavez 0909-22-12681
#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

void crearArchivos(int cantidad);
int contarArchivosDeDirectorio();
void listarArchivosDeDirectorio();
void mostrarDetalles();
void buscarArchivosPorNombre(std::string nombreArchivo);

using namespace std;

int main()
{
    int cantidad;
    string nombreArchivo;
    cout<<"Hola, Bienvenido a tu Asistente de Creacion de Archivos \n";
    cout << "Cuantos archivos quiere crear \n";
    cin >> cantidad;
    crearArchivos(cantidad);

    return 0;
}

void crearArchivos(int cantidad) {
    string nombreArchivo="archivo";
    if(cantidad %2==0){
    int i= cantidad;

    for(i=0; i<cantidad; i++){
        ofstream file;
        file.open("C:/Users/Usuario/Documents/par/" + nombreArchivo + to_string(i) +".txt");
        file << "Texto De Prueba\n";
        file << "Hola, Mucho Gusto\n";
        file << "Mi nombre es Jack\n";
        file.close();
    }
    cout<<"Archivos creados : " + to_string(i);
}else{
        int i= cantidad;

        for(i=0; i<cantidad; i++){
            ofstream file;
            file.open("C:/Users/Usuario/Desktop/impar/" + nombreArchivo + to_string(i) +".txt");
            file << "Texto De Prueba\n";
            file << "Hola, Mucho Gusto\n";
            file << "Mi nombre es Jack\n";
            file.close();
        }
        cout<<"Archivos creados : " + to_string(i);

    }
}