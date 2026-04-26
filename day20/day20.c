#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, sum, count = 0;
    int arr[MAX_SIZE];

    // Read size
    if (scanf("%d", &n) != 1) return 0;

    // Read elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check all possible subarrays
    for (i = 0; i < n; i++) {
        sum = 0;
        for (j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                count++;
            }
        }
    }

    // Print result
    printf("%d\n", count);

    return 0;
}
