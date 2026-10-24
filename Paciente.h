#ifndef PACIENTE_H
#define PACIENTE_H

#include "Persona.h"

class Paciente : public Persona
{
private:
    string historiaClinica; // //historia clinica
    string tipoSeguro;      // //tipo de seguro

public:
    // //constructor
    Paciente() : Persona(), historiaClinica("HC-000"), tipoSeguro("NINGUNO") {}

    Paciente(string c, string n, int e, string hc, string seguro)
        : Persona(c, n, e), historiaClinica(hc), tipoSeguro(seguro) {
    }

    // //acceso
    string getHistoriaClinica() const { return historiaClinica; }
    string getTipoSeguro() const { return tipoSeguro; }

    // //salida
    string mostrar() override
    {
        string datos = "\n===== PACIENTE =====\n";
        datos += "CI         : " + ci + "\n";
        datos += "NOMBRE     : " + nombre + "\n";
        datos += "EDAD       : " + to_string(edad) + "\n";
        datos += "HISTORIA   : " + historiaClinica + "\n";
        datos += "SEGURO     : " + tipoSeguro + "\n";
        mostrarMensaje(datos);
        return datos;
    }

    // //persistencia binaria
    void guardar(ofstream& archivo) const override
    {
        LibreriaBinaria::escribirCaracter(archivo, 'P'); // //identificador tipo
        LibreriaBinaria::escribirCadena(archivo, ci);
        LibreriaBinaria::escribirCadena(archivo, nombre);
        LibreriaBinaria::escribirEntero(archivo, edad);
        LibreriaBinaria::escribirCadena(archivo, historiaClinica);
        LibreriaBinaria::escribirCadena(archivo, tipoSeguro);
    }

    void recuperar(ifstream& archivo) override
    {
        ci = LibreriaBinaria::leerCadena(archivo);
        nombre = LibreriaBinaria::leerCadena(archivo);
        edad = LibreriaBinaria::leerEntero(archivo);
        historiaClinica = LibreriaBinaria::leerCadena(archivo);
        tipoSeguro = LibreriaBinaria::leerCadena(archivo);
    }
};

#endif#pragma once
