#include <stdio.h>
#include <stdlib.h>

void trocar(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int arr[], int ini, int fim) {
    int pivo = arr[fim], i = (ini - 1);

    for (int j = ini; j < fim; j++) {
        if (arr[j] <= pivo) {
            i++;
            trocar(&arr[i], &arr[j]);
        }
    }

    trocar(&arr[i + 1], &arr[fim]);
    return i + 1;
}

void quicksort(int arr[], int ini, int fim) {
    if (ini < fim) {
        int indice_pivo = particionar(arr, ini, fim);
        quicksort(arr, ini, indice_pivo - 1);
        quicksort(arr, indice_pivo + 1, fim);
    }
}

int main() {
    int N = 0, aux = 0, buffer[20];
    scanf("%d", &N);

    int* arr = (int*)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, N - 1);

    int atual = arr[0], count = 1;

    for (int i = 1; i < N; i++) {
        if (arr[i] == atual) {
            count++;
        }
        else {
            printf("%d aparece %d vez(es)\n", atual, count);
            atual = arr[i];
            count = 1;
        }
    }
    printf("%d aparece %d vez(es)\n", atual, count);
    free(arr);

    return 0;
}