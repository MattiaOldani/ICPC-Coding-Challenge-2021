#include<stdio.h>
#include<stdlib.h>

typedef struct work {
    int duration;
    int end;
} Work;

void mergesort(Work *A, int i, int f, Work *B);
void merge(Work *A, int i, int m, int f, Work *B);

int main() {
    int N;
    scanf(" %d", &N);

    Work *A, *B;
    A = malloc(N * sizeof(Work));
    B = malloc(N * sizeof(Work));
    for (int i = 0; i < N; i++)
        scanf(" %d %d", &(A + i) -> duration, &(A + i) -> end);
    
    mergesort(A, 0, N, B);

    int *end;
    end = malloc(N * sizeof(int));
    end[0] = A[0] . end;
    int last, counter = 1;
    last = A[0] . end;
    for (int i = 1; i < N; i++) {
        if (A[i] . end == last)
            continue;
        end[counter++] = A[i] . end;
        last = end[counter - 1];
    }

    int start = 0;
    int sum = 0;
    for (int i = 0; i < counter; i++) {
        int n = end[i];
        for (int t = start; A[t] . end == n && sum <= n; t++) {
            sum += A[t] . duration;
            start = t;
        }
        start++;
        if (sum > n) {
            printf("No\n");
            free(A);
            free(B);
            free(end);
            return 0;
        }
    }

    printf("Yes\n");

    free(A);
    free(B);
    free(end);

    return 0;
}

void mergesort(Work *A, int i, int f, Work *B) {
    if (abs(f - i) > 1) {
        int m;
        m = (i + f) / 2;
        mergesort(A, i, m, B);
        mergesort(A, m, f, B);
        merge(A, i, m, f, B);
    }
}

void merge(Work *A, int i, int m, int f, Work *B) {
    int i1, i2, k;
    i1 = i;
    i2 = m;
    k = 0;
    while (i1 < m && i2 < f)
        if (A[i1].end < A[i2].end)
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