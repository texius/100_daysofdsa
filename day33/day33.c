#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 1000

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

int main() {
    char infix[MAX], postfix[MAX], stack[MAX];
    int top = -1, j = 0;

    if (scanf("%s", infix) != 1) return 0;

    for (int i = 0; infix[i]; i++) {
        char c = infix[i];
        if (isalnum(c)) {
            postfix[j++] = c;
        } else if (c == '(') {
            stack[++top] = c;
        } else if (c == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[j++] = stack[top--];
            }
            if (top != -1) top--;
        } else {
            while (top != -1 && precedence(stack[top]) >= precedence(c)) {
                postfix[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }
    while (top != -1) {
        postfix[j++] = stack[top--];
    }
    postfix[j] = '\0';
    
    printf("%s\n", postfix);
    return 0;
}
