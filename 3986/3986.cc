#include <iostream>

char buf[131072], stack[131072];

int main() {
    int n, idx;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        idx = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            if (!idx || stack[idx - 1] != buf[j]) {
                stack[idx++] = buf[j];
            } else {
                --idx;
            }
        }
        
        if (!idx) {
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}