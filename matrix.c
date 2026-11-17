#include "matrix.h"

int dodaj(double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC) {
    int i, j;
    if (wA != wB || kA != kB) return BLAD_NIEZGODNE_WYMIARY;
    *wC = wA; *kC = kA;
    for (i = 0; i < wA; i++)
        for (j = 0; j < kA; j++) C[i][j] = A[i][j] + B[i][j];
    return OK;
}

int odejmij(double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC) {
    int i, j;
    if (wA != wB || kA != kB) return BLAD_NIEZGODNE_WYMIARY;
    *wC = wA; *kC = kA;
    for (i = 0; i < wA; i++)
        for (j = 0; j < kA; j++) C[i][j] = A[i][j] - B[i][j];
    return OK;
}

int pomnoz(double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC) {
    int i, j, m;
    if (kA != wB) return BLAD_NIEZGODNE_WYMIARY;
    *wC = wA; *kC = kB;
    for (i = 0; i < wA; i++) {
        for (j = 0; j < kB; j++) {
            C[i][j] = 0;
            for (m = 0; m < kA; m++) C[i][j] += A[i][m] * B[m][j];
        }
    }
    return OK;
}

int wykonaj(int op, double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC) {
    if (op == 1) return dodaj(A, wA, kA, B, wB, kB, C, wC, kC);
    if (op == 2) return odejmij(A, wA, kA, B, wB, kB, C, wC, kC);
    if (op == 3) return pomnoz(A, wA, kA, B, wB, kB, C, wC, kC);
    return BLAD_NIEZNANA_OPERACJA;
}