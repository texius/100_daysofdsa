#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, i, max, min;
    int arr[MAX_SIZE];

    // Read size
    if (scanf("%d", &n) != 1) return 0;

    // Read elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize max and min
    max = arr[0];
    min = arr[0];

    // Find max and min
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    // Print result
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
