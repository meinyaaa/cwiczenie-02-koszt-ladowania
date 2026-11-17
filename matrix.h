#ifndef MATRIX_H
#define MATRIX_H

#define MAX 20

#define OK 0
#define BLAD_OTWARCIA 1
#define BLAD_BRAK_WYMIAROW 2
#define BLAD_ZAKRES 3
#define BLAD_ZA_MALO 4
#define BLAD_ELEMENT 5
#define BLAD_NIEZGODNE_WYMIARY 6
#define BLAD_ZAPISU 7
#define BLAD_NIEZNANA_OPERACJA 8

int dodaj(double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC);
int odejmij(double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC);
int pomnoz(double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC);
int wykonaj(int op, double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC);

#endif