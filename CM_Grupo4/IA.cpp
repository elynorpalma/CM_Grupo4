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
int transiciones[5][5] = { 0 };
float matrizTransicion[5][5] = { 0 };
float vectorUnitario[5] = { 0 };
float matrizElevada[5][5];
float probabilidades[5];
char ultimoEstado;
char IAs[5] = { 'C', 'G','D','N','O' };

void baseDeDatos()
{

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            int posicion = rand() % 5;
            char letra = IAs[posicion];
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
void compararTransición()
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
void elevarMatrizAPotencia(int potencia, float resultado[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            resultado[i][j] = (i == j) ? 1.0f : 0.0f;
        }
    }

    float temp[5][5];
    float tempMultiplicacion[5][5];

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            temp[i][j] = matrizTransicion[i][j];
        }
    }

    while (potencia > 0) {
        if (potencia % 2 == 1) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    tempMultiplicacion[i][j] = 0;
                    for (int k = 0; k < 5; k++) {
                        tempMultiplicacion[i][j] += resultado[i][k] * temp[k][j];
                    }
                }
            }
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    resultado[i][j] = tempMultiplicacion[i][j];
                }
            }
        }

        // Elevar temp al cuadrado
        float tempCuadrado[5][5];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                tempCuadrado[i][j] = 0;
                for (int k = 0; k < 5; k++) {
                    tempCuadrado[i][j] += temp[i][k] * temp[k][j];
                }
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                temp[i][j] = tempCuadrado[i][j];
            }
        }

        potencia /= 2;
    }
}
void calcularVectorUnitario()
{
    char ultimoEstado = matriz[9][9];
    for (int i = 0; i < 5; i++) {
        if (IAs[i] == ultimoEstado) {
            vectorUnitario[i] = 1.0f;
            break;
        }
    }
}
void calcularProbabilidades(int n) {
    elevarMatrizAPotencia(n, matrizElevada);
    calcularVectorUnitario();
    
    for (int i = 0; i < 5; i++) {
        probabilidades[i] = 0;
        for (int j = 0; j < 5; j++) {
            probabilidades[i] += matrizElevada[j][i] * vectorUnitario[j];
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

    resultado += "\nPROBABILIDADES FINALES (" + to_string(nDias) + " días):\n\n";
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


