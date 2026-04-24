#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1000

int main() {
    char str[MAX_SIZE];
    int i, n;
    int isPalindrome = 1;

    // Read string
    if (scanf("%s", str) != 1) return 0;

    n = strlen(str);

    // Check if palindrome using two-pointer approach
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            isPalindrome = 0;
            break;
        }
        left++;
        right--;
    }

    // Print result
    if (isPalindrome) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
