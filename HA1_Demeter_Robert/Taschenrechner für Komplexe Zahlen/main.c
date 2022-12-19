#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "funktionen.h"

int main() {
	char str1[10];
	char str2[10];
	RoI array[3] = { 0,0,0,0,0,0 };

	einlesen(str1);
	einlesen(str2);
	formatieren(str1, &array);
	formatieren(str2, &array);
	operation(array);
	

}