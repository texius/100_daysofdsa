#include <stdio.h>

#define MAX_SIZE 1000 // Defining a safe maximum limit

int main() {
    int n, pos, x, i;
    int arr[MAX_SIZE]; 

    // 1. Read size
    if (scanf("%d", &n) != 1) return 0;

    // 2. Read existing elements
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Read position and new element
    scanf("%d", &pos);
    scanf("%d", &x);

    // 4. Shift elements to the right
    // We start from the end and move towards the target index
    for (i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // 5. Insert x at the 0-based index (pos - 1)
    arr[pos - 1] = x;

    // 6. Print the updated array (now has n+1 elements)
    for (i = 0; i <= n; i++) {
        printf("%d", arr[i]);
        if (i < n) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
