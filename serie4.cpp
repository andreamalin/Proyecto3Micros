/*
* Universidad del Valle de Guatemala
* Programación de microprocesadores
* CC3050
*----------------------------------------
* Serie4.cpp
* Determina el valor de convergencia de la serie
* para n=1
* ∑ [e - (1 + 1/n²)^n]
* ---------------------------------------
* Proyecto 3 
* ---------------------------------------
* Grupo #8
* Encargados del código: Oliver de León
* Laura Tamath
*----------------------------------------*/

#include <omp.h>	// Biblioteca de OpenMP 
#include <iostream> //Biblioteca Cout
#include <cmath> // Biblioteca de funciones matematicas

#define infinite 100 //Define hasta donde realizar la sumatoria 

double serie(int current){
	double e = 2.178282;
	double potencia = 2;
	double power = pow(current, potencia); //eleva n²
	double resultado1 = (1+1/power); //se realiza 1 + 1/n²
	double res1 = pow(resultado1, current); // (1 + 1/n²)^n
	resultado = e - res1; // e - (1 + 1/n²)^n
	return resultado;

}

int main ()
{


} //main