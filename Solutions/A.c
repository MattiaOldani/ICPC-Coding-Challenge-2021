#include<stdio.h>
#include<stdlib.h>

int main() {
    int N;
    scanf(" %d", &N);

    int *A;
    A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf(" %d", A + i);
    
    int S1 = 0;
    int S2 = 0;
    int res;
    for (int i = 0; i < N; i++) {
        S2 += A[i];
    }
    res = abs(S2);

    for (int k = 0; k <= N; k++) {
        S2 -= A[k];
        S1 += A[k];
        if (abs(S1 - S2) < res)
            res = abs(S1 - S2);
    }

    printf("%d\n", res);

    free(A);

    return 0;
}