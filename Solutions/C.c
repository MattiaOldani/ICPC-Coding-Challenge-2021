#include<stdio.h>
#include<stdlib.h>

//void quicksort(int *A, int i, int f);
//int partition(int *A, int i, int f);
void mergesort(int *A, int i, int f, int *B);
void merge(int *A, int i, int m, int f, int *B);

int main() {
    int N;
    scanf(" %d", &N);

    int *A, *B;
    A = malloc(N * sizeof(int));
    B = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        scanf(" %d", A + i);
    
    //quicksort(A, 0, N);
    mergesort(A, 0, N, B);

    printf("%d\n", A[N / 2] - A[N / 2 - 1]);

    free(A);
    free(B);

    return 0;
}

void mergesort(int *A, int i, int f, int *B) {
    if (abs(f - i) > 1) {
        int m;
        m = (i + f) / 2;
        mergesort(A, i, m, B);
        mergesort(A, m, f, B);
        merge(A, i, m, f, B);
    }
}

void merge(int *A, int i, int m, int f, int *B) {
    int i1, i2, k;
    i1 = i;
    i2 = m;
    k = 0;
    while (i1 < m && i2 < f)
        if (A[i1] < A[i2])
            B[k++] = A[i1++];
        else
            B[k++] = A[i2++];
    
    while (i1 < m)
        B[k++] = A[i1++];
    
    while (i2 < f)
        B[k++] = A[i2++];
    
    for (int t = 0; t < f - i; t++)
        A[t + i] = B[t];
}

/*
    PRIMA PROVA FATTA CON QUICKSORT
    IL TEST CASE #29 DAVA ERRORE DI TIMEOUT
    HO QUINDI IMPLEMENTATO UN MERGESORT
    MI DISPIACE DIRLO MA MIRKO 1-0 MATTIA

    void quicksort(int *A, int i, int f) {
        while (abs(f - i) > 1) {
            int m;
            m = partition(A, i, f);
            if (m - i < f - m) {
                quicksort(A, i, m);
                i = m + 1;
            } else {
                quicksort(A, m + 1, f);
                f = m;
            }
        }
    }

    int partition(int *A, int i, int f) {
        int pivot, sx, dx;
        pivot = A[i];
        sx = i;
        dx = f;
        while (sx < dx) {
            do {
                dx--;
            } while (A[dx] > pivot);
            do {
                sx++;
            } while (sx < dx && A[sx] <= pivot);
            if (sx < dx) {
                int x;
                x = A[dx];
                A[dx] = A[sx];
                A[sx] = x;
            }
        }

        int x;
        x = A[i];
        A[i] = A[dx];
        A[dx] = x;

        return dx;
    }
*/