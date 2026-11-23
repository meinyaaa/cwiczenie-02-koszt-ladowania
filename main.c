#include <stdio.h>
#include "matrix.h"
#include "matrix_io.h"

int main() {
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int wA, kA, wB, kB, wC, kC;
    int kod, op = 0;
    char plikA[100], plikB[100];
    char sciezkaA[110], sciezkaB[110];

    printf("Podaj nazwe pliku A (np. A.txt): ");
    scanf("%99s", plikA);
    sprintf(sciezkaA, "dane/%s", plikA);

    printf("Podaj nazwe pliku B (np. B.txt): ");
    scanf("%99s", plikB);
    sprintf(sciezkaB, "dane/%s", plikB);

    printf("Operacja: 1 dodawanie, 2 odejmowanie, 3 mnozenie\nwybor: ");
    if (scanf("%d", &op) != 1) op = 0;

    kod = wczytaj_macierz(sciezkaA, A, &wA, &kA);
    if (kod != OK) { fprintf(stderr, "Blad pliku A: %s\n", opis_bledu(kod)); return 1; }

    kod = wczytaj_macierz(sciezkaB, B, &wB, &kB);
    if (kod != OK) { fprintf(stderr, "Blad pliku B: %s\n", opis_bledu(kod)); return 1; }

    kod = wykonaj(op, A, wA, kA, B, wB, kB, C, &wC, &kC);
    if (kod != OK) { fprintf(stderr, "Blad obliczen: %s\n", opis_bledu(kod)); return 1; }

    kod = zapisz_macierz("wynik.txt", C, wC, kC);
    if (kod != OK) { fprintf(stderr, "Blad zapisu: %s\n", opis_bledu(kod)); return 1; }

    printf("Wyniki pomyslnie zapisane w pliku: wynik.txt.\n");
    return 0;
}