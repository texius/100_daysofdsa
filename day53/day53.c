#include <stdio.h>
#include <stdlib.h>

struct NodeData {
    int data;
    int hd;
    int index;
};

int compare(const void* a, const void* b) {
    struct NodeData* n1 = (struct NodeData*)a;
    struct NodeData* n2 = (struct NodeData*)b;
    if (n1->hd != n2->hd) return n1->hd - n2->hd;
    return n1->index - n2->index;
}

int main() {
    int n;
    int arr[1000];
    int hd[1000] = {0};
    struct NodeData nodes[1000];
    int count = 0;

    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    if (n > 0 && arr[0] != -1) {
        hd[0] = 0;
        nodes[count++] = (struct NodeData){arr[0], 0, 0};
        for (int i = 0; i < n; i++) {
            if (arr[i] != -1) {
                int left = 2 * i + 1;
                int right = 2 * i + 2;
                if (left < n && arr[left] != -1) {
                    hd[left] = hd[i] - 1;
                    nodes[count++] = (struct NodeData){arr[left], hd[left], left};
                }
                if (right < n && arr[right] != -1) {
                    hd[right] = hd[i] + 1;
                    nodes[count++] = (struct NodeData){arr[right], hd[right], right};
                }
            }
        }
    }
    
    qsort(nodes, count, sizeof(struct NodeData), compare);
    
    if (count > 0) {
        int current_hd = nodes[0].hd;
        printf("%d", nodes[0].data);
        for (int i = 1; i < count; i++) {
            if (nodes[i].hd != current_hd) {
                printf("\n%d", nodes[i].data);
                current_hd = nodes[i].hd;
            } else {
                printf(" %d", nodes[i].data);
            }
        }
        printf("\n");
    }
    return 0;
}
