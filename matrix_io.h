#ifndef MATRIX_IO_H
#define MATRIX_IO_H

#include "matrix.h"

const char* opis_bledu(int kod);
int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k);
int zapisz_macierz(const char *nazwa, double M[][MAX], int w, int k);
void wypisz_macierz(double M[][MAX], int w, int k);

#endif