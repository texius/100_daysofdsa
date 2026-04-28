#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, i, val, key, count = 0;
    struct Node *head = NULL, *tail = NULL, *temp;

    if (scanf("%d", &n) != 1) return 0;
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
    scanf("%d", &key);

    temp = head;
    while (temp != NULL) {
        if (temp->data == key) count++;
        temp = temp->next;
    }

    printf("%d\n", count);

    return 0;
}
