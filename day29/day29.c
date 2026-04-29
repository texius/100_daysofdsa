#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val, k;
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
    if (scanf("%d", &k) != 1) return 0;
    k = k % n;
    if (k == 0) {
        temp = head;
        while (temp != NULL) {
            printf("%d", temp->data);
            if (temp->next != NULL) printf(" ");
            temp = temp->next;
        }
        printf("\n");
        return 0;
    }

    tail->next = head;
    int steps = n - k;
    temp = head;
    for (i = 1; i < steps; i++) {
        temp = temp->next;
    }
    head = temp->next;
    temp->next = NULL;

    temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
