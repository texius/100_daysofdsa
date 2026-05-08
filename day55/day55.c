#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int arr[1000];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    int level = 0;
    int start = 0;
    int printed = 0;

    while (start < n) {
        int nodesInLevel = 1 << level;
        int end = start + nodesInLevel - 1;
        if (end >= n) end = n - 1;
        
        int rightmost = -1;
        for (int i = start; i <= end; i++) {
            if (arr[i] != -1) {
                rightmost = arr[i];
            }
        }
        if (rightmost != -1) {
            if (printed) printf(" ");
            printf("%d", rightmost);
            printed = 1;
        }
        
        start = end + 1;
        level++;
    }
    printf("\n");
    return 0;
}
