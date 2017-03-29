#include <iostream>
#include <cstring>

char buf[4096];

int main() {
    char word[64];
    int blen, wlen, offset, chk;
    int cnt = 0;
    
    fgets(buf, 4096, stdin);
    buf[strlen(buf) - 1] = '\0';
    blen = strlen(buf);
    
    fgets(word, 64, stdin);
    word[strlen(word) - 1] = '\0';
    wlen = strlen(word);
    
    for (int i = 0; i <= blen - wlen; i += offset) {
        offset = 1;
        
        if (buf[i] == word[0]) {
            offset = wlen;
            chk = 1;
            
            for (int j = 1; j < wlen; ++j) {
                if (buf[i + j] == word[0] && offset == wlen) {
                    offset = j;
                }
                
                if (buf[i + j] != word[j]) {
                    if (offset == wlen) {
                        offset = ++j;
                    }
                    
                    --chk;
                    break;
                }
            }
            
            if (chk) {
                offset = wlen;
                ++cnt;
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}