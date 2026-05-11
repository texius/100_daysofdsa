#include <stdio.h>
#include <stdlib.h>

int adj[1000][1000] = {0};
int visited[1000] = {0};

void dfs(int v, int n) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, n);
        }
    }
}

int main() {
    int n, m, start;
    if (scanf("%d", &n) != 1) return 0;
    if (scanf("%d", &m) != 1) return 0;
    
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        adj[v][u] = 1;
    }
    if (scanf("%d", &start) == 1) {
        dfs(start, n);
        printf("\n");
    }
    return 0;
}
