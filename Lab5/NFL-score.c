#include <stdio.h>

void findScoringCombinations(int score, int plays[], int n) {
    if (score == 0) {
        // Print the combination
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                printf(", ");
            }
            if (plays[i] == 0) {
                printf("0 TD");
            } else if (plays[i] == 1) {
                printf("1 FG");
            } else if (plays[i] == 2) {
                printf("1 Safety");
            } else if (plays[i] == 3) {
                printf("1 TD + 1 FG");
            } else if (plays[i] == 4) {
                printf("1 TD + 2pt");
            }
        }
        printf("\n");
        return;
    }
    
    if (score >= 6) {
        plays[n] = 0;
        findScoringCombinations(score - 6, plays, n + 1);
    }
    if (score >= 3) {
        plays[n] = 1;
        findScoringCombinations(score - 3, plays, n + 1);
    }
    if (score >= 2) {
        plays[n] = 2;
        findScoringCombinations(score - 2, plays, n + 1);
    }
    if (score >= 8) {
        plays[n] = 4;
        findScoringCombinations(score - 8, plays, n + 1);
    }
    if (score >= 7) {
        plays[n] = 3;
        findScoringCombinations(score - 7, plays, n + 1);
    }
}

int main() {
    int score;
    int plays[100];  // Maximum 100 plays to reach a score
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);
        
        if (score <= 1) {
            printf("Enter 0 or 1 to STOP\n");
            break;
        }
        
        printf("Possible combinations of scoring plays:\n");
        findScoringCombinations(score, plays, 0);
    }
    
    return 0;
}
