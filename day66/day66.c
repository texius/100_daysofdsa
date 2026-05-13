#include <stdio.h>

int adj[1000][1000] = {0};
int visited[1000] = {0};
int recStack[1000] = {0};
int hasCycle = 0;

void dfs(int v, int n) {
    visited[v] = 1;
    recStack[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) dfs(i, n);
            else if (recStack[i]) hasCycle = 1;
        }
    }
    recStack[v] = 0;
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1; // Directed
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, n);
    }
    if (hasCycle) printf("YES\n");
    else printf("NO\n");
    return 0;
}
