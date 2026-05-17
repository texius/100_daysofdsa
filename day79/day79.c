#include <stdio.h>
#include <limits.h>

int adj[1000][1000];
int dist[1000];
int visited[1000] = {0};

int main() {
    int n, m, start;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            adj[i][j] = INT_MAX;
        }
        dist[i] = INT_MAX;
    }
    
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        if (w < adj[u][v]) {
            adj[u][v] = w;
            adj[v][u] = w;
        }
    }
    
    if (scanf("%d", &start) != 1) return 0;
    dist[start] = 0;
    
    for (int i = 0; i < n; i++) {
        int u = -1, min_val = INT_MAX;
        for (int j = 1; j <= n; j++) {
            if (!visited[j] && dist[j] < min_val) {
                min_val = dist[j];
                u = j;
            }
        }
        
        if (u == -1) break;
        visited[u] = 1;
        
        for (int v = 1; v <= n; v++) {
            if (!visited[v] && adj[u][v] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    
    for (int i = 1; i <= n; i++) {
        if (dist[i] == INT_MAX) printf("-1 ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
    return 0;
}
