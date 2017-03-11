#include <iostream>

int main() {
    int t, n, m;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &n, &m);
        printf("%d\n", m * (n - m) + 1);
    }
    
    return 0;
}