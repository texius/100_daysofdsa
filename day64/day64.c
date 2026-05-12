#include <stdio.h>

int adj[1000][1000] = {0};
int visited[1000] = {0};
int queue[1000];

int main() {
    int n, m, start;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    if (scanf("%d", &start) != 1) return 0;
    
    int front = 0, rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    
    while (front < rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        for (int i = 0; i < n; i++) {
            if (adj[curr][i] && !visited[i]) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }
    printf("\n");
    return 0;
}
