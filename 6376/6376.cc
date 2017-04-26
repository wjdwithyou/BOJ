#include <iostream>

double dp[16];
int fact[16];

int main() {
    dp[0] = fact[0] = 1;
    
    puts("n e");
    puts("- -----------");
    puts("0 1");
    
    for (int i = 1; i <= 9; ++i) {
        fact[i] = i * fact[i - 1];
        dp[i] = 1 / static_cast<double>(fact[i]) + dp[i - 1];
        
        printf("%d ", i);
        printf((i < 3) ? "%g\n" : "%.9f\n", dp[i]);
    }
    
    return 0;
}