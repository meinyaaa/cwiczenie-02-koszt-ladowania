#include <stdio.h>
#define MAX 20

int main(void) {
    int wA = 2, kA = 3, wB = 2, kB = 3, wC = 2, kC = 3;
    double A[MAX][MAX] = {
        {1,2,3},
        {4,5,6}
    };
    double B[MAX][MAX] = {
        {4,8,2},
        {1,6,7}
    };
    double C[MAX][MAX];

    if(wA < 1 || wA > MAX || kA < 1 || kA > MAX || wB < 1 || wB > MAX || kB < 1 || kB > MAX) {
        printf("Blad: wymiary macierzy poza zakresem\n");
        return 1;
    }
    if(wA != wB || kA != kB) {
        printf("Blad: niezgodne wymiary macierzy\n");
        return 1;
    }

    int i, j;
    printf("\nA\n");
    for(i = 0; i < wA; i++) {
        for(j = 0; j < kA; j++) {
            printf("%8.2lf", A[i][j]);
        }
        printf("\n");
    }
    printf("\nB\n");
    for(i = 0; i < wB; i++) {
        for(j = 0; j < kB; j++) {
            printf("%8.2lf", B[i][j]);
        }
        printf("\n");
    }
    printf("\nSuma A + B\n");
    for(i = 0; i < wC; i++) {
        for(j = 0; j < kC; j++) {
            C[i][j] = A[i][j] + B[i][j];
            printf("%8.2lf", C[i][j]);
        }
        printf("\n");
    }

    printf("\nRoznica A - B\n");
    for(i = 0; i < wC; i++) {
        for(j = 0; j < kC; j++) {
            C[i][j] = A[i][j] - B[i][j];
            printf("%8.2lf", C[i][j]);
        }
        printf("\n");
    }
    return 0;
}