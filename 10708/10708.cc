#include <iostream>

int main() {
    int score[128] = { 0 };
    int target[128];
    int n, m, t, wc;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= m; ++i) {
        scanf("%d", &target[i]);
    }
    
    for (int i = 1; i <= m; ++i) {
        wc = 0;
        
        for (int j = 1; j <= n; ++j) {
            scanf("%d", &t);
            
            (target[i] == t) ? ++score[j] : ++wc;
        }
        
        score[target[i]] += wc;
    }
    
    for (int i = 1; i <= n; ++i) {
        printf("%d\n", score[i]);
    }
    
    return 0;
}