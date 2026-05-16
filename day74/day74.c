#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Vote {
    char name[100];
    int count;
};

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    
    struct Vote votes[1000];
    int unique_count = 0;
    
    for (int i = 0; i < n; i++) {
        char temp[100];
        scanf("%s", temp);
        
        int found = 0;
        for (int j = 0; j < unique_count; j++) {
            if (strcmp(votes[j].name, temp) == 0) {
                votes[j].count++;
                found = 1;
                break;
            }
        }
        if (!found) {
            strcpy(votes[unique_count].name, temp);
            votes[unique_count].count = 1;
            unique_count++;
        }
    }
    
    int max_votes = 0;
    char winner[100] = "";
    
    for (int i = 0; i < unique_count; i++) {
        if (votes[i].count > max_votes) {
            max_votes = votes[i].count;
            strcpy(winner, votes[i].name);
        } else if (votes[i].count == max_votes) {
            if (strcmp(votes[i].name, winner) < 0) {
                strcpy(winner, votes[i].name);
            }
        }
    }
    
    printf("%s %d\n", winner, max_votes);
    return 0;
}
