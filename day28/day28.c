#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val;
    struct Node *head = NULL, *tail = NULL, *temp;

    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    for (i = 0; i < n; i++) {
        scanf("%d", &val);
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = NULL;
        if (head == NULL) {
            head = temp;
            tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
    }
    tail->next = head;

    temp = head;
    for (i = 0; i < n; i++) {
        printf("%d", temp->data);
        if (i < n - 1) printf(" ");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
