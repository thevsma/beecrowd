#include <stdio.h>

int main() {
    int t, total = 0, arr[5];

    scanf("%d",&t);
    for (int i = 0; i < 5; i++) {
        scanf("%d",&arr[i]);
    }

    for (int i = 0; i < 5; i++) {
        if (arr[i] == t) {
            total++;
        }
    }

    printf("%d\n", total);

    return 0;
}