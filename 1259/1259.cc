#include <iostream>
#include <cstring>

int main() {
    char buf[8];
    int chk;
    
    while (true) {
        scanf("%s", buf);
        
        if (buf[0] == '0') {
            break;
        }
        
        chk = 0;
        
        for (int i = 0, j = strlen(buf) - 1; i < j; ++i, --j) {
            if (buf[i] != buf[j]) {
                ++chk;
                break;
            }
        }
        
        puts((chk) ? "no" : "yes");
    }
    
    return 0;
}