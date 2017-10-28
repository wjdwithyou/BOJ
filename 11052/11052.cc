#include <iostream>

int dp[1024], p[1024];

int main(void) {
    int n, max;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &p[i]);
    }
    
    dp[1] = p[1];
    
    for (int i = 2; i <= n; ++i) {
        max = p[i];
        
        for (int j = i >> 1; j > 0; --j) {
            if (max < dp[j] + dp[i - j]) {
                max = dp[j] + dp[i - j];
            }
        }
        
        dp[i] = max;
    }
    
    return !printf("%d", dp[n]);
}