#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "funktionen.h"

#define MAX_ITERATIONEN 1000
#define EPSILON 0.001

int main() {

	printf("Welche Ableitung soll fuer den Algorithmus verwendet werden?\n1. Analytische Ableitung\n2. Numerische Ableitung\n");
	int p;
	int c=0;
	scanf("%d", &p);
	if (p == 1 || p == 2) {
		c++;
	}

	while (c == 0) {
		printf("Leider ist die angegebene Option nicht vorhanden.\nBitte versuchen Sie es erneut.\n");
		printf("Welche Ableitung soll fuer den Algorithmus verwendet werden?\n1. Analytische Ableitung\n2. Numerische Ableitung\n");
		scanf("%d", &p);
		break;

	}
	newton(p);


	return 0;
}

