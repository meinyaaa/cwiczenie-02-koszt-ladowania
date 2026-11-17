#include <stdio.h>
#define MAX 20

int czytajDane(FILE *f, double M[][MAX], int *w, int *k) {
    if(*w<1 || *k<1 || *w>MAX || *k>MAX) {
        printf("niepoprawne wymiary\n");
        return 1;
    }
    for(int i = 0; i<*w; i++) {
        for(int j = 0; j<*k; j++){
            int wynik = fscanf(f, "%lf", &M[i][j]);
            if(wynik != 1) {
                printf("blad odczytu danych\n");
                return 1;
            }
        }
    }
    return 0;
}

int wczytajMacierz(const char *nazwa, double M[][MAX], int *w, int *k) {
    FILE *f = fopen(nazwa, "r");
    if(f == NULL) {
        printf("blad otwarcia pliku");
        return 1;
    }
    int kod = czytajDane(f, M, w, k);
    fclose(f);
    return kod;
}

int zapiszMacierz(const char *nazwa, double M[][MAX], int w, int k) {
    FILE *f = fopen(nazwa, "w");
    if(f == NULL) {
        printf("blad otwarcia pliku");
        return 1;
    }
    fprintf(f, "%d %d\n", w, k);
    for(int i = 0; i<w; i++) {
        for(int j = 0; j<k; j++) {
            if(j>0) fprintf(f, " ");
            fprintf(f, "%.2f", M[i][j]);
        }
        fprintf(f, "\n");
    }
    int blad = ferror(f);
    if(fclose(f) != 0) blad = 1;
    return blad ? 1 : 0;
}

int dzialanie(int op, double A[][MAX], int wA, int kA, double B[][MAX], int wB, int kB, double c[][MAX], int *wC, int *kC) {
    
}