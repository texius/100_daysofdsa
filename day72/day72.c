#include <stdio.h>
#include <string.h>

int main() {
    char s[1000];
    if (scanf("%s", s) != 1) return 0;
    
    int hash[256] = {0};
    int len = strlen(s);
    char ans = -1;
    
    for (int i = 0; i < len; i++) {
        if (hash[(unsigned char)s[i]] == 1) {
            ans = s[i];
            break;
        }
        hash[(unsigned char)s[i]]++;
    }
    
    if (ans != -1) printf("%c\n", ans);
    else printf("-1\n");
    
    return 0;
}
