#include <stdio.h>

int adj[1000][1000] = {0};
int visited[1000] = {0};
int hasCycle = 0;

void dfs(int v, int parent, int n) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) dfs(i, v, n);
            else if (i != parent) hasCycle = 1;
        }
    }
}

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) dfs(i, -1, n);
    }
    if (hasCycle) printf("YES\n");
    else printf("NO\n");
    return 0;
}
