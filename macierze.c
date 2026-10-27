#include <stdio.h>
#define MAX 20

void wypisz(double M[][MAX], int w, int k) {
    int i, j;
    for(i = 0; i < w; i++) {
        for(j = 0; j < k; j++) {
            printf("%8.2f", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void suma(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k) {
    int i, j;
    for(i = 0; i < w; i++) {
        for(j = 0; j < k; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

void roznica(double A[][MAX], double B[][MAX], double C[][MAX], int w, int k) {
    int i, j;
    for(i = 0; i < w; i++) {
        for(j = 0; j < k; j++) {
            C[i][j] = A[i][j] - B[i][j];
        }
    }
}

void pomnoz(double A[][MAX], double B[][MAX], double C[][MAX], int wA, int kA, int kB) {
    int i, j, n;
    double s;
    for(i = 0; i < wA; i++) {
        for(j = 0; j < kB; j++) {
            s = 0.0;
            for(n = 0; n < kA; n++) {
                s = s + A[i][n] * B[n][j];
            }
            C[i][j] = s;
        }
    }
}

int czy_zgodne_wymiary(int wA, int kA, int wB, int kB) {
    return (wA == wB && kA == kB);
}

int czy_zgodne_mnozenie(int kA, int wB) {
    return (kA == wB);
}

int main(void) {
    int wA = 2, kA = 2;
    int wB = 2, kB = 2;
    int wP = 2, kP = 3;
    int wQ = 3, kQ = 2;
    
    double A[MAX][MAX] = {
        {1, 2},
        {3, 4}
    };
    
    double B[MAX][MAX] = {
        {5, 6},
        {7, 8}
    };
    double P[MAX][MAX] = {
        {1, 2, 3},
        {4, 5, 6}
    };
    double Q[MAX][MAX] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    
    double C[MAX][MAX];

    printf("Macierz A:\n");
    wypisz(A, wA, kA);

    printf("Macierz B:\n");
    wypisz(B, wB, kB);

    printf("Macierz P:\n");
    wypisz(P, wP, kP);

    printf("Macierz Q:\n");
    wypisz(Q, wQ, kQ);

    double pierwszy_elementPxQ = P[0][0] * Q[0][0] + P[0][1] * Q[1][0] + P[0][2] * Q[2][0];
    printf("Recznie policzony pierwszy element P x Q:\n");
    printf("C[0][0] = (1 * 7) + (2 * 9) + (3 * 11) = 7 + 18 + 33 = %.2f\n\n", pierwszy_elementPxQ);

    double pierwszy_elementAxB = A[0][0] * B[0][0] + A[0][1] * B[1][0] + A[0][2] * B[2][0];
    printf("Recznie policzony pierwszy element A x B:\n");
    printf("C[0][0] = (1 * 5) + (2 * 7) = 5 + 14 = %.2f\n\n", pierwszy_elementAxB);

    if (czy_zgodne_wymiary(wA, kA, wB, kB)) {
        suma(A, B, C, wA, kA);
        printf("Suma (A + B):\n");
        wypisz(C, wA, kA);
    }
    else {
        printf("Blad: niezgodne wymiary");
    }

    if (czy_zgodne_wymiary(wA, kA, wB, kB)) {
        roznica(A, B, C, wA, kA);
        printf("Roznica (A - B):\n");
        wypisz(C, wA, kA);
    }
    else {
        printf("Blad: niezgodne wymiary");
    }
    
    if (czy_zgodne_mnozenie(kP, wQ)) {
        pomnoz(P, Q, C, wP, kP, kQ);
        printf("Wynik mnozenia P x Q (wymiar %dx%d):\n", wP, kQ);
        wypisz(C, wP, kQ);
    } else {
        printf("Blad: Nie można pomnozyc P x Q\n");
    }
    
    if (czy_zgodne_mnozenie(kA, wB)) {
        pomnoz(A, B, C, wA, kA, kB);
        printf("Wynik mnozenia A x B (wymiar %dx%d):\n", wA, kB);
        wypisz(C, wA, kB);
    } else {
        printf("Blad: Nie można pomnozyc A x B\n");
    }

    if (czy_zgodne_mnozenie(kQ, wP)) {
        double QP[MAX][MAX];
        pomnoz(Q, P, QP, wQ, kQ, kP);
        printf("Wynik mnozenia Q x P (wymiar %dx%d):\n", wQ, kP);
        wypisz(QP, wQ, kP);
    } else {
        printf("Blad: Nie można pomnozyc Q x P\n");
    }

    printf("Proba mnozenia P x A:\n");
    if (czy_zgodne_mnozenie(kP, wA)) {
        pomnoz(P, A, C, wP, kP, kA);
        wypisz(C, wP, kA);
    } else {
        printf("Niezgodne wymiary\n");
    }

    printf("Proba dodawania P + Q:\n");
    if (czy_zgodne_wymiary(wP, kP, wQ, kQ)) {
        suma(P, Q, C, wP, kP);
        wypisz(C, wP, kP);
    } else {
        printf("Niezgodne wymiary\n\n");
    }
    return 0;
}