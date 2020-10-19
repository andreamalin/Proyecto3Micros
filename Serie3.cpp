/*
*-------------------------------------------
* Grupo #7:
* 	- Martín Amado		19020
* 	- Andrea Amaya		19357
* 	- Oliver de León	19270
* 	- Brandon Hernández	19376
* 	- Laura Tamath		19365
* Serie3.cpp
* ------------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* CC3056 - Programacion de Microprocesadores
* Proyecto Parte C
* ------------------------------------------
* Se encarga de realizar la serie de:
* (1 - (1/sqrt(x)))^x
*-------------------------------------------*/
#include <iostream>
#include <math.h>
#include <omp.h>

using namespace std;

int main(){
	
	// Declaración de variables a utilizar
	int limit;
	double result = 0, preResult; 
	omp_set_num_threads(10); 		//Se definen 10 threads

	cout << "Ingrese cuantos numeros de la sumatoria quiere operar: ";
	cin >> limit;
	
	#pragma omp parallel for private(preResult)
	for(int i = 1; i <= limit; i++){
		preResult = pow((1 - (1/(sqrt(i)))), i);
		
		#pragma omp atomic 
		result += preResult;
	}	// Pragma For
	
	cout << "El resultado es: " << result << endl;
	
	return 0;
} // Main
