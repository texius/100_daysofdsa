#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node *front = NULL, *rear = NULL;

void enqueue(int val) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;
    temp->next = NULL;
    if (rear == NULL) { front = rear = temp; return; }
    rear->next = temp;
    rear = temp;
}

int dequeue() {
    if (front == NULL) return -1;
    struct Node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    int data = temp->data;
    free(temp);
    return data;
}

int main() {
    int n, val;
    char op[20];
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "enqueue") == 0) {
            scanf("%d", &val);
            enqueue(val);
        } else if (strcmp(op, "dequeue") == 0) {
            printf("%d\n", dequeue());
        }
    }
    return 0;
}
