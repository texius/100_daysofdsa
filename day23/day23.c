#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createList(int n) {
    struct Node *head = NULL, *tail = NULL, *temp;
    int i, val;
    for (i = 0; i < n; i++) {
        if (scanf("%d", &val) != 1) break;
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
    return head;
}

int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    struct Node* l1 = createList(n);
    if (scanf("%d", &m) != 1) return 0;
    struct Node* l2 = createList(m);

    struct Node *head = NULL, *tail = NULL, *temp;
    while (l1 != NULL || l2 != NULL) {
        int val;
        if (l1 != NULL && (l2 == NULL || l1->data <= l2->data)) {
            val = l1->data;
            l1 = l1->next;
        } else {
            val = l2->data;
            l2 = l2->next;
        }
        
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

    temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
