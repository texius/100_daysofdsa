#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int r, c, i, j;
    int mat[MAX_SIZE][MAX_SIZE];

    // Read dimensions
    if (scanf("%d %d", &r, &c) != 2) return 0;

    // Read matrix
    for (i = 0; i < r; i++) {
        for (j = 0; j < c; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    int top = 0, bottom = r - 1, left = 0, right = c - 1;
    int count = 0, total = r * c;

    while (count < total) {
        // Traverse top row
        for (j = left; j <= right && count < total; j++) {
            printf("%d", mat[top][j]);
            count++;
            if (count < total) printf(" ");
        }
        top++;
        // Traverse right column
        for (i = top; i <= bottom && count < total; i++) {
            printf("%d", mat[i][right]);
            count++;
            if (count < total) printf(" ");
        }
        right--;
        // Traverse bottom row
        for (j = right; j >= left && count < total; j--) {
            printf("%d", mat[bottom][j]);
            count++;
            if (count < total) printf(" ");
        }
        bottom--;
        // Traverse left column
        for (i = bottom; i >= top && count < total; i--) {
            printf("%d", mat[i][left]);
            count++;
            if (count < total) printf(" ");
        }
        left++;
    }
    printf("\n");
    return 0;
}
