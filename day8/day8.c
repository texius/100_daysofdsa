#include <stdio.h>

// Recursive function to compute a^b
int power(int a, int b) {
    // Base case: any number to power 0 is 1
    if (b == 0) {
        return 1;
    }
    // Recursive case: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    int a, b;

    // Read a and b
    if (scanf("%d %d", &a, &b) != 2) return 0;

    // Compute and print a^b
    printf("%d\n", power(a, b));

    return 0;
}
