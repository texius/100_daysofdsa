#include <stdio.h>

int main() {
    int arr[1000];
    int n = 0;
    
    // Read elements until EOF
    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }
    
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                if (j - i + 1 > max_len) {
                    max_len = j - i + 1;
                }
            }
        }
    }
    
    printf("%d\n", max_len);
    return 0;
}
