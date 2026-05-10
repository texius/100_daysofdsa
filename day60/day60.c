#include <stdio.h>

int main() {
    int n;
    int arr[1000];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    int valid = 1;
    for (int i = 0; i <= (n / 2) - 1; i++) {
        if (arr[i] == -1) continue;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left < n && arr[left] != -1 && arr[i] > arr[left]) {
            valid = 0;
            break;
        }
        if (right < n && arr[right] != -1 && arr[i] > arr[right]) {
            valid = 0;
            break;
        }
    }
    
    if (valid) printf("YES\n");
    else printf("NO\n");
    return 0;
}
