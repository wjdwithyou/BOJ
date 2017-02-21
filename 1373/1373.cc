#include <iostream>
#include <cstring>
#include <cmath>

char buf[1048576];

int main() {
    int len, mod;
    int sum = 0;
    
    scanf("%s", buf);
    
    len = strlen(buf);
    mod = len % 3;
    
    if (mod) {
        if (mod == 1) {
            sum += (buf[0] - '0') ? 1 : 0;
        }
        else {
            sum += (buf[0] - '0') ? 2 : 0;
            sum += (buf[1] - '0') ? 1 : 0;
        }
        
        printf("%d", sum);
    }
    
    for (int i = mod; i < len; i += 3) {
        sum = 0;
        
        for (int j = 0; j < 3; ++j) {
            sum += (buf[i + j] - '0') ? static_cast<int>(pow(2, 2 - j)) : 0;
        }
        
        printf("%d", sum);
    }
    
    return 0;
}