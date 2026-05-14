#include <stdio.h>
#include <limits.h>

struct Edge {
    int u, v, w;
};

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    struct Edge edges[10000];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }
    
    int dist[1000];
    for (int i = 0; i < n; i++) dist[i] = INT_MAX;
    dist[0] = 0; // Assuming 0 as source
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;
            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    
    int hasNegCycle = 0;
    for (int j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;
        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            hasNegCycle = 1;
            break;
        }
    }
    
    if (hasNegCycle) {
        printf("NEGATIVE CYCLE\n");
    } else {
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) printf("-1 ");
            else printf("%d ", dist[i]);
        }
        printf("\n");
    }
    return 0;
}
