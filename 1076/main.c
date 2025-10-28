#include <stdio.h>
#include <string.h>

#define MAX_VERTICES 50

int main() {
    int arestas_vistas[MAX_VERTICES][MAX_VERTICES];
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        int V, A;
        int count = 0;

        scanf("%d", &N);
        scanf("%d %d", &V, &A);

        memset(arestas_vistas, 0, sizeof(arestas_vistas));

        for (int i = 0; i < A; i++) {
            int u, v;
            scanf("%d %d", &u, &v);

            int n1, n2;
            if (u < v) {
                n1 = u;
                n2 = v;
            } else {
                n1 = v;
                n2 = u;
            }

            if (arestas_vistas[n1][n2] == 0) {
                arestas_vistas[n1][n2] = 1;
                count++;
            }
        }
        int resultado = count * 2;
        printf("%d\n", resultado);
    }
    return 0;
}