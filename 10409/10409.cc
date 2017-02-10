#include <iostream>

int main() {
    int n, t, w;
    int cnt = 0, chk = 0;
    
    scanf("%d %d", &n, &t);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &w);
        
        if (chk) {
            continue;
        }
        
        t -= w;
        ++cnt;
        
        
        if (t < 0) {
            ++chk;
            --cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}