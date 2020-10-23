/*
* Universidad del Valle de Guatemala
* Programación de microprocesadores
* CC3050
*----------------------------------------
* Serie2.cpp
* Determina el valor de convergencia de la serie
* para n=1
* ∑ [1/(n(n + 1))]
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
* Encargada del codigo: Andrea Amaya
*----------------------------------------*/
#include <omp.h>	// OpenMP include file
#include <iostream> //Cout
using namespace std;

#define infinite 100 //Define hasta donde hacer la sumatoria *10
					//Con 100 - se realiza la sumatoria hasta 1000

double serie(int actual){ //Calcula el valor del thread actual
	double resultado = actual*(actual+1.0);
	resultado = 1/resultado;
	return resultado;
}

int main()
{
	int num=0, sumar=0;
	double total=0;
	omp_set_num_threads(100); //Se definen 100 threads
	
	//Secuencial
	for(int actual=0;actual<10;actual++){ 
		//Se revisa por cual ciclo vamos
		sumar = 100*actual;
		//Paralelismo
		#pragma omp parallel private(num)
		{
			//Se hace de forma ordenada
			#pragma omp for ordered
			for(int i=0;i<infinite;i++) //Hasta llegar a infinite
			{
				#pragma omp ordered
				{
					//Sumo +1 al thread (comienza en 1 la sumatoria)
					//Se suma el ciclo actual
					num = (omp_get_thread_num()+1)+sumar; 
					//Se suma el resultado al total
					#pragma omp atomic
					total+=serie(num);
				} //ordered
			}//for
		} //pragma
	} //for
	cout << "La sumatoria es: " << total << endl; //Se muestra
	return 0;
}//main
