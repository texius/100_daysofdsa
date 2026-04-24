#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, pos, i;
    int arr[MAX_SIZE];

    // 1. Read size
    if (scanf("%d", &n) != 1) return 0;

    // 2. Read existing elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read position to delete (1-based)
    scanf("%d", &pos);

    // 4. Shift elements to the left (starting from pos position)
    // Delete element at pos (1-based), which is arr[pos-1]
    for (i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // 5. Print the updated array (now has n-1 elements)
    for (i = 0; i < n - 1; i++) {
        printf("%d", arr[i]);
        if (i < n - 2) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
