#pragma once
#define _CRT_SECURE_NO_WARNINGS

typedef double (*ptr)(double);

double f(double x);
double f_an(double x);
double f_num(double x);
double newton(int p);