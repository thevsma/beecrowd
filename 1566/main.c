#include <stdio.h>
#include <stdlib.h>

#define MAX_ALTURA 231  // 230 + 1 (índice 0 não será usado)
#define MIN_ALTURA 20

int main() {
    int NC, N, altura;
    int cont[MAX_ALTURA]; // O índice representa a altura

    scanf("%d", &NC);
    while (NC--) {
        scanf("%d", &N);

        // Zera o contador de alturas
        for (int i = 0; i < MAX_ALTURA; i++) cont[i] = 0;

        // Conta cada altura lida
        for (int i = 0; i < N; i++) {
            scanf("%d", &altura);
            cont[altura]++;
        }

        // Imprime as alturas ordenadas
        int primeiro = 1;
        for (int i = MIN_ALTURA; i < MAX_ALTURA; i++) {
            while (cont[i]--) {
                if (!primeiro) printf(" ");
                printf("%d", i);
                primeiro = 0;
            }
        }
        printf("\n");
    }
    return 0;
}