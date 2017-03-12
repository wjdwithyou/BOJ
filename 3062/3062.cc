#include <iostream>
#include <cstring>

int main() {
    char buf[8];
    int t, len, n, chk;
    char temp;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        chk = 0;
        
        scanf("%s", buf);
        len = strlen(buf);
        
        n = atoi(buf);
        
        for (int j = 0, k = len - 1; j < k; ++j, --k) {
            temp = buf[j];
            buf[j] = buf[k];
            buf[k] = temp;
        }
        
        n += atoi(buf);
        
        sprintf(buf, "%d", n);
        len = strlen(buf);
        
        for (int j = 0, k = len - 1; j < k; ++j, --k) {
            if (buf[j] != buf[k]) {
                ++chk;
                break;
            }
        }
        
        puts((chk) ? "NO" : "YES");
    }
    
    return 0;
}