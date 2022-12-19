#pragma once
typedef struct Real_or_Imaginary {
	double real;
	double imaginary;
}RoI;

void einlesen(char* str);
void formatieren(char* str, RoI array[]);
int pruefen(char* str);
void plus(RoI array[]);
void minus(RoI array[]);
void multiplikation(RoI array[]);
void division(RoI array[]);
void operation(RoI array[]);
void ausgabe(double real, double imaginary);