#include <iostream>

int main() {
    int n;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (; n > 0; n >>= 1) {
        if (n & 1) {
            ++cnt;
            
            if (cnt > 1) {
                cnt = 0;
                break;
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}