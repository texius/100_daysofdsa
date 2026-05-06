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

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2) return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return lca(root->right, n1, n2);
    return root;
}

int main() {
    int n, val, n1, n2;
    struct Node* root = NULL;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }
    if (scanf("%d %d", &n1, &n2) == 2) {
        struct Node* ans = lca(root, n1, n2);
        if (ans) printf("%d\n", ans->data);
    }
    return 0;
}
