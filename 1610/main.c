#include <stdio.h>
#include <string.h>

#define MAX_N 10001
#define MAX_M 30000

int head[MAX_N];
int to[MAX_M];
int next[MAX_M];
int edge_count;

int visitado[MAX_N];

void add_edge(int A, int B) {
    to[edge_count] = B;
    next[edge_count] = head[A];
    head[A] = edge_count;
    edge_count++;
}

int dfs(int u) {
    visitado[u] = 1;

    for (int k = head[u]; k != -1; k = next[k]) {
        int v = to[k];

        if (visitado[v] == 1) {
            return 1;
        }

        if (visitado[v] == 0) {
            if (dfs(v) == 1) {
                return 1;
            }
        }

    }

    visitado[u] = 2;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        edge_count = 0;
        memset(head, -1, sizeof(head));
        memset(visitado, 0, sizeof(visitado));

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            add_edge(A, B);
        }

        int ciclo_encontrado = 0;

        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                if (dfs(i) == 1) {
                    ciclo_encontrado = 1;
                    break;
                }
            }
        }

        if (ciclo_encontrado) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
    }

    return 0;
}