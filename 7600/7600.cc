#include <iostream>
#include <cstring>

#define NUM_ALPHA 26

int main() {
    char end[2] = "#";
    char buf[256];
    int alpha[32];
    int cnt;
    
    while (true) {
        memset(alpha, 0, sizeof(alpha));
        cnt = 0;
        
        fgets(buf, 256, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        if (!strcmp(buf, end)) {
            break;
        }
        
        for (int i = 0; buf[i] != '\0'; ++i) {
            if (buf[i] >= 'A' && buf[i] <= 'Z') {
                alpha[buf[i] - 'A'] = 1;
            } else if (buf[i] >= 'a' && buf[i] <= 'z') {
                alpha[buf[i] - 'a'] = 1;
            } else;
        }
        
        for (int i = 0; i < NUM_ALPHA; ++i) {
            cnt += alpha[i];
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}