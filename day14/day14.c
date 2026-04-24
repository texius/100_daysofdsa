#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int n, i, j;
    int mat[MAX_SIZE][MAX_SIZE];
    int isIdentity = 1;

    // Read size
    if (scanf("%d", &n) != 1) return 0;

    // Read matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Check identity matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if ((i == j && mat[i][j] != 1) || (i != j && mat[i][j] != 0)) {
                isIdentity = 0;
                break;
            }
        }
        if (!isIdentity) break;
    }

    if (isIdentity) {
        printf("Identity Matrix\n");
    } else {
        printf("Not an Identity Matrix\n");
    }
    return 0;
}
