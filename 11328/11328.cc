#include <iostream>
#include <cstring>

int main() {
    char buf[1024];
    int alpha[32];
    int n, chk;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        memset(alpha, 0, sizeof(alpha));
        chk = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            ++alpha[buf[j] - 'a'];
        }
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            --alpha[buf[j] - 'a'];
        }
        
        for (int j = 'z' - 'a'; j >= 0; --j) {
            if (alpha[j]) {
                ++chk;
                break;
            }
        }
        
        puts((chk) ? "Impossible" : "Possible");
    }
    
    return 0;
}