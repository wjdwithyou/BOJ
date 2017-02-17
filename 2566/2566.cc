#include <iostream>

int main() {
    int n, ii, jj;
    int max = 0;
    
    for (int i = 1; i <= 9; ++i) {
        for (int j = 1; j <= 9; ++j) {
            scanf("%d", &n);
            
            if (max < n) {
                ii = i;
                jj = j;
                max = n;
            }
        }
    }
    
    printf("%d\n%d %d", max, ii, jj);
    return 0;
}