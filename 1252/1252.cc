#include <iostream>
#include <cstring>

int main() {
    char buf[2][128];
    char r[128];
    int len[2];
    int d, s;
    int c = 0;
    
    for (int i = 0; i < 2; ++i) {
        scanf("%s", buf[i]);
        len[i] = strlen(buf[i]);
        
        for (int j = 0; j < len[i]; ++j) {
            if (buf[i][j] == '1' || j == len[i] - 1) {
                if (j) {
                    len[i] -= j;
                
                    for (int k = 0; k < len[i]; ++k) {
                        buf[i][k] = buf[i][k + j];
                    }
                }
                
                break;
            }
        }
    }
    
    if (len[0] < len[1]) {
        char t[128];
        int lt;
        
        strcpy(t, buf[0]);
        strcpy(buf[0], buf[1]);
        strcpy(buf[1], t);
        
        lt = len[0];
        len[0] = len[1];
        len[1] = lt;
    }
    
    d = len[0] - len[1];
    
    if (d) {
        for (int i = len[1] - 1; i >= 0; --i) {
            buf[1][i + d] = buf[1][i];
        }
        for (int i = 0; i < d; ++i) {
            buf[1][i] = '0';
        }
    }
    
    r[len[0]] = '\0';
    
    for (int i = len[0] - 1; i >= 0; --i) {
        s = (buf[0][i] & 1) + (buf[1][i] & 1) + c;
        c = ((s & 0b10) != 0);
        r[i] = (s & 0b01) + '0';
    }
    
    if (c) {
        printf("1");
    }
    
    return !printf("%s", r);
}