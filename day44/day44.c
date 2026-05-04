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

void inorder(struct Node* root, int *first) {
    if (root) {
        inorder(root->left, first);
        if (!(*first)) printf(" ");
        printf("%d", root->data);
        *first = 0;
        inorder(root->right, first);
    }
}

void preorder(struct Node* root, int *first) {
    if (root) {
        if (!(*first)) printf(" ");
        printf("%d", root->data);
        *first = 0;
        preorder(root->left, first);
        preorder(root->right, first);
    }
}

void postorder(struct Node* root, int *first) {
    if (root) {
        postorder(root->left, first);
        postorder(root->right, first);
        if (!(*first)) printf(" ");
        printf("%d", root->data);
        *first = 0;
    }
}

int main() {
    int n;
    int arr[1000];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    struct Node* root = createTree(arr, n, 0);
    
    int f1 = 1; inorder(root, &f1); printf("\n");
    int f2 = 1; preorder(root, &f2); printf("\n");
    int f3 = 1; postorder(root, &f3); printf("\n");
    
    return 0;
}
