#pragma once
#include "iostream"
#pragma once
#include <string>
using namespace std;

void baseDeDatos();
string imprimirBase();
string cantidadIndicadores();
void compararTransicion();
string imprimirTransiciones();
void calcularMatrizDeTransicion();
string imprimirMatrizDeTransicion();
void calcularVectorUnitario();
string imprimirVectorUnitario();
void elevarMatrizAPotencia(int potencia, float resultado[5][5]);
void calcularProbabilidades(int nDias);
string imprimirProbabilidades(int nDias);
string imprimirMatrizPersonalizada(float matriz[5][5]);
int calcularIAMasProbable();
string generarRecomendaciones();

