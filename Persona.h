#ifndef PERSONA_H
#define PERSONA_H

#include <string>
#include <fstream>
#include "libreria.h"
#include "LibreriaBinaria.h"

using namespace std;

class Persona
{
protected:
    string ci;     // //ci
    string nombre; // //nombre
    int edad;      // //edad

public:
    // //constructor
    Persona() : ci("0"), nombre("SIN_NOMBRE"), edad(0) {}

    Persona(string c, string n, int e) : ci(c), nombre(n), edad(e) {}

    // //acceso
    string getCI() const { return ci; }
    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    // //contrato virtual puro
    virtual string mostrar() = 0;
    virtual void guardar(ofstream& archivo) const = 0;
    virtual void recuperar(ifstream& archivo) = 0;

    virtual ~Persona() {}
};

#endif#pragma once
