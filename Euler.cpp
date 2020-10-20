/*
	Euler.cpp
	--------------------
	Calculo de la constante de Euler
	con implementacion de openmp
*/

#include <omp.h>                         // Inclusion de librerias
#include <stdio.h>
#include <stdlib.h>

float factorial(int n) {
	if (n < 0)
		return -1;
	else if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}
int main() {
	int n;								//Valor que se le da a n para ciclo for
	float e = 0;
	printf("Ingrese el valor 'n'. A mayor valor de 'n' mayor exactitud de la constante: ");
	scanf("%d", &n);
	#pragma omp parallel for
	for (int i = 0; i < n; i++)
		e += (1 / factorial(i));

	printf("\nEl valor de la contstante de Euler es: %f\n", e);
}