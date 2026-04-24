#include <stdio.h>

// Recursive function to compute n-th Fibonacci number
int fib(int n) {
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int n;

    // Read n
    if (scanf("%d", &n) != 1) return 0;

    // Compute and print n-th Fibonacci number
    printf("%d\n", fib(n));

    return 0;
}
