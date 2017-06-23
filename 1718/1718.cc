#include <iostream>
#include <cstring>

#define NUM_ALPHA 26

char buf[32768], key[32768];

int main() {
    int len;
    int chk = 1;
    
    fgets(buf, 32768, stdin);
    buf[strlen(buf) - 1] = '\0';
    
    scanf("%s", key);
    len = strlen(key);
    
    for (int i = 0; chk; i += len) {
        for (int j = 0; j < len; ++j) {
            if (buf[i + j] == '\0') {
                --chk;
                break;
            }
            
            printf("%c", (buf[i + j] == ' ') ? ' ': ((buf[i + j] + (NUM_ALPHA - key[j] - 1)) % NUM_ALPHA) + 'a');
        }
    }
    
    return 0;
}