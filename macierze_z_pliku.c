#include <stdio.h>
#include <stdlib.h>

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
    if (fscanf(f, "%d %d", w, k) != 2) return BLAD_BRAK_WYMIAROW;
    if (*w < 1 || *w > MAX || *k < 1 || *k > MAX) return BLAD_ZAKRES;
    
    for (int i = 0; i < *w; i++) {
        for (int j = 0; j < *k; j++) {
            int wynik = fscanf(f, "%lf", &M[i][j]);
            if (wynik == EOF) return BLAD_ZA_MALO;
            if (wynik != 1) return BLAD_ELEMENT;
        }
    }
    return OK;
}

int wczytaj_macierz(const char *nazwa, double M[][MAX], int *w, int *k) {
    FILE *f = fopen(nazwa, "r");
    if (f == NULL) return BLAD_OTWARCIA;
    int kod = czytaj_dane(f, M, w, k);
    fclose(f);
    return kod;
}

int zapisz_macierz(const char *nazwa, double M[][MAX], int w, int k) {
    FILE *f = fopen(nazwa, "w");
    if (f == NULL) return BLAD_OTWARCIA;
    
    fprintf(f, "%d %d\n", w, k);
    for (int i = 0; i < w; i++) {
        for (int j = 0; j < k; j++) {
            if (j > 0) fprintf(f, " ");
            fprintf(f, "%.2f", M[i][j]);
        }
        fprintf(f, "\n");
    }
    
    int blad = ferror(f);
    if (fclose(f) != 0) blad = 1;
    return blad ? BLAD_ZAPISU : OK;
}

int wykonaj(int op, double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double C[][MAX], int *wC, int *kC) {
    if (op == 1) {
        if (wA != wB || kA != kB) return BLAD_NIEZGODNE_WYMIARY;
        *wC = wA; *kC = kA;
        for (int i = 0; i < wA; i++)
            for (int j = 0; j < kA; j++) C[i][j] = A[i][j] + B[i][j];
        return OK;
    } 
    if (op == 2) { 
        if (wA != wB || kA != kB) return BLAD_NIEZGODNE_WYMIARY;
        *wC = wA; *kC = kA;
        for (int i = 0; i < wA; i++)
            for (int j = 0; j < kA; j++) C[i][j] = A[i][j] - B[i][j];
        return OK;
    } 
    if (op == 3) { 
        if (kA != wB) return BLAD_NIEZGODNE_WYMIARY;
        *wC = wA; *kC = kB;
        for (int i = 0; i < wA; i++) {
            for (int j = 0; j < kB; j++) {
                C[i][j] = 0;
                for (int m = 0; m < kA; m++) C[i][j] += A[i][m] * B[m][j];
            }
        }
        return OK;
    }
    return BLAD_NIEZNANA_OPERACJA;
}

int main() {
    double A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];
    int wA, kA, wB, kB, wC, kC;
    int kod, op = 0;


    kod = wczytaj_macierz("dane/A.txt", A, &wA, &kA);
    if (kod != OK) { fprintf(stderr, "Blad: %s\n", opis_bledu(kod)); return 1; }

    kod = wczytaj_macierz("dane/B.txt", B, &wB, &kB);
    if (kod != OK) { fprintf(stderr, "Blad: %s\n", opis_bledu(kod)); return 1; }

  
    printf("Operacja: 1 dodawanie, 2 odejmowanie, 3 mnozenie\n");
    if (scanf("%d", &op) != 1) op = 0;

    kod = wykonaj(op, A, wA, kA, B, wB, kB, C, &wC, &kC);
    if (kod != OK) { fprintf(stderr, "Blad: %s\n", opis_bledu(kod)); return 1; }

    kod = zapisz_macierz("wynik.txt", C, wC, kC);
    if (kod != OK) { fprintf(stderr, "Blad: %s\n", opis_bledu(kod)); return 1; }

    printf("wyniki zapisane w pliku: wynik.txt.\n");
    return 0;
}