#include <iostream>
#include <cstring>

int main() {
    char buf[256];
    int alpha[32];
    int cnt;
    
    while (true) {
        memset(alpha, 0, sizeof(alpha));
        cnt = 0;
        
        fgets(buf, 256, stdin);
        
        if (buf[0] == '*') {
            break;
        }
        
        for (int i = 0; cnt < 26 && buf[i] != '\n'; ++i) {
            if (buf[i] == ' ' || alpha[buf[i] - 'a']) {
                continue;
            }
            
            ++alpha[buf[i] - 'a'];
            ++cnt;
        }
        
        puts((cnt == 26) ? "Y" : "N");
    }
    
    return 0;
}