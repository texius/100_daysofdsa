#include <stdio.h>

int adj[1000][1000] = {0};
int visited[1000] = {0};
int stack[1000];
int top = -1;

void dfs(int v, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) dfs(i, n);
    }
    stack[++top] = v;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, n);
    }
    while (top >= 0) {
        printf("%d ", stack[top--]);
    }
    printf("\n");
    return 0;
}
