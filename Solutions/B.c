#include<stdio.h>
#include<stdlib.h>

int main() {
    int N;
    scanf(" %d", &N);

    int *A;
    A = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf(" %d", A + i);

    int m1, m2;
    m1 = A[0];
    m2 = A[1];
    if (m1 < m2) {
        int x;
        x = m1;
        m1 = m2;
        m2 = x;
    }

    for (int i = 2; i < N; i++) {
        if (A[i] > m1) {
            m2 = m1;
            m1 = A[i];
        } else if (A[i] > m2) {
            m2 = A[i];
        }
    }

    for (int i = 0; i < N; i++)
        if (A[i] == m1)
            printf("%d\n", m2);
        else
            printf("%d\n", m1);
    
    free(A);

    return 0;
}