#include <stdio.h>

#define MAX_N 50001

int pai[MAX_N];
int A, S;

int find(int i) {
    if (pai[i] == i) {
        return i;
    }

    return pai[i] = find(pai[i]);
}

int unite(int a, int b) {
    int raiz_a = find(a);
    int raiz_b = find(b);

    if (raiz_a != raiz_b) {
        pai[raiz_a] = raiz_b;
        return 1;
    }

    return 0;
}


int main() {
    scanf("%d", &A);
    scanf("%d", &S);

    int numero_de_familias = A;
    for (int i = 1; i <= A; i++) {
        pai[i] = i;
    }

    for (int k = 0; k < S; k++) {
        int a, b;
        scanf("%d %d", &a, &b);

        if (unite(a, b) == 1) {
            numero_de_familias--;
        }
    }

    printf("%d\n", numero_de_familias);

    return 0;
}