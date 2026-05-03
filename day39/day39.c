#include <stdio.h>
#include <string.h>

#define MAX 1000
int heap[MAX];
int size = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void insert(int val) {
    heap[size] = val;
    int i = size;
    size++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void minHeapify(int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int smallest = i;
    if (l < size && heap[l] < heap[smallest]) smallest = l;
    if (r < size && heap[r] < heap[smallest]) smallest = r;
    if (smallest != i) {
        swap(&heap[i], &heap[smallest]);
        minHeapify(smallest);
    }
}

int extractMin() {
    if (size <= 0) return -1;
    if (size == 1) { size--; return heap[0]; }
    int root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    minHeapify(0);
    return root;
}

int peek() {
    if (size <= 0) return -1;
    return heap[0];
}

int main() {
    int n, val;
    char op[20];
    
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "insert") == 0) {
            scanf("%d", &val);
            insert(val);
        } else if (strcmp(op, "extractMin") == 0) {
            int res = extractMin();
            printf("%d\n", res);
        } else if (strcmp(op, "peek") == 0) {
            int res = peek();
            printf("%d\n", res);
        }
    }
    return 0;
}
