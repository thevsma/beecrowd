#include <stdio.h>
#include <stdlib.h>

void bubblesort(int arr[], int n, int* count) {
    int swapped;

    for (int i = 0; i < (n - 1); i++) {
        swapped = 0;

        for (int j = 0; j < (n - 1); j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
                (*count)++;
            }
        }

        if (!swapped) break;
    }
}

int main() {
    int N;

    scanf("%d",&N);
    if (N == 0) return 0;

    int L;
    while (N > 0) {
        int count = 0;
        scanf("%d", &L);
        int* arr = (int*)malloc(L * sizeof(int));

        for (int i = 0; i < L; i++) {
            scanf("%d",&arr[i]);
        }

        bubblesort(arr, L, &count);
        printf("Optimal train swapping takes %d swaps.\n", count);

        free(arr);
        N--;
    }

    return 0;
}