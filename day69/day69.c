#include <stdio.h>
#include <limits.h>

int adj[1000][1000] = {0};
int dist[1000];
int visited[1000] = {0};

int main() {
    int n, m, start;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
        dist[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
        adj[v][u] = w; // Assuming undirected for Dijkstra generic case unless specified
    }
    if (scanf("%d", &start) != 1) start = 0;
    
    dist[start] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        int u = -1, minDist = INT_MAX;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && dist[j] < minDist) {
                minDist = dist[j];
                u = j;
            }
        }
        if (u == -1) break;
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("-1 ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
    return 0;
}
