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

    struct Node *p1 = l1, *p2 = l2;
    int found = 0;

    // Based on the problem description, we find the first common data value 
    // as the intersection point.
    while (p1 != NULL) {
        p2 = l2;
        while (p2 != NULL) {
            if (p1->data == p2->data) {
                printf("%d\n", p1->data);
                found = 1;
                break;
            }
            p2 = p2->next;
        }
        if (found) break;
        p1 = p1->next;
    }

    if (!found) printf("No Intersection\n");

    return 0;
}
