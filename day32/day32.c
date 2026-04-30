#include <stdio.h>
#define MAX 1000

int main() {
    int n, m, val;
    int stack[MAX];
    int top = -1;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        stack[++top] = val;
    }
    scanf("%d", &m);
    while (m-- && top >= 0) {
        top--;
    }

    for (int i = top; i >= 0; i--) {
        printf("%d", stack[i]);
        if (i > 0) printf(" ");
    }
    printf("\n");
    return 0;
}
