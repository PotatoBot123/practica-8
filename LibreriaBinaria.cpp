#include "LibreriaBinaria.h"
#include <cstdint>
#include <stdexcept>

void LibreriaBinaria::escribirCaracter(ofstream& archivo, char dato)
{
    archivo.write(reinterpret_cast<const char*>(&dato), sizeof(dato));
    if (!archivo)
        throw runtime_error("Error al escribir caracter en binario.");
}

char LibreriaBinaria::leerCaracter(ifstream& archivo)
{
    char dato;
    archivo.read(reinterpret_cast<char*>(&dato), sizeof(dato));
    if (!archivo)
        throw runtime_error("Error al leer caracter desde binario.");
    return dato;
}

void LibreriaBinaria::escribirEntero(ofstream& archivo, int dato)
{
    archivo.write(reinterpret_cast<const char*>(&dato), sizeof(dato));
    if (!archivo)
        throw runtime_error("Error al escribir entero en binario.");
}

int LibreriaBinaria::leerEntero(ifstream& archivo)
{
    int dato = 0;
    archivo.read(reinterpret_cast<char*>(&dato), sizeof(dato));
    if (!archivo)
        throw runtime_error("Error al leer entero desde binario.");
    return dato;
}

void LibreriaBinaria::escribirCadena(ofstream& archivo, const string& dato)
{
    uint32_t longitud = static_cast<uint32_t>(dato.size());
    archivo.write(reinterpret_cast<const char*>(&longitud), sizeof(longitud));
    if (longitud > 0)
        archivo.write(dato.data(), static_cast<streamsize>(longitud));

    if (!archivo)
        throw runtime_error("Error al escribir cadena en binario.");
}

string LibreriaBinaria::leerCadena(ifstream& archivo)
{
    uint32_t longitud = 0;
    archivo.read(reinterpret_cast<char*>(&longitud), sizeof(longitud));
    if (!archivo)
        throw runtime_error("Error al leer longitud de cadena.");

    if (longitud > 1000000)
        throw runtime_error("Longitud de cadena invalida.");

    string dato(longitud, '\0');
    if (longitud > 0)
        archivo.read(&dato[0], static_cast<streamsize>(longitud));

    if (!archivo)
        throw runtime_error("Cadena incompleta en archivo binario.");
    return dato;
}