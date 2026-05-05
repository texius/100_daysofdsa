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

int main() {
    int n;
    int arr[1000];
    if (scanf("%d", &n) != 1) return 0;
    int first = 1;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if(arr[i] != -1) {
            if(!first) printf(" ");
            printf("%d", arr[i]);
            first = 0;
        }
    }
    printf("\n");
    return 0;
}
