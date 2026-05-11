#include <stdio.h>
#include <stdlib.h>

struct Node {
    int dest;
    struct Node* next;
};

struct Node* createNode(int v) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->dest = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    struct Node* adjList[1000] = {NULL};
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        struct Node* newNode = createNode(v);
        newNode->next = adjList[u];
        adjList[u] = newNode;
        
        newNode = createNode(u);
        newNode->next = adjList[v];
        adjList[v] = newNode;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        struct Node* temp = adjList[i];
        while (temp) {
            printf(" %d", temp->dest);
            temp = temp->next;
        }
        printf("\n");
    }
    return 0;
}
