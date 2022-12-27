#include "funktionen.h"
#include <stdio.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_ITERATIONEN 1000
#define EPSILON 0.001


double f(double x) {

	return(x - 3) * (x - 3);
}
double f_an(double x) {

	return 2 * (x - 3);
}
double f_num(double x) {

	double h = 0.00000001;

	return (f(x + h) - f(x)) / h;

}
double newton(int p) {
	ptr f_ptr = &f;
	ptr f_anptr = &f_an;
	ptr f_numptr = &f_num;
	double x0;
	double x1;
	int i = 0;
	if (p == 1) {
		printf("Sie haben sich fuer die Analytische Ableitung entschieden.");
		printf("Bitte geben Sie einen Startwert an.\n");
		scanf("%lf", &x0);
		while (i < MAX_ITERATIONEN) {
			x1 = x0 - f_ptr(x0) / f_anptr(x0);
			if (fabs(x1 - x0) < EPSILON) {
				printf("Die Nullstelle wurde nach %d Iterationen gefunden: %lf ", i, x1);
				return 0;
			}
			x0 = x1;
			i++;
		}
		if (i >= MAX_ITERATIONEN) {
			printf("Es wurde die Maximale Anzahl an Iterationen erreicht.");
		}



	}
	else if (p == 2) {
		printf("Sie haben sich fuer die Numerische Ableitung entschieden.");
		printf("Bitte geben Sie einen Startwert an.\n");
		scanf("%lf", &x0);
		while (i < MAX_ITERATIONEN) {
			x1 = x0 - f_ptr(x0) / f_numptr(x0);
			if (fabs(x1 - x0) < EPSILON) {
				printf("Die Nullstelle wurde nach %d Iterationen gefunden: %lf ", i, x1);
				return 0;
			}
			x0 = x1;
			i++;
		}
		if (i >= MAX_ITERATIONEN) {
			printf("Es wurde die Maximale Anzahl an Iterationen erreicht.");
		}
	}
}