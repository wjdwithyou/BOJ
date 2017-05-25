#include <iostream>

int main() {
    int n, m, a, b;
    int m6 = 1024, m1 = 1024;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        
        m6 = (m6 > a) ? a : m6;
        m1 = (m1 > b) ? b : m1;
    }
    
    return !printf("%d", (m6 > 6 * m1) ? m1 * n : m6 * (n / 6) + ((m6 < m1 * (n % 6)) ? m6 : m1 * (n % 6)));
}