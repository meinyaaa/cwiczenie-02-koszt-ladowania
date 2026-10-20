#include <stdio.h>
#define MAX 20

int main(void) {
    int wA = 2, kA = 3;
    double A[MAX][MAX] = {
        {1,2,3},
        {4,5,6}
    };

    int i, j;
    for(i = 0; i < wA; i++) {
        for(j = 0; j < kA; j++) {
            printf("%8.2lf", A[i][j]);
        }
        printf("\n");
    }
    return 0;
}