#include <stdio.h>
#include <string.h>

#define MAX_N 2001

int N, M;
int grafo_normal[MAX_N][MAX_N];
int grafo_transposto[MAX_N][MAX_N];
int visitado[MAX_N];

void dfs(int u, int grafo_para_buscar[][MAX_N]) {
    visitado[u] = 1;

    for (int v = 1; v <= N; v++) {
        if (grafo_para_buscar[u][v] == 1 && visitado[v] == 0) {
            dfs(v, grafo_para_buscar);
        }
    }
}

int checar_todos_visitados() {
    for (int i = 1; i <= N; i++) {
        if (visitado[i] == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int V, W, P;

    while (scanf("%d %d", &N, &M) == 2 && (N != 0 || M != 0)) {

        memset(grafo_normal, 0, sizeof(grafo_normal));
        memset(grafo_transposto, 0, sizeof(grafo_transposto));

        for (int i = 0; i < M; i++) {
            scanf("%d %d %d", &V, &W, &P);

            if (P == 1) {
                grafo_normal[V][W] = 1;
                grafo_transposto[W][V] = 1;
            } else {
                grafo_normal[V][W] = 1;
                grafo_normal[W][V] = 1;

                grafo_transposto[V][W] = 1;
                grafo_transposto[W][V] = 1;
            }
        }

        memset(visitado, 0, sizeof(visitado));
        dfs(1, grafo_normal);

        if (checar_todos_visitados() == 0) {
            printf("0\n");
            continue;
        }

        memset(visitado, 0, sizeof(visitado));
        dfs(1, grafo_transposto);

        if (checar_todos_visitados() == 0) {
            printf("0\n");
        } else {
            printf("1\n");
        }
    }

    return 0;
}