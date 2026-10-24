#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Reporte.h"
#include "libreria.h"
using namespace std;

Reporte::Reporte() : texto("") {}

void Reporte::establecerTexto(const string& texto)
{
    this->texto = texto; // //mutacion
}

void Reporte::guardar(const string& nomfis)
{
    try
    {
        ofstream archivo(nomfis);
        if (!archivo.is_open())
            throw runtime_error("No se pudo abrir " + nomfis);

        archivo << texto;
        if (!archivo)
            throw runtime_error("Error al escribir reporte.");

        archivo.close();
        mostrarMensaje("\nReporte guardado correctamente en " + nomfis + ".\n");
    }
    catch (const exception& e)
    {
        mostrarMensaje(string("ERROR: ") + e.what() + "\n");
    }
}

void Reporte::recuperar(const string& nomfis)
{
    try
    {
        ifstream archivo(nomfis);
        if (!archivo.is_open())
            throw runtime_error("No se pudo abrir " + nomfis);

        string linea;
        mostrarMensaje("\n===== REPORTE ALMACENADO =====\n");
        while (getline(archivo, linea))
            mostrarMensaje(linea + "\n");
        archivo.close();
    }
    catch (const exception& e)
    {
        mostrarMensaje(string("ERROR: ") + e.what() + "\n");
    }
}