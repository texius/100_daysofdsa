#include <stdio.h>
#define MAX 1000

int main() {
    int queue[MAX];
    int front = 0, rear = 0;
    int n, val, m;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        queue[rear++] = val;
    }
    
    if (scanf("%d", &m) == 1) {
        front = (front + m) % n;
        int remaining = n - m;
        for (int i = 0; i < remaining; i++) {
            printf("%d", queue[(front + i) % n]);
            if (i < remaining - 1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
