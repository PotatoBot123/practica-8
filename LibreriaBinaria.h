#ifndef LIBRERIABINARIA_H
#define LIBRERIABINARIA_H

#include <fstream>
#include <string>
using namespace std;

// //libreria binaria reutilizable
class LibreriaBinaria
{
public:
    static void escribirCaracter(ofstream& archivo, char dato);
    static char leerCaracter(ifstream& archivo);

    static void escribirEntero(ofstream& archivo, int dato);
    static int leerEntero(ifstream& archivo);

    static void escribirCadena(ofstream& archivo, const string& dato);
    static string leerCadena(ifstream& archivo);
};

#endif#pragma once
