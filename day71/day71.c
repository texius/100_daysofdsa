#include <stdio.h>
#include <string.h>

int table[100];
int m;

void insert(int key) {
    int i = 0;
    while (i < m) {
        int index = (key % m + i * i) % m;
        if (table[index] == -1) {
            table[index] = key;
            return;
        }
        i++;
    }
}

void search(int key) {
    int i = 0;
    while (i < m) {
        int index = (key % m + i * i) % m;
        if (table[index] == key) {
            printf("FOUND\n");
            return;
        }
        if (table[index] == -1) {
            break;
        }
        i++;
    }
    printf("NOT FOUND\n");
}

int main() {
    int n;
    char op[20];
    int key;

    if (scanf("%d", &m) != 1) return 0;
    if (scanf("%d", &n) != 1) return 0;

    for (int i = 0; i < m; i++) table[i] = -1;

    for (int i = 0; i < n; i++) {
        scanf("%s %d", op, &key);
        if (strcmp(op, "INSERT") == 0) {
            insert(key);
        } else if (strcmp(op, "SEARCH") == 0) {
            search(key);
        }
    }
    return 0;
}
