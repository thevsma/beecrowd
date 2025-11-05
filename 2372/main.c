#include <stdio.h>
#include <math.h>
#define MAXN 101

const int INF = pow(2,30);


int G[MAXN][MAXN];

int fixo[MAXN];
int dist[MAXN];
int maiores[MAXN];
int num_cidades, num_estradas, menor, maior;

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

int main(){
    int U, V, W;
    scanf("%d %d", &num_cidades, &num_estradas);
    for(int i = 0; i < num_cidades; i++)
        for(int j = 0; j < num_cidades; j++)
            G[i][j] = INF;

    for(int i = 0; i < num_estradas; i++){
        scanf("%d %d %d", &U, &V, &W);
        G[U][V] = G[V][U] = W;
    }

    for(int i = 0; i < num_cidades; i++){
        menor = INF;
        maior = 0;
        Dijkstra(i);
        for(int j = 0; j < num_cidades; j++){
            if(i != j && dist[j] > maior){
                maior = dist[j];
            }
        }
        maiores[i] = maior;
    }

    for(int i = 0; i < num_cidades; i++){
        if(maiores[i] < menor){
            menor = maiores[i];
        }
    }

    printf("%d\n", menor);

    return 0;
}