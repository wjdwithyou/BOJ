#include <iostream>

#define NUM_SCORE 5

int main() {
    int score[8];
    int t, idx, temp, sum;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        sum = 0;
        
        for (int j = 0; j < NUM_SCORE; ++j) {
            scanf("%d", &score[j]);
        }
        
        for (int a = 0; a < NUM_SCORE; ++a) {
            idx = a;
            
            for (int b = a + 1; b < NUM_SCORE; ++b) {
                if (score[idx] > score[b]) {
                    idx = b;
                }
            }
            
            temp = score[a];
            score[a] = score[idx];
            score[idx] = temp;
        }
        
        if (score[3] - score[1] >= 4) {
            puts("KIN");
        }
        else {
            for (int i = 1; i <= 3; ++i) {
                sum += score[i];
            }
            
            printf("%d\n", sum);
        }
    }
    
    return 0;
}