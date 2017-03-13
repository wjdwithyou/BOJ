#include <iostream>
#include <cstring>

int main() {
    char a[64], b[64];
    int la, lb, cnt;
    int min = 64;
    
    scanf("%s %s", a, b);
    
    la = strlen(a);
    lb = strlen(b);
    
    for (int i = lb - la; i >= 0; --i) {
        cnt = 0;
        
        for (int j = 0; j < la; ++j) {
            if (a[j] != b[i + j]) {
                ++cnt;
            }
        }
        
        if (min > cnt) {
            min = cnt;
        }
    }
    
    printf("%d", min);
    return 0;
}