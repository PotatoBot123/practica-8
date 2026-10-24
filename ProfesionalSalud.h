#ifndef PROFESIONALSALUD_H
#define PROFESIONALSALUD_H

#include "Persona.h"

class ProfesionalSalud : public Persona
{
private:
    string especialidad;        // //especialidad
    string registroProfesional; // //registro profesional

public:
    // //constructor
    ProfesionalSalud() : Persona(), especialidad("GENERAL"), registroProfesional("REG-000") {}

    ProfesionalSalud(string c, string n, int e, string esp, string reg)
        : Persona(c, n, e), especialidad(esp), registroProfesional(reg) {
    }

    // //acceso
    string getEspecialidad() const { return especialidad; }
    string getRegistroProfesional() const { return registroProfesional; }

    // //salida
    string mostrar() override
    {
        string datos = "\n===== PROFESIONAL DE SALUD =====\n";
        datos += "CI          : " + ci + "\n";
        datos += "NOMBRE      : " + nombre + "\n";
        datos += "EDAD        : " + to_string(edad) + "\n";
        datos += "ESPECIALIDAD: " + especialidad + "\n";
        datos += "REGISTRO    : " + registroProfesional + "\n";
        mostrarMensaje(datos);
        return datos;
    }

    // //persistencia binaria
    void guardar(ofstream& archivo) const override
    {
        LibreriaBinaria::escribirCaracter(archivo, 'S'); // //identificador tipo
        LibreriaBinaria::escribirCadena(archivo, ci);
        LibreriaBinaria::escribirCadena(archivo, nombre);
        LibreriaBinaria::escribirEntero(archivo, edad);
        LibreriaBinaria::escribirCadena(archivo, especialidad);
        LibreriaBinaria::escribirCadena(archivo, registroProfesional);
    }

    void recuperar(ifstream& archivo) override
    {
        ci = LibreriaBinaria::leerCadena(archivo);
        nombre = LibreriaBinaria::leerCadena(archivo);
        edad = LibreriaBinaria::leerEntero(archivo);
        especialidad = LibreriaBinaria::leerCadena(archivo);
        registroProfesional = LibreriaBinaria::leerCadena(archivo);
    }
};

#endif#pragma once
