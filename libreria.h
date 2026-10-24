#ifndef LIBRERIA_H
#define LIBRERIA_H
#include <string>
using namespace std;

const int MAX = 500;

// módulos de entrada
string leerCadena(const string mensaje);
float leerNumR(const string mensaje);
int leerNumE(const string mensaje);
int leerNumEP(const string mensaje);
int leerLimite(const string mensaje, int limite);
float leerNumRPSC(const string mensaje);
int leerNumEPSC(const string mensaje);

void llenarVector(int v[], int n);
void llenarVector(float v[], int n);
void llenarMatriz(float m[][MAX], int f, int c);

// módulos de proceso
float redondear(float num, int decimales);
void ordenamientoBurbuja(int v[], int n);
void ordenamientoInsercion(int v[], int n);
void ordenamientoSeleccion(int v[], int n);
int secuencial(int v[], int n, int dato);
int binaria(int v[], int n, int dato);

// módulos de salida
void mostrarMensaje(const string mensaje);
char mostrarConfirmacion(const string mensaje);
void mostrarRedondeado(float numero, int decimales);
void mostrarVector(int v[], int n);
void mostrarMatriz(float m[][MAX], int f, int c);

#endif#pragma once
