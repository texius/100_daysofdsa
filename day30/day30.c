#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node* next;
};

int main() {
    int n, i, c, e;
    struct Node *head = NULL, *tail = NULL, *temp;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    for (i = 0; i < n; i++) {
        scanf("%d %d", &c, &e);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = c; // Using 'coeff' logic, but following my standard 'data' naming for consistency where possible, let's stick to 'coeff' for clarity.
        temp->coeff = c;
        temp->exp = e;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }

    temp = head;
    while (temp != NULL) {
        if (temp->exp == 0) {
            printf("%d", temp->coeff);
        } else if (temp->exp == 1) {
            printf("%dx", temp->coeff);
        } else {
            printf("%dx^%d", temp->coeff, temp->exp);
        }
        
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
