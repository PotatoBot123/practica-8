#ifndef IALMACENAR_H
#define IALMACENAR_H

#include <string>
using namespace std;

// //contrato base de almacenamiento
class IAlmacenar
{
public:
    virtual void guardar(const string& nomfis) = 0; // //contrato
    virtual void recuperar(const string& nomfis) = 0; // //contrato
    virtual ~IAlmacenar() {}
};

#endif#pragma once
