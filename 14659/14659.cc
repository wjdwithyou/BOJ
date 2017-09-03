#include <iostream>

int main() {
    int n, c;
    int cnt = 0, max = 0;
    
    scanf("%d", &n);
    
    for (int i = 0, h = 0; i < n; ++i) {
        scanf("%d", &c);
        
        if (h > c) {
            ++cnt;
        } else {
            if (max < cnt) {
                max = cnt;
            }
            
            h = c;
            cnt = 0;
        }
    }
    
    return !printf("%d", (max > cnt) ? max : cnt);
}