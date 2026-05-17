#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    long long dist[100][100];
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val == -1 && i != j) {
                dist[i][j] = INT_MAX;
            } else {
                dist[i][j] = val;
            }
        }
    }
    
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INT_MAX) printf("-1");
            else printf("%lld", dist[i][j]);
            
            if (j < n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
