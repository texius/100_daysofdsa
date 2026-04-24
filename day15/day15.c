#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int m, n, i, j, sum = 0;
    int mat[MAX_SIZE][MAX_SIZE];

    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Read matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Sum primary diagonal
    for (i = 0; i < m && i < n; i++) {
        sum += mat[i][i];
    }
    printf("%d\n", sum);
    return 0;
}
