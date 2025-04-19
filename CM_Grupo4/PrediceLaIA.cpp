#include "pch.h"
#include "Funcionamiento.h"
#include "iostream"
#include <string>
#include <cmath>
#include <iomanip>  
#include <sstream>  
using namespace std;
char matriz[10][10];
int contadorC = 0;
int contadorG = 0;
int contadorD = 0;
int contadorN = 0;
int contadorO = 0;
int transiciones[5][5] = {0};
float matrizTransicion[5][5] = { 0 };
char IAs[5] = { 'C', 'G','D','N','O' };
void baseDeDatos()
{
	srand(time(NULL));
	
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			int posicion = rand() % 5;
			char letra= IAs[posicion];
			matriz[i][j] = letra;
			if (letra == 'C')contadorC++;
			if (letra == 'G')contadorG++;
			if (letra == 'D')contadorD++;
			if (letra == 'N')contadorN++;
			if (letra == 'O')contadorO++;
		}
	}
}
int indice(char letra)
{
	for (int i = 0; i < 5; i++)
	{
		if (IAs[i] == letra)
			return i;
	}
}
void compararTransici�n()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 9; j++) 
		{
			char actual = matriz[i][j];
			char siguiente = matriz[i][j + 1];
			int ahora = indice(actual);
			int despues = indice(siguiente);
				transiciones[ahora][despues]++;
		}

	}
}
int obtenerContador(char letra) {
    if (letra == 'C') return contadorC;
    if (letra == 'G') return contadorG;
    if (letra == 'D') return contadorD;
    if (letra == 'N') return contadorN;
    if (letra == 'O') return contadorO;
    return 0;
}
void calcularMatrizDeTransicion() {
    for (int i = 0; i < 5; i++) {  
        int totalLetra = obtenerContador(IAs[i]); 

        if (totalLetra != 0) {
            for (int j = 0; j < 5; j++) {  
                matrizTransicion[i][j] = (double)transiciones[i][j] / totalLetra;
            }
        }
    }
}
string calcularVectorUnitario() {
    float vectorUnitario[5] = { 0.0, 0.0, 0.0, 0.0, 0.0 };
    char letraFinal = matriz[9][9]; 

    int indice;
    for (int i = 0; i < 5; i++) {
        if (IAs[i] == letraFinal) {
            indice = i;
            break;
        }
    }

    vectorUnitario[indice] = 1.0;

    string resultado = "Vector unitario:\r\n";

    for (int i = 0; i < 5; i++) {
        stringstream ss;
        ss << fixed << setprecision(1) << vectorUnitario[i]; 
        resultado += IAs[i]; 
        resultado += ": ";
        resultado += ss.str();
        resultado += "\r\n";
    }

    return resultado;
}
string imprimirBase()
{
	string resultado = "";
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			resultado += matriz[i][j];
			if (j < 9)  
				resultado += "->";
		}
		resultado += '\n';
	}
	return resultado;
}
string cantidadIndicadores()
{
	string resultado = "La cantidad de dias:\r\n";
	resultado += "C: " + to_string(contadorC) + "\r\n";
	resultado += "G: " + to_string(contadorG) + "\r\n";
	resultado += "D: " + to_string(contadorD) + "\r\n";
	resultado += "N: " + to_string(contadorN) + "\r\n";
	resultado += "O: " + to_string(contadorO) + "\r\n";
	return resultado;
}

string imprimirTransiciones() {
    string resultado = "La cantidad de veces que:\r\n";
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            resultado += IAs[i];
            resultado += "->";
            resultado += IAs[j];
            resultado += "= ";
            resultado += to_string(transiciones[i][j]);
            resultado += "\t";
        }
        resultado += "\r\n";
    }
    return resultado;
}
string imprimirMatrizDeTransicion() {
    string resultado = "DIA CERO:\r\n\r\n";
    resultado += "La matriz de transici�n es:\r\n\r\n";

    resultado += "       ";  // Espaciado inicial para encabezados
    for (int j = 0; j < 5; j++) {
        resultado += IAs[j];
        resultado += "     ";  // Ajuste para alineaci�n uniforme
    }
    resultado += "\r\n";

    for (int j = 0; j < 5; j++) { // **Iterar columnas primero**
        resultado += IAs[j];  // Encabezado de la columna
        resultado += "  ";  // Espaciado adicional para alineaci�n

        for (int i = 0; i < 5; i++) { // **Iterar filas despu�s**
            stringstream ss;
            ss << fixed << setprecision(3) << matrizTransicion[i][j]; // Mantener tres decimales
            resultado += ss.str() + "   "; // Espaciado uniforme entre valores
        }
        resultado += "\r\n"; // Nueva l�nea por cada columna
    }
    return resultado;
}


