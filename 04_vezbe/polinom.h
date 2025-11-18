#ifndef POLINOM_H
#define POLINOM_H

#include <stdio.h>
#include <stdlib.h>

void greska();

int *unos(int *n);

void ispis_polinoma(int *a, int n);

int suma_polinoma(int *a, int n, int *b, int m, int **c);

void mnoz_skalar(int *a, int n, int c);

int vr_poly(int *a, int n, int x);

int mul_poly(int *a, int n, int *b, int m, int **c);

#endif