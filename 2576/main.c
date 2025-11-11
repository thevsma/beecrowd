#include <stdio.h>
#include <math.h>
#define MAXN 1001

const int INF = pow(2, 30);


int G[MAXN][MAXN];

int fixo[MAXN];
int dist[MAXN];
int C, S, A, B;

void Dijkstra(int origem)
{
    for(int i=0; i<C; i++)
    {
        fixo[i] = 0;
        dist[i] = INF;
    }
    dist[origem] = 0;

    for(int i = C; i>0; i--)
    {
        int no = -1;
        for(int i=0; i<C; i++)
            if(!fixo[i] && (no==-1 || dist[i] < dist[no]))
                no = i;

        if(no == -1 || dist[no] == INF)
            break;

        fixo[no] = 1;

        for(int i=0; i<C; i++)
            if(dist[i] > dist[no]+G[no][i])
                dist[i] = dist[no]+G[no][i];
    }
}

int main() {
    int C1, C2, bibi, bibika;
    scanf("%d %d %d %d", &C, &S, &A, &B);

    int orig_A = A - 1;
    int orig_B = B - 1;


    for(int i = 0; i < C; i++) {
        for(int j = 0; j < C; j++) {
            if (i == j) G[i][j] = 0;
            else G[i][j] = INF;
        }
    }

    for(int i = 0; i < S; i++) {
        scanf("%d %d", &C1, &C2);
        int u = C1 - 1;
        int v = C2 - 1;

        if(G[u][v] > 0) G[u][v] = 0;

        if(G[v][u] > 1) G[v][u] = 1;
    }

    Dijkstra(orig_A);
    bibi = dist[orig_B];

    Dijkstra(orig_B);
    bibika = dist[orig_A];

    if (bibi == INF && bibika == INF) {
        printf("Bibibibika\n");
    } else if (bibi == bibika) {
        printf("Bibibibika\n");
    } else if (bibi < bibika) {
        printf("Bibi: %d\n", bibi);
    } else {
        printf("Bibika: %d\n", bibika);
    }

    return 0;
}