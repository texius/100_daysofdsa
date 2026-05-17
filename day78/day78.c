#include <stdio.h>
#include <limits.h>

int adj[1000][1000];

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INT_MAX;
        }
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (w < adj[u][v]) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }
    
    int selected[1000] = {0};
    int min_edge[1000];
    for (int i = 1; i <= n; i++) min_edge[i] = INT_MAX;
    
    min_edge[1] = 0;
    int total_weight = 0;
    
    for (int i = 0; i < n; i++) {
        int u = -1, min_val = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!selected[j] && min_edge[j] < min_val) {
                min_val = min_edge[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        
        selected[u] = 1;
        total_weight += min_val;
        
        for (int v = 1; v <= n; v++) {
            if (adj[u][v] != INT_MAX && !selected[v] && adj[u][v] < min_edge[v]) {
                min_edge[v] = adj[u][v];
            }
        }
    }
    
    printf("%d\n", total_weight);
    return 0;
}
