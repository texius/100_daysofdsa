#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j, count;
    int arr[MAX_SIZE];
    int freq[MAX_SIZE];

    // Read size
    if (scanf("%d", &n) != 1) return 0;

    // Read elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        freq[i] = -1; // Initialize frequency array with -1
    }

    // Count frequency of each element
    for (i = 0; i < n; i++) {
        count = 1;
        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                freq[j] = 0; // Mark as visited
            }
        }
        if (freq[i] != 0) {
            freq[i] = count;
        }
    }

    // Print elements and their frequencies
    int first = 1;
    for (i = 0; i < n; i++) {
        if (freq[i] != 0) {
            if (!first) printf(" ");
            printf("%d:%d", arr[i], freq[i]);
            first = 0;
        }
    }
    printf("\n");

    return 0;
}
