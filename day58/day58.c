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

struct Node* buildTree(int in[], int pre[], int inSt, int inEnd, int *preIndex) {
    if (inSt > inEnd) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = pre[(*preIndex)++];
    node->left = node->right = NULL;
    
    if (inSt == inEnd) return node;
    
    int inIndex = search(in, inSt, inEnd, node->data);
    node->left = buildTree(in, pre, inSt, inIndex - 1, preIndex);
    node->right = buildTree(in, pre, inIndex + 1, inEnd, preIndex);
    return node;
}

void postorder(struct Node* node, int *first) {
    if (node == NULL) return;
    postorder(node->left, first);
    postorder(node->right, first);
    if (!(*first)) printf(" ");
    printf("%d", node->data);
    *first = 0;
}

int main() {
    int n;
    int pre[1000], in[1000];
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) scanf("%d", &pre[i]);
    for (int i = 0; i < n; i++) scanf("%d", &in[i]);
    
    int preIndex = 0;
    struct Node* root = buildTree(in, pre, 0, n - 1, &preIndex);
    int first = 1;
    postorder(root, &first);
    printf("\n");
    return 0;
}
