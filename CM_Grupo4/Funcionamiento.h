#pragma once
#include "iostream"
#pragma once
#include <string>
using namespace std;
void baseUsuario1();
void  baseUsuario2(); 
void baseUsuario3(); 
void baseDeDatos();
string imprimirBase();
string cantidadIndicadores();
void compararTransicion();
void resetearContadoresYTransiciones();
void copiarMatrizUsuarioAMatrizPrincipal(int usuario);
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

