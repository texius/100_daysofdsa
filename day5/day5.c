#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int p, q, i, j, k;
    int arr1[MAX_SIZE], arr2[MAX_SIZE], merged[MAX_SIZE * 2];

    // 1. Read first array size and elements
    if (scanf("%d", &p) != 1) return 0;
    for (i = 0; i < p; i++) {
        scanf("%d", &arr1[i]);
    }

    // 2. Read second array size and elements
    if (scanf("%d", &q) != 1) return 0;
    for (i = 0; i < q; i++) {
        scanf("%d", &arr2[i]);
    }

    // 3. Merge two sorted arrays
    i = 0;  // pointer for arr1
    j = 0;  // pointer for arr2
    k = 0;  // pointer for merged array

    while (i < p && j < q) {
        if (arr1[i] <= arr2[j]) {
            merged[k++] = arr1[i++];
        } else {
            merged[k++] = arr2[j++];
        }
    }

    // 4. Add remaining elements from arr1
    while (i < p) {
        merged[k++] = arr1[i++];
    }

    // 5. Add remaining elements from arr2
    while (j < q) {
        merged[k++] = arr2[j++];
    }

    // 6. Print merged array
    for (i = 0; i < p + q; i++) {
        printf("%d", merged[i]);
        if (i < p + q - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
