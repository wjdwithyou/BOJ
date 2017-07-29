#include <iostream>

int main() {
    int n, t;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &t);
        
        if (t != i) {
            ++cnt;
        }
    }
    
    return !printf("%d", cnt);
}