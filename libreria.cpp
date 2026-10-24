#include <cmath>
#include <iostream>
#include <iomanip>
#include "libreria.h"

// //modulos de entrada
string leerCadena(const string mensaje)
{
	string cadena;
	mostrarMensaje(mensaje);
	getline(cin >> ws, cadena);
	return cadena;
}

float leerNumR(const string mensaje)
{
	float num;
	mostrarMensaje(mensaje);
	cin >> num;
	return num;
}

int  leerNumE(const string mensaje)
{
	int num;
	mostrarMensaje(mensaje);
	cin >> num;
	return num;
}

int  leerNumEP(const string mensaje)
{
	int num;
	do
	{
		num = leerNumE(mensaje);
	} while (num < 0);
	return num;
}

int leerLimite(const string mensaje, int limite)
{
	int tam;
	do
	{
		tam = leerNumEP(mensaje);
	} while (tam <= 0 || tam > limite);
	return tam;
}

void llenarVector(int v[], int n)
{
	for (int i = 0; i < n; i++)
		v[i] = leerNumEP("Elemento [" + to_string(i) + "]=");
}

void llenarVector(float v[], int n)
{
	for (int i = 0; i < n; i++)
		v[i] = leerNumR("Elemento [" + to_string(i) + "]=");
}

void llenarMatriz(float m[][MAX], int f, int c)
{
	for (int i = 0; i < f; i++)
		for (int j = 0; j < c; j++)
			m[i][j] = leerNumR("ELEMENTO [" + to_string(i) + "][" + to_string(j) + "]=");
}

float leerNumRPSC(const string mensaje)
{
	float num;
	do
	{
		num = leerNumR(mensaje);
	} while (num <= 0);
	return num;
}

int leerNumEPSC(const string mensaje)
{
	int num;
	do
	{
		num = leerNumE(mensaje);
	} while (num <= 0);
	return num;
}

// //modulos de proceso
float redondear(float num, int decimales)
{
	float factor = pow(10.0, decimales);
	return round(num * factor) / factor;
}

void ordenamientoBurbuja(int v[], int n)
{
	int aux;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < n - 1 - i; j++)
			if (v[j] > v[j + 1])
			{
				aux = v[j];
				v[j] = v[j + 1];
				v[j + 1] = aux;
			}
}

void ordenamientoInsercion(int v[], int n)
{
	int aux, j;
	for (int i = 1; i < n; i++)
	{
		aux = v[i];
		j = i - 1;
		while (j >= 0 && v[j] > aux)
		{
			v[j + 1] = v[j];
			j--;
		}
		v[j + 1] = aux;
	}
}

void ordenamientoSeleccion(int v[], int n)
{
	int posicionMenor, aux;
	for (int i = 0; i < n - 1; i++)
	{
		posicionMenor = i;
		for (int j = i + 1; j < n; j++)
			if (v[j] < v[posicionMenor])
				posicionMenor = j;
		aux = v[i];
		v[i] = v[posicionMenor];
		v[posicionMenor] = aux;
	}
}

int secuencial(int v[], int n, int dato)
{
	int pos = -1;
	for (int i = 0; i < n; i++)
		if (v[i] == dato)
			pos = i;
	return pos;
}

int binaria(int v[], int n, int dato)
{
	int ini = 0, fin = n - 1, medio;
	while (ini <= fin)
	{
		medio = (ini + fin) / 2;
		if (v[medio] == dato)
			return medio;
		if (dato < v[medio])
			fin = medio - 1;
		else
			ini = medio + 1;
	}
	return -1;
}

// //modulos de salida
void mostrarMensaje(const string mensaje)
{
	cout << mensaje << " ";
}

char mostrarConfirmacion(const string mensaje)
{
	char respuesta;
	do
	{
		mostrarMensaje(mensaje);
		cin >> respuesta;
		respuesta = toupper(respuesta);
	} while (respuesta != 'N' && respuesta != 'S');
	return respuesta;
}

void mostrarRedondeado(float num, int decimales)
{
	float res = redondear(num, decimales);
	cout << fixed << setprecision(decimales) << res;
}

void mostrarVector(int v[], int n)
{
	for (int i = 0; i < n; i++)
		mostrarMensaje("Elemento [" + to_string(i) + "]=" + to_string(v[i]) + "\n");
}

void mostrarMatriz(float m[][MAX], int f, int c)
{
	for (int i = 0; i < f; i++)
	{
		for (int j = 0; j < c; j++)
			mostrarMensaje(to_string(m[i][j]) + "\t");
		mostrarMensaje("\n");
	}
}