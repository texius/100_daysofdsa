#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int m, n, i, j;
    int mat[MAX_SIZE][MAX_SIZE];
    int isSymmetric = 1;

    // Read dimensions
    if (scanf("%d %d", &m, &n) != 2) return 0;

    // Read matrix
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Check if it's a square matrix
    if (m != n) {
        printf("Not a Symmetric Matrix\n");
        return 0;
    }

    // Check if matrix is symmetric
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (mat[i][j] != mat[j][i]) {
                isSymmetric = 0;
                break;
            }
        }
        if (!isSymmetric) {
            break;
        }
    }

    // Print result
    if (isSymmetric) {
        printf("Symmetric Matrix\n");
    } else {
        printf("Not a Symmetric Matrix\n");
    }

    return 0;
}
