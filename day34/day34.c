#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;

void push(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = top;
    top = temp;
}

int pop() {
    if (!top) return 0;
    int val = top->data;
    struct Node* temp = top;
    top = top->next;
    free(temp);
    return val;
}

int main() {
    char exp[1000];
    int i = 0;

    if (!fgets(exp, sizeof(exp), stdin)) return 0;

    while (exp[i]) {
        if (exp[i] == ' ' || exp[i] == '\n') {
            i++;
            continue;
        }
        if (isdigit(exp[i]) || (exp[i] == '-' && isdigit(exp[i + 1]))) {
            int sign = 1;
            if (exp[i] == '-') {
                sign = -1;
                i++;
            }
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num * sign);
            i--; 
        } else {
            int val1 = pop();
            int val2 = pop();
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
        i++;
    }
    printf("%d\n", pop());
    return 0;
}
