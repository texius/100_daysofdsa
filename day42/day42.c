#include <stdio.h>
#define MAX 1000

int main() {
    int n;
    int queue[MAX];
    int stack[MAX];
    int top = -1;
    
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }
    
    for (int i = 0; i < n; i++) {
        stack[++top] = queue[i];
    }
    
    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d", queue[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
