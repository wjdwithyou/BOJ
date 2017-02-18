#include <iostream>

char buf[16384];

int main() {
    char joi[4] = "JOI";
    char ioi[4] = "IOI";
    int jcnt = 0, icnt = 0, chk = 1;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i + 2] != '\0'; ++i, chk = 1) {
        if (buf[i] == 'J') {
            for (int j = 0; j < 3; ++j) {
                if (buf[i + j] != joi[j]) {
                    --chk;
                    break;
                }
            }
            
            if (chk) {
                ++jcnt;
            }
        }
        else if (buf[i] == 'I') {
            for (int j = 0; j < 3; ++j) {
                if (buf[i + j] != ioi[j]) {
                    --chk;
                    break;
                }
            }
            
            if (chk) {
                ++icnt;
            }
        }
        else;
    }
    
    printf("%d\n%d", jcnt, icnt);
    return 0;
}