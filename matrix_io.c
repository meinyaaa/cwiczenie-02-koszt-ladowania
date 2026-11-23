#include <stdio.h>
#include "matrix_io.h"

const char* opis_bledu(int kod) {
    switch (kod) {
        case BLAD_OTWARCIA: return "nie mozna otworzyc pliku";
        case BLAD_BRAK_WYMIAROW: return "brak wymiarow";
        case BLAD_ZAKRES: return "wymiary poza zakresem 1-20";
        case BLAD_ZA_MALO: return "za malo elementow";
        case BLAD_ELEMENT: return "element nie jest poprawna liczba";
        case BLAD_NIEZGODNE_WYMIARY: return "niezgodne wymiary dla wybranej operacji";
        case BLAD_ZAPISU: return "blad zapisu";
        case BLAD_NIEZNANA_OPERACJA: return "nieznana operacja";
        default: return "nieznany blad";
    }
}

int czytaj_dane(FILE *f, double M[][MAX], int *w, int *k) {
    int i, j, wynik;
    if (fscanf(f, "%d %d", w, k) != 2) return BLAD_BRAK_WYMIAROW;
    if (*w < 1 || *w > MAX || *k < 1 || *k > MAX) return BLAD_ZAKRES;
    
    for (i = 0; i < *w; i++) {
        for (j = 0; j < *k; j++) {
            wynik = fscanf(f, "%lf", &M[i][j]);
            if (wynik == EOF) return BLAD_ZA_MALO;
            if (wynik != 1) return BLAD_ELEMENT;
        }
    }
    return OK;
}

int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k) {
    FILE *f = fopen(nazwa, "r");
    int kod;
    if (f == NULL) return BLAD_OTWARCIA;
    kod = czytaj_dane(f, M, w, k);
    fclose(f);
    return kod;
}

int zapisz_macierz(const char *nazwa, double M[][MAX], int w, int k) {
    int i, j, blad;
    FILE *f = fopen(nazwa, "w");
    if (f == NULL) return BLAD_OTWARCIA;
    
    fprintf(f, "%d %d\n", w, k);
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            if (j > 0) fprintf(f, " ");
            fprintf(f, "%.2f", M[i][j]);
        }
        fprintf(f, "\n");
    }
    
    blad = ferror(f);
    if (fclose(f) != 0) blad = 1;
    return blad ? BLAD_ZAPISU : OK;
}

void wypisz_macierz(double M[][MAX], int w, int k) {
    int i, j;
    for (i = 0; i < w; i++) {
        for (j = 0; j < k; j++) {
            printf("%.2f ", M[i][j]);
        }
        printf("\n");
    }
}