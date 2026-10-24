#ifndef REPORTE_H
#define REPORTE_H

#include <string>
#include "IAlmacenar.h"
using namespace std;

class Reporte : public IAlmacenar
{
private:
    string texto; // //texto del reporte
public:
    Reporte();
    void establecerTexto(const string& texto);
    void guardar(const string& nomfis) override;
    void recuperar(const string& nomfis) override;
};

#endif#pragma once
