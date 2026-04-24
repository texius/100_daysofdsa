#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, k, i;
    int arr[MAX_SIZE];
    int comparisons = 0;
    int found = -1;

    // 1. Read array size
    if (scanf("%d", &n) != 1) return 0;

    // 2. Read n integers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read key to search
    scanf("%d", &k);

    // 4. Perform linear search and count comparisons
    for (i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            found = i;
            break;
        }
    }

    // 5. Output results
    if (found != -1) {
        printf("Found at index %d\n", found);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}
