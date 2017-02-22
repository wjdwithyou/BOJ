#include <iostream>
#include <cstring>

int main() {
    int cnt[16];
    char x[16];
    int t, r;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        memset(cnt, 0, sizeof(cnt));
        r = 0;
        
        scanf("%s", x);
        
        for (int j = 0; x[j] != '\0'; ++j) {
            ++cnt[x[j] - '0'];
        }
        
        for (int j = 0; j < 10; ++j) {
            r += (cnt[j]) ? 1 : 0;
        }
        
        printf("%d\n", r);
    }
    
    return 0;
}