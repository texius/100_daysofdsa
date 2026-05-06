#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int val) {
    if (!root) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (val < root->data) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

void inorder(struct Node* root, int *first) {
    if (root) {
        inorder(root->left, first);
        if (!(*first)) printf(" ");
        printf("%d", root->data);
        *first = 0;
        inorder(root->right, first);
    }
}

int main() {
    int n, val;
    struct Node* root = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    int f = 1;
    inorder(root, &f);
    printf("\n");
    return 0;
}
