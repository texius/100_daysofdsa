#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, min_sum, sum, element1, element2;
    int arr[MAX_SIZE];

    // Read size
    if (scanf("%d", &n) != 1 || n < 2) return 0;

    // Read elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Initialize min_sum with a large value
    min_sum = INT_MAX;

    // Check all pairs
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            sum = arr[i] + arr[j];
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                element1 = arr[i];
                element2 = arr[j];
            }
        }
    }

    // Print the pair
    // Note: The example shows the pair in specific order, 
    // usually smaller first or as they appear.
    printf("%d %d\n", element1, element2);

    return 0;
}
