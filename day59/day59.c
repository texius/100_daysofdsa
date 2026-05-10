#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) return i;
    }
    return -1;
}

struct Node* buildTree(int in[], int post[], int inSt, int inEnd, int *postIndex) {
    if (inSt > inEnd) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = post[(*postIndex)--];
    node->left = node->right = NULL;
    
    if (inSt == inEnd) return node;
    
    int inIndex = search(in, inSt, inEnd, node->data);
    node->right = buildTree(in, post, inIndex + 1, inEnd, postIndex);
    node->left = buildTree(in, post, inSt, inIndex - 1, postIndex);
    return node;
}

void preorder(struct Node* node, int *first) {
    if (node == NULL) return;
    if (!(*first)) printf(" ");
    printf("%d", node->data);
    *first = 0;
    preorder(node->left, first);
    preorder(node->right, first);
}

int main() {
    int n;
    int in[1000], post[1000];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    for (int i = 0; i < n; i++) scanf("%d", &post[i]);
    
    int postIndex = n - 1;
    struct Node* root = buildTree(in, post, 0, n - 1, &postIndex);
    int first = 1;
    preorder(root, &first);
    printf("\n");
    return 0;
}
