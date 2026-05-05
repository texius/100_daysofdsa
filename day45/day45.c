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

int height(struct Node* root) {
    if (!root) return 0;
    int l = height(root->left);
    int r = height(root->right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n;
    int arr[1000];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = createTree(arr, n, 0);
    printf("%d\n", height(root));
    return 0;
}
