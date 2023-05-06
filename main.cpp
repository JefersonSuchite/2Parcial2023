//Jeferson Alexis Suchite Chavez 0909-22-12681
#include <iostream>
#include <fstream>
#include <filesystem>
#include "windows.h"

void crearArchivos(int cantidad);
void buscarArchivosCreados(int cantidad);
void buscarArchivosPorNombre(std::string nombreArchivo);
std::string buscarArchivoMasPequeno();

using namespace std;

int main()
{
    int cantidad;
    string nombreArchivo;
    cout<<"Hola, Bienvenido a tu Asistente de Creacion de Archivos \n";
    cout << "Cuantos archivos quiere crear \n";
    cin >> cantidad;
    crearArchivos(cantidad);

    buscarArchivosCreados(cantidad);

    string archivoMasPequeno = buscarArchivoMasPequeno();
    cout << "El archivo mas pequeno es: \n" << archivoMasPequeno << endl;

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
    cout<<"Archivos creados : " + to_string(i) << endl;
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
        cout<<"Archivos creados : " + to_string(i)<<endl;

    }
}

void buscarArchivosCreados(int cantidad) {
    std::string ruta;

    if (cantidad % 2 == 0) {
        ruta = "C:/Users/Usuario/Documents/par";
    } else {
        ruta = "C:/Users/Usuario/Desktop/impar";
    }

    std::cout << "Buscando archivos en la carpeta: \n" << ruta << std::endl;

    for (const auto& entry : std::filesystem::directory_iterator(ruta)) {
        if (entry.is_regular_file()) {
            std::cout << entry.path().filename() << std::endl;
        }
    }
}

string buscarArchivoMasPequeno() {
    string ruta;
    string archivoMasPequeno;
    long long tamanoMasPequeno = numeric_limits<long long>::max();

    string rutaPar = "C:/Users/Usuario/Documents/par";
    string rutaImpar = "C:/Users/Usuario/Desktop/impar";

    for (const auto& entry : filesystem::directory_iterator(rutaPar)) {
        if (entry.is_regular_file()) {
            long long tamanoArchivo = filesystem::file_size(entry.path());
            if (tamanoArchivo < tamanoMasPequeno) {
                tamanoMasPequeno = tamanoArchivo;
                archivoMasPequeno = entry.path().filename().string();
            }
        }
    }

    for (const auto& entry : filesystem::directory_iterator(rutaImpar)) {
        if (entry.is_regular_file()) {
            long long tamanoArchivo = filesystem::file_size(entry.path());
            if (tamanoArchivo < tamanoMasPequeno) {
                tamanoMasPequeno = tamanoArchivo;
                archivoMasPequeno = entry.path().filename().string();
            }
        }
    }

    return archivoMasPequeno;
}