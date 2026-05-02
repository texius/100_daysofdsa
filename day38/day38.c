#include <stdio.h>
#include <string.h>

#define MAX 1000
int deque[MAX];
int f = -1, r = -1;

void push_front(int x) {
    if (f == -1) { f = r = 0; deque[f] = x; }
    else if (f == 0) { f = MAX - 1; deque[f] = x; }
    else { deque[--f] = x; }
}

void push_back(int x) {
    if (f == -1) { f = r = 0; deque[r] = x; }
    else if (r == MAX - 1) { r = 0; deque[r] = x; }
    else { deque[++r] = x; }
}

int pop_front() {
    if (f == -1) return -1;
    int res = deque[f];
    if (f == r) f = r = -1;
    else if (f == MAX - 1) f = 0;
    else f++;
    return res;
}

int pop_back() {
    if (f == -1) return -1;
    int res = deque[r];
    if (f == r) f = r = -1;
    else if (r == 0) r = MAX - 1;
    else r--;
    return res;
}

int front() { return f == -1 ? -1 : deque[f]; }
int back() { return r == -1 ? -1 : deque[r]; }
int size() {
    if (f == -1) return 0;
    if (r >= f) return r - f + 1;
    return MAX - f + r + 1;
}

int main() {
    int n, val;
    char op[20];
    
    if (scanf("%d", &n) != 1) return 0;
    while (n--) {
        scanf("%s", op);
        if (strcmp(op, "push_front") == 0) { scanf("%d", &val); push_front(val); }
        else if (strcmp(op, "push_back") == 0) { scanf("%d", &val); push_back(val); }
        else if (strcmp(op, "pop_front") == 0) { printf("%d\n", pop_front()); }
        else if (strcmp(op, "pop_back") == 0) { printf("%d\n", pop_back()); }
        else if (strcmp(op, "front") == 0) { printf("%d\n", front()); }
        else if (strcmp(op, "back") == 0) { printf("%d\n", back()); }
        else if (strcmp(op, "size") == 0) { printf("%d\n", size()); }
    }
    return 0;
}
