#include <stdio.h>
#include "matrix.h"
#include "matrix_io.h"

int liczba_testow = 0;
int liczba_bledow = 0;

static void sprawdz(int warunek, const char *opis) {
    liczba_testow++;
    if (warunek) {
        printf("[ OK ] %s\n", opis);
    } else {
        liczba_bledow++;
        printf("[BLAD] %s\n", opis);
    }
}

int main(void) {
    double A[MAX][MAX] = {{1.0, -2.0}, {0.0, 4.0}};
    double B[MAX][MAX] = {{5.0, 6.0}, {-7.0, 8.0}};
    double P[MAX][MAX] = {{1.0, 2.0, 3.0}, {4.0, 5.0, 6.0}};
    double Q[MAX][MAX] = {{7.0, 8.0}, {9.0, 10.0}, {11.0, 12.0}};
    double M1[MAX][MAX] = {{5.5}};
    double M2[MAX][MAX] = {{-2.0}};
    double DuzaA[MAX][MAX];
    double DuzaB[MAX][MAX];
    double C[MAX][MAX];
    int wC, kC;
    int i, j;

    sprawdz(dodaj(A, 2, 2, B, 2, 2, C, &wC, &kC) == OK, "Dodawanie: kod OK");
    sprawdz(wC == 2 && kC == 2, "Dodawanie: poprawne wymiary wyniku");
    sprawdz(C[0][0] == 6.0 && C[0][1] == 4.0 && C[1][0] == -7.0 && C[1][1] == 12.0, "Dodawanie: poprawne wartosci (zera i ujemne)");

    sprawdz(odejmij(A, 2, 2, B, 2, 2, C, &wC, &kC) == OK, "Odejmowanie: kod OK");
    sprawdz(C[0][0] == -4.0 && C[0][1] == -8.0 && C[1][0] == 7.0 && C[1][1] == -4.0, "Odejmowanie: poprawne wartosci");

    sprawdz(pomnoz(P, 2, 3, Q, 3, 2, C, &wC, &kC) == OK, "Mnozenie prostokatnych: kod OK");
    sprawdz(wC == 2 && kC == 2, "Mnozenie prostokatnych: wymiary 2x2");
    sprawdz(C[0][0] == 58.0 && C[0][1] == 64.0 && C[1][0] == 139.0 && C[1][1] == 154.0, "Mnozenie prostokatnych: poprawne wartosci");

    sprawdz(pomnoz(M1, 1, 1, M2, 1, 1, C, &wC, &kC) == OK, "Macierz 1x1 mnozenie: kod OK");
    sprawdz(wC == 1 && kC == 1 && C[0][0] == -11.0, "Macierz 1x1 mnozenie: wynik -11.0");

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            DuzaA[i][j] = 1.0;
            DuzaB[i][j] = 2.0;
        }
    }
    sprawdz(dodaj(DuzaA, MAX, MAX, DuzaB, MAX, MAX, C, &wC, &kC) == OK, "Limit 20x20 dodawanie: kod OK");
    sprawdz(C[19][19] == 3.0, "Limit 20x20 dodawanie: ostatni element poprawny");

    sprawdz(dodaj(A, 2, 2, P, 2, 3, C, &wC, &kC) == BLAD_NIEZGODNE_WYMIARY, "Dodawanie: wykrycie niezgodnych wymiarow");
    sprawdz(odejmij(A, 2, 2, P, 2, 3, C, &wC, &kC) == BLAD_NIEZGODNE_WYMIARY, "Odejmowanie: wykrycie niezgodnych wymiarow");
    sprawdz(pomnoz(A, 2, 2, Q, 3, 2, C, &wC, &kC) == BLAD_NIEZGODNE_WYMIARY, "Mnozenie: wykrycie niezgodnych wymiarow");
    sprawdz(wykonaj(99, A, 2, 2, B, 2, 2, C, &wC, &kC) == BLAD_NIEZNANA_OPERACJA, "Wykonaj: wykrycie nieznanej operacji");

    sprawdz(wczytaj_macierz("nieistniejacy_plik_testowy.txt", C, &wC, &kC) == BLAD_OTWARCIA, "I/O: wykrycie braku pliku");

    printf("\nPodsumowanie: %d/%d testow zaliczonych.\n", liczba_testow - liczba_bledow, liczba_testow);
    return liczba_bledow > 0 ? 1 : 0;
}