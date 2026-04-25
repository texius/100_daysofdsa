#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, i, k;
    int arr[MAX_SIZE];
    int rotated[MAX_SIZE];

    // Read size
    if (scanf("%d", &n) != 1) return 0;

    // Read elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Read k
    scanf("%d", &k);

    // Normalize k in case k > n
    k = k % n;

    // Rotate elements to auxiliary array
    for (i = 0; i < n; i++) {
        int newPos = (i + k) % n;
        rotated[newPos] = arr[i];
    }

    // Print rotated array
    for (i = 0; i < n; i++) {
        printf("%d", rotated[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
