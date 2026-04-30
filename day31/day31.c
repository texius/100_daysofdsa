#include <stdio.h>
#define MAX 1000

int main() {
    int stack[MAX];
    int top = -1;
    int n, type, val;

    if (scanf("%d", &n) != 1) return 0;

    while (n--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &val);
            if (top < MAX - 1) stack[++top] = val;
        } else if (type == 2) {
            if (top == -1) printf("Stack Underflow\n");
            else printf("%d\n", stack[top--]);
        } else if (type == 3) {
            for (int i = top; i >= 0; i--) {
                printf("%d", stack[i]);
                if (i > 0) printf(" ");
            }
            printf("\n");
        }
    }
    return 0;
}
