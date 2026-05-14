#include <stdio.h>

int adj[1000][1000] = {0};
int inDegree[1000] = {0};
int queue[1000];
int front = 0, rear = 0;

int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
        inDegree[v]++;
    }
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) queue[rear++] = i;
    }
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int v = 0; v < n; v++) {
            if (adj[u][v]) {
                inDegree[v]--;
                if (inDegree[v] == 0) queue[rear++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}
