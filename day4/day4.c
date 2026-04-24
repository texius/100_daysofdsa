#include <stdio.h>

#define MAX_SIZE 1000

int main() {
    int n, i;
    int arr[MAX_SIZE];

    // 1. Read array size
    if (scanf("%d", &n) != 1) return 0;

    // 2. Read n integers
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // 3. Reverse array using two-pointer approach
    int left = 0;
    int right = n - 1;
    
    while (left < right) {
        // Swap arr[left] and arr[right]
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;
        left++;
        right--;
    }

    // 4. Print reversed array
    for (i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}
