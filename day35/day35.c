#include <stdio.h>
#define MAX 1000

int main() {
    int queue[MAX];
    int front = 0, rear = 0;
    int n, val;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        queue[rear++] = val;
    }

    for (int i = front; i < rear; i++) {
        printf("%d", queue[i]);
        if (i < rear - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
