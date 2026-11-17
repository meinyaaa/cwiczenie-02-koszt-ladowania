#include <stdio.h>
#include "matrix.h"

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

int main() {
    double A[MAX][MAX] = {{1, 2}, {3, 4}};
    double B[MAX][MAX] = {{5, 6}, {7, 8}};
    double C[MAX][MAX];
    int wC, kC;

    sprawdz(dodaj(A, 2, 2, B, 2, 2, C, &wC, &kC) == OK, "Dodawanie poprawne wymiary");
    sprawdz(C[0][0] == 6, "Wynik dodawania [0][0] poprawny");
    
    sprawdz(dodaj(A, 2, 2, B, 1, 2, C, &wC, &kC) == BLAD_NIEZGODNE_WYMIARY, "Dodawanie zlych wymiarow prostokatnych");

    if (liczba_bledow == 0) printf("Wszystkie testy zaliczone!\n");
    return liczba_bledow > 0 ? 1 : 0;
}