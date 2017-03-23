#include <iostream>

int main() {
    char buf[8];
    int t, n, m, cnt;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        cnt = 0;
        
        scanf("%d %d", &n, &m);
        
        for (int j = n; j <= m; ++j) {
            sprintf(buf, "%d", j);
            
            for (int k = 0; buf[k] != '\0'; ++k) {
                if (buf[k] == '0') {
                    ++cnt;
                }
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}