#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    int i, n;

    // Read string
    if (scanf("%s", str) != 1) return 0;

    n = strlen(str);

    // Print string in reverse order
    for (i = n - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}
