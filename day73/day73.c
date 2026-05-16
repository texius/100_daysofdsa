#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    if (scanf("%s", s) != 1) return 0;
    
    int hash[256] = {0};
    int len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        hash[(unsigned char)s[i]]++;
    }
    
    char ans = '$';
    for (int i = 0; i < len; i++) {
        if (hash[(unsigned char)s[i]] == 1) {
            ans = s[i];
            break;
        }
    }
    
    printf("%c\n", ans);
    return 0;
}
