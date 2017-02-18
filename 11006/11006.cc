#include <iostream>

int main() {
    int t, n, m;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &n, &m);
        printf("%d %d\n", 2 * m - n, n - m);
    }
    
    return 0;
}