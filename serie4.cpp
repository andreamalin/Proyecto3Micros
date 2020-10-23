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
* Grupo #7:
* 	- Martín Amado		19020
* 	- Andrea Amaya		19357
* 	- Oliver de León	19270
* 	- Brandon Hernández	19376
* 	- Laura Tamath		19365
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

using namespace std;

int main ()
{
	// Atributos a utilizar
	int limite;
	double final = 0;
	double resultado;
	double e = 2.178282;
	int potencia = 2;
	omp_set_num_threads(10); 	//numero de hilos

	cout << "Ingrese hasta donde quiere que la sumatoria opere: ";
	cin >> limite;

	#pragma omp parallel for private(resultado)
	for(int i = 1; i <= limite; i++){
		double cua = pow(i, potencia); //eleva n²
		double resultado1 = (1+1/cua); //se realiza 1 + 1/n²
		double res1 = pow(resultado1, i); // (1 + 1/n²)^n
		resultado = e - res1; // e - (1 + 1/n²)^n

		#pragma omp atomic
		final += resultado;

	}	// Pragma For

	cout << "El resultado es: " << final << endl;
	return 0;
} //main
