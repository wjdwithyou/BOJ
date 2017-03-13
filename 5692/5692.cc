#include <iostream>
#include <cstring>

int main() {
    int fact[8] = { 1, 1, 2, 6, 24, 120 };
    char buf[8];
    int len, sum;
    
    while (true) {
        scanf("%s", buf);
        len = strlen(buf);
        
        if (buf[0] == '0' && len == 1) {
            break;
        }
        
        sum = 0;
        
        for (int i = 0; i < len; ++i) {
            sum += fact[len - i] * (buf[i] - '0');
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}