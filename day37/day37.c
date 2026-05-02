#include <stdio.h>
#include <string.h>
#define MAX 1000

int pq[MAX];
int size = 0;

void insert(int val) {
    pq[size++] = val;
}

int peek() {
    if (size == 0) return -1;
    int min = pq[0];
    for (int i = 1; i < size; i++) {
        if (pq[i] < min) min = pq[i];
    }
    return min;
}

int deleteMin() {
    if (size == 0) return -1;
    int minIdx = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIdx]) minIdx = i;
    }
    int min = pq[minIdx];
    for (int i = minIdx; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
    return min;
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
        } else if (strcmp(op, "delete") == 0) {
            int res = deleteMin();
            if(res == -1) printf("-1\n");
            else printf("%d\n", res);
        } else if (strcmp(op, "peek") == 0) {
            int res = peek();
            if(res == -1) printf("-1\n");
            else printf("%d\n", res);
        }
    }
    return 0;
}
