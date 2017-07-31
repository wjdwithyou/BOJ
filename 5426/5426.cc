#include <iostream>
#include <cstring>
#include <cmath>

char buf[16384];

int main() {
    int t, len, n;
    
    scanf("%d", &t);
    
    for (int k = 0; k < t; ++k) {
        scanf("%s", buf);
        
        len = strlen(buf);
        n = static_cast<int>(sqrt(len));
        
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < len; j += n) {
                printf("%c", buf[j]);
            }
        }
        
        puts("");
    }
    
    return 0;
}