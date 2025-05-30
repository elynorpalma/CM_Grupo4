#include "pch.h"
#include "Funcionamiento.h"
#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>  
#include <sstream>  
using namespace std;

char matriz[10][10];
char matrizUsuario1[10][10],matrizUsuario2[10][10], matrizUsuario3[10][10];
int contadorC = 0;
int contadorG = 0;
int contadorD = 0;
int contadorN = 0;
int contadorO = 0;
int transiciones[5][5] = { 0 };
float matrizTransicion[5][5] = { 0 };
float vectorUnitario[5] = { 0 };
float matrizElevada[5][5];
float probabilidades[5];
char IAs[5] = { 'C', 'G','D','N','O' };

void baseUsuario1() 
{
    char base[10][10] = {
    {'C','C','C','C','G','G','G','C','C','G'},
    {'N','N','N','N','G','G','D','O','O','O'},
    {'N','D','D','D','D','N','N','N','N','N'},
    {'D','D','N','N','D','N','D','D','D','N'},
    {'G','G','G','G','C','N','N','O','O','O'},
    {'N','N','N','N','D','G','G','G','G','D'},
    {'G','D','N','N','G','D','N','G','G','N'},
    {'N','N','C','O','G','G','G','N','N','G'},
    {'G','G','G','D','G','G','G','C','C','C'},
    {'G','G','O','O','O','D','D','D','D','D'}
    };


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrizUsuario1[i][j] = base[i][j];
        }
    }
}
void baseUsuario2()
{
    char base[10][10] = {
        {'D','D','D','G','O','O','N','N','N','N'},
        {'O','N','D','D','D','N','G','G','G','C'},
        {'G','G','G','G','O','G','G','G','G','G'},
        {'D','G','G','N','C','D','D','D','D','O'},
        {'C','C','D','D','D','D','C','N','D','D'},
        {'D','D','D','D','D','O','O','G','G','G'},
        {'C','C','C','C','G','D','D','D','D','D'},
        {'C','C','O','O','O','O','C','C','C','C'},
        {'G','G','N','N','N','N','N','N','N','N'},
        {'O','C','N','N','N','O','O','O','O','C'}
    };


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrizUsuario2[i][j] = base[i][j];
        }
    }
}
void baseUsuario3()
{
    char base[10][10] = {
        {'N','N','C','C','O','O','O','O','O','G'},
        {'G','G','C','C','D','D','D','D','D','D'},
        {'O','N','D','D','D','D','D','D','D','D'},
        {'N','N','N','N','N','N','N','D','O','O'},
        {'G','D','D','D','N','G','D','D','D','D'},
        {'G','G','G','G','G','G','G','G','C','C'},
        {'G','G','C','C','G','N','N','N','N','N'},
        {'D','D','D','D','D','D','D','D','D','D'},
        {'O','O','D','D','D','D','G','C','G','G'},
        {'O','C','N','N','O','O','N','D','D','C'}
    };


    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            matrizUsuario3[i][j] = base[i][j];
        }
    }
}
void baseDeDatos() {

    for (int i = 0; i < 10; i++) {
        char anterior = IAs[rand() % 5];

        for (int j = 0; j < 10; j++) {
            if (j > 0 && (rand() % 100) < 60) {
                matriz[i][j] = anterior;
            }
            else {
                matriz[i][j] = IAs[rand() % 5];
                anterior = matriz[i][j];
            }
            switch (matriz[i][j]) {
            case 'C': contadorC++; break;
            case 'G': contadorG++; break;
            case 'D': contadorD++; break;
            case 'N': contadorN++; break;
            case 'O': contadorO++; break;
            }
        }
    }
}

int indice(char letra) {
    for (int i = 0; i < 5; i++) {
        if (IAs[i] == letra) return i;
    }
    return -1;
}
void compararTransicion() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 9; j++) {
            int actual = indice(matriz[i][j]);
            int siguiente = indice(matriz[i][j + 1]);
            if (actual != -1 && siguiente != -1) {
                transiciones[actual][siguiente]++;
            }
        }
    }
}
void resetearContadoresYTransiciones() {
    
    contadorC = contadorG = contadorD = contadorN = contadorO = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            transiciones[i][j] = 0;
        }
    }
}
void copiarMatrizUsuarioAMatrizPrincipal(int usuario) {
    char (*matrizOrigen)[10] = nullptr;

    switch (usuario) {
    case 1: matrizOrigen = matrizUsuario1; break;
    case 2: matrizOrigen = matrizUsuario2; break;
    case 3: matrizOrigen = matrizUsuario3; break;
    default: return;
    }

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = matrizOrigen[i][j];
            switch (matriz[i][j]) {
            case 'C': contadorC++; break;
            case 'G': contadorG++; break;
            case 'D': contadorD++; break;
            case 'N': contadorN++; break;
            case 'O': contadorO++; break;
            }
        }
    }
}
int obtenerContador(char letra) {
    switch (letra) {
    case 'C': return contadorC;
    case 'G': return contadorG;
    case 'D': return contadorD;
    case 'N': return contadorN;
    case 'O': return contadorO;
    default: return 0;
    }
}
void calcularMatrizDeTransicion() {
    for (int i = 0; i < 5; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            total += transiciones[i][j];
        }

        if (total == 0) {
            for (int j = 0; j < 5; j++) {
                matrizTransicion[i][j] = 0.2f;
            }
        }
        else {
            for (int j = 0; j < 5; j++) {
                matrizTransicion[i][j] = (float)transiciones[i][j] / total;
            }
        }
    }
}
void multiplicarMatrices(const float a[5][5], const float b[5][5], float resultado[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < 5; k++) {
                resultado[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void elevarMatrizAPotencia(int potencia, float resultado[5][5]) {
    float temp[5][5];
    float tempResult[5][5];
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            resultado[i][j] = (i == j) ? 1.0f : 0.0f;
            temp[i][j] = matrizTransicion[i][j];
        }
    }

    while (potencia > 0) {
        if (potencia % 2 == 1) {
            multiplicarMatrices(resultado, temp, tempResult);
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    resultado[i][j] = tempResult[i][j];
                }
            }
        }

        multiplicarMatrices(temp, temp, tempResult);
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                temp[i][j] = tempResult[i][j];
            }
        }

        potencia /= 2;
    }
}
void calcularVectorUnitario() {
    char ultimoEstado = matriz[9][9];
    for (int i = 0; i < 5; i++) {
        vectorUnitario[i] = (IAs[i] == ultimoEstado) ? 1.0f : 0.0f;
    }
}
void calcularProbabilidades(int n) {
    elevarMatrizAPotencia(n, matrizElevada);
    calcularVectorUnitario();

    for (int i = 0; i < 5; i++) {
        probabilidades[i] = 0;
        for (int j = 0; j < 5; j++) {
            probabilidades[i] += vectorUnitario[j] * matrizElevada[j][i];
        }
    }
}
int calcularIAMasProbable() {
    int indiceMax = 0;
    for (int i = 1; i < 5; i++) {
        if (probabilidades[i] > probabilidades[indiceMax]) {
            indiceMax = i;
        }
    }
    return indiceMax;
}


string imprimirProbabilidades(int nDias) {
    string resultado;

    resultado += "\nPROBABILIDADES FINALES (" + to_string(nDias) + " días):\r\n\n";
    for (int i = 0; i < 5; i++) {
        stringstream ss;
        ss << fixed << setprecision(2) << (probabilidades[i] * 100);
        resultado += string(1, IAs[i]) + ": " + ss.str() + "%"+ "\r\n";
    }
    resultado += "\r\n";
    return resultado;

}
string imprimirMatrizPersonalizada(float matriz[5][5]) {
    string resultado = " ";
    resultado += "      ";
    for (int j = 0; j < 5; j++) {
        resultado += IAs[j];
        resultado += "         ";
    }
    resultado += "\r\n";

    for (int j = 0; j < 5; j++) {
        resultado += IAs[j];
        resultado += "  ";

        for (int i = 0; i < 5; i++) {
            stringstream ss;
            ss << fixed << setprecision(3) << matrizElevada[i][j];
            resultado += ss.str() + "   ";
        }
        resultado += "\r\n";
    }
    return resultado;
}
string generarRecomendaciones() 
{
    int iaSeleccionada = calcularIAMasProbable();
    float probabilidad = probabilidades[iaSeleccionada];

    stringstream ss;
    ss << fixed << setprecision(2) << (probabilidad * 100);

    string recomendacion;
    recomendacion += "\r\nHerramienta más probable de ser usada: " + string(1, IAs[iaSeleccionada]) + "\r\n";
    recomendacion += "Probabilidad: " + ss.str() + "%\r\n";
    switch (iaSeleccionada) {
        case 0: // ChatGPT
            recomendacion += "Recomendación: Úsalo para redactar textos, resolver dudas, generar ideas o ayudarte con programación.\r\n";
            break;
        case 1: // Gemini
            recomendacion += "Recomendación: Ideal para búsquedas rápidas, integración con productos de Google y resúmenes contextuales.\r\n";
            break;
        case 2: // DALL-E
            recomendacion += "Recomendación: Utilízalo para generar imágenes a partir de texto, útil en diseño gráfico o visualización de ideas.\r\n";
            break;
        case 3: // Notion
            recomendacion += "Recomendación: Perfecto para organizar tareas, tomar notas inteligentes o planificar proyectos con ayuda de IA.\r\n";
            break;
        case 4: // Otros
            recomendacion += "Recomendación: Explora herramientas especializadas según tu necesidad: análisis de datos, generación de música, o edición de video.\r\n";
            break;
      
    }
    return recomendacion;
}
string imprimirVectorUnitario()
{    calcularVectorUnitario();
     string resultado;

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
    string  resultado;
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
    string resultado;
    resultado += "CHATGPT (C): " + to_string(contadorC) + "\r\n";
    resultado += "GEMINI (G): " + to_string(contadorG) + "\r\n";
    resultado += "DALL-E (D): " + to_string(contadorD) + "\r\n";
    resultado += "NOTION (N): " + to_string(contadorN) + "\r\n";
    resultado += "OTROS (O): " + to_string(contadorO) + "\r\n";
    return resultado;
}
string imprimirTransiciones() {
    string resultado;
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
    string resultado;
    resultado += "      ";
    for (int j = 0; j < 5; j++) {
        resultado += IAs[j];
        resultado += "         ";
    }
    resultado += "\r\n";

    for (int j = 0; j < 5; j++) {
        resultado += IAs[j];
        resultado += "  ";

        for (int i = 0; i < 5; i++) {
            stringstream ss;
            ss << fixed << setprecision(3) << matrizTransicion[i][j];
            resultado += ss.str() + "   ";
        }
        resultado += "\r\n";
    }
    return resultado;
}


