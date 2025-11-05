#include <stdio.h>
#include <math.h>
#define MAXN 251

const int INF = pow(2,30);


int G[MAXN][MAXN];

int fixo[MAXN];
int dist[MAXN];
int num_cidades, num_estradas, num_rota, cidade_conserto;

void Dijkstra(int origem)
{
    for(int i=0; i<num_cidades; i++)
    {
        fixo[i] = 0;
        dist[i] = INF;
    }
    dist[origem] = 0;

    for(int faltam = num_cidades; faltam>0; faltam--)
    {
        int no = -1;
        for(int i=0; i<num_cidades; i++)
            if(!fixo[i] && (no==-1 || dist[i] < dist[no]))
                no = i;

        if(no == -1) break;

        fixo[no] = 1;

        if(dist[no] == INF)
            break;

        for(int i=0; i<num_cidades; i++)
            if(dist[i] > dist[no]+G[no][i])
                dist[i] = dist[no]+G[no][i];
    }
}

int main() {
    int x, y, p;
    scanf("%d %d %d %d", &num_cidades, &num_estradas, &num_rota, &cidade_conserto);
    for(int i = 0; i < num_cidades; i++)
        for(int j = 0; j < num_cidades; j++)
            G[i][j] = INF;

    while(num_cidades > 0){
        for(int i = 0; i < num_estradas; i++){
            scanf("%d %d %d", &x, &y, &p);
            if(x < num_rota && y < num_rota){
                if(y == (x + 1)){
                    G[x][y] = p;
                }
                else if(x == (y + 1)){
                    G[y][x] = p;
                }
            }
            else if(x < num_rota || y < num_rota){
                if(x < num_rota){
                    G[y][x] = p;
                }
                else{
                    G[x][y] = p;
                }
            }
            else{
                G[x][y] = G[y][x] = p;
            }
        }

        Dijkstra(cidade_conserto);
        printf("%d\n", dist[num_rota-1]);

        scanf("%d %d %d %d", &num_cidades, &num_estradas, &num_rota, &cidade_conserto);
        for(int i = 0; i < num_cidades; i++)
            for(int j = 0; j < num_cidades; j++)
                G[i][j] = INF;
    }

    return 0;
}