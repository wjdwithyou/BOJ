#include <iostream>

int main() {
    int n, t;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = (n >> 1); i > 0; --i) {
        for (int j = i + 2;; ++j) {
            t = n - i - j;
            
            if (t < 1) {
                break;
            }
            
            cnt += !(t & 1);
        }
    }
    
    return !printf("%d", cnt);
}