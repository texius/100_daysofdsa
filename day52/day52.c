#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createTree(int arr[], int n, int i) {
    if (i < n && arr[i] != -1) {
        struct Node* root = (struct Node*)malloc(sizeof(struct Node));
        root->data = arr[i];
        root->left = createTree(arr, n, 2 * i + 1);
        root->right = createTree(arr, n, 2 * i + 2);
        return root;
    }
    return NULL;
}

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data == n1 || root->data == n2) return root;
    struct Node* left_lca = lca(root->left, n1, n2);
    struct Node* right_lca = lca(root->right, n1, n2);
    if (left_lca && right_lca) return root;
    return (left_lca != NULL) ? left_lca : right_lca;
}

int main() {
    int n, n1, n2;
    int arr[1000];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    struct Node* root = createTree(arr, n, 0);
    if (scanf("%d %d", &n1, &n2) == 2) {
        struct Node* ans = lca(root, n1, n2);
        if (ans) printf("%d\n", ans->data);
    }
    return 0;
}
