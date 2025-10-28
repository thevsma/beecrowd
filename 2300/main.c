#include <stdio.h>
#include <string.h>

#define MAX_ESTACOES 101

int grafo[MAX_ESTACOES][MAX_ESTACOES];
int visitado[MAX_ESTACOES];
int E;

void dfs(int u) {
    visitado[u] = 1;

    for (int v = 1; v <= E; v++) {
        if (grafo[u][v] == 1 && visitado[v] == 0) {
            dfs(v);
        }
    }
}

int main() {
    int L, X, Y;
    int teste_n = 1;

    while (scanf("%d %d", &E, &L) == 2 && (E != 0 || L != 0)) {

        memset(grafo, 0, sizeof(grafo));
        memset(visitado, 0, sizeof(visitado));

        for (int i = 0; i < L; i++) {
            scanf("%d %d", &X, &Y);

            grafo[X][Y] = 1;
            grafo[Y][X] = 1;
        }

        dfs(1);

        int conectado = 1;
        for (int i = 1; i <= E; i++) {
            if (visitado[i] == 0) {
                conectado = 0;
                break;
            }
        }

        printf("Teste %d\n", teste_n);
        if (conectado) {
            printf("normal\n");
        } else {
            printf("falha\n");
        }
        printf("\n");

        teste_n++;
    }

    return 0;
}