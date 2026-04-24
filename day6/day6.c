#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, i, j;
    int arr[MAX_SIZE];

    // 1. Read array size
    if (scanf("%d", &n) != 1) return 0;

    // 2. Read n integers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Remove duplicates in-place using two-pointer technique
    j = 0;  // pointer for unique elements
    
    for (i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    // 4. Print unique elements (0 to j inclusive)
    for (i = 0; i <= j; i++) {
        printf("%d", arr[i]);
        if (i < j) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
