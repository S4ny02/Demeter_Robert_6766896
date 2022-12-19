#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "funktionen.h"


int k;
void einlesen(char* str) {
	printf("Zahlenformat (a+bi) oder ((-a)+(-bi))\n");
	printf("Zahl eingeben : ");
	scanf("%s", str);

}

void formatieren(char* str, RoI array[]);
int pruefen(char* str) {
	int x = 0;
	int y = 0;

	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == '+') {
			x++;
		}
		else if (str[i] == 'i') {
			y++;
		}
	}
	if (x == 1 && y == 1) {
		return 1;
	}
	else {

		return 0;
	}

}
void formatieren(char* str, RoI array[]) {
	int len = strlen(str);
	char zahl[10] = { '\0' };

	int x = 0;

	for (int i = 0; i < len; i++) {
		char d = str[i];
		if (d != '+' && d != 'i' && d != '(' && d != ')') {
			zahl[x] = d;
			zahl[x + 1] = '\0';
			x++;
		}
		else if (d == '+') {
			array[k].real = atof(zahl);
			
			x = 0;
		}
		else if (d == 'i') {
			array[k].imaginary = atof(zahl);
			
			x = 0;
			k++;
		}
	}
}
void plus(RoI array[]);
void minus(RoI array[]);
void multiplikation(RoI array[]);
void division(RoI array[]);
void operation(RoI array[]) {
	char c;
	printf("Waehlen sie die Operation aus: '+', '-', '*', '/'\n");
	scanf(" %c", &c);
	if (c == '+') {
		plus(array);
	}
	else if (c == '-') {
		minus(array);
	}
	else if (c == '*') {
		multiplikation(array);
	}
	else if (c == '/') {
		division(array);
	}
}
void polar1(double real, double imaginary) {
	double r, a, b;
	r = sqrt(pow(real, 2) + pow(imaginary, imaginary));
	b = imaginary / real;
	if (real < 0 && imaginary < 0) {
		a = atan(b) - 3.1414926;
	}
	else if (real < 0) {
		a = atan(b) + 3.1414926;
	}
	else {
		a = atan(b);
	}
	printf("z = %.2lf * e^(i%.2lf)\n", r, a);
}
void polar2(double real, double imaginary) {
	double r, a, b;
	r = sqrt(pow(real, 2) + pow(imaginary, 2));
	b = imaginary / real;
	if (real < 0 && imaginary < 0) {
		a = atan(b) - 3.1414926;
	}
	else if (real < 0) {
		a = atan(b) + 3.1414926;
	}
	else {
		a = atan(b);
	}
	printf("z = %.2lf*(cos(%.2lf)+i*sin(%.2lf))\n", r, a, a);


}
void ausgabe(double real, double imaginary) {
	printf("Waehlen Sie ein Ausgabeformat:\n1. Karthesisch\n2. Poolar 1\n3. Polar 2\n");
	int a;
	scanf("%d", &a);
	if (a == 1) {
		printf("z = %.2lf + %.2lfi\n", real, imaginary);
	}
	else if (a == 2) {
		polar1(real, imaginary);
	}
	else if (a == 3) {
		polar2(real, imaginary);
	}
}

void plus(RoI array[]) {
	double x1 = array[0].real;
	double x2 = array[1].real;
	double y1 = array[0].imaginary;
	double y2 = array[1].imaginary;
	double realErg = 0;
	double imaginaryErg = 0;

	realErg = (x1 + x2);
	imaginaryErg = (y1 + y2);
	ausgabe(realErg, imaginaryErg);
	
}
void minus(RoI array[]) {
	double x1 = array[0].real;
	double x2 = array[1].real;
	double y1 = array[0].imaginary;
	double y2 = array[1].imaginary;
	double realErg = 0;
	double imaginaryErg = 0;

	realErg = (x1 - x2);
	imaginaryErg = (y1 - y2);
	ausgabe(realErg, imaginaryErg);
	

}
void multiplikation(RoI array[]) {
	double x1 = array[0].real;
	double x2 = array[1].real;
	double y1 = array[0].imaginary;
	double y2 = array[1].imaginary;
	double realErg = 0;
	double imaginaryErg = 0;

	realErg = ((x1 * x2) - (y1 * y2));
	imaginaryErg = ((x1 * y2) + (x2 * y1));
	ausgabe(realErg, imaginaryErg);
	

}
void division(RoI array[]) {
	double x1 = array[0].real;
	double x2 = array[1].real;
	double y1 = array[0].imaginary;
	double y2 = array[1].imaginary;
	double realErg = 0;
	double imaginaryErg = 0;
	double teiler = 0;
	teiler = ((x2 * x2) + (y2 * y2));
	realErg = (((x1 * x2) + (x1 * y2)) / teiler);
	imaginaryErg = (((x2 * x1) - (x1 * y2)) / teiler);
	ausgabe(realErg, imaginaryErg);
	

}
