#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int m, n, i, j;
    int mat1[MAX_SIZE][MAX_SIZE];
    int mat2[MAX_SIZE][MAX_SIZE];
    int result[MAX_SIZE][MAX_SIZE];

    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Read first matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat1[i][j]);
        }
    }

    // Read second matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat2[i][j]);
        }
    }

    // Add matrices
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // Print result matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            printf("%d", result[i][j]);
            if (j < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}
