#include <iostream>

#define NUM_ALPHA 26

int main() {
    int alpha[32] = { 0, };
    char buf[64];
    int oidx;
    int cnt = 0, idx = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        ++alpha[buf[i] - 'A'];
    }
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        if (alpha[i] & 1) {
            oidx = i;
            ++cnt;
        }
        
        alpha[i] >>= 1;
    }
    
    if (cnt >= 2) {
        printf("I'm Sorry Hansoo");
    } else {
        for (int i = 0; i < NUM_ALPHA; ++i) {
            for (int j = alpha[i]; j > 0; --j) {
                buf[idx++] = i + 'A';
            }
        }
        
        for (int i = 0; i < idx; ++i) {
            printf("%c", buf[i]);
        }
        
        if (cnt) {
            printf("%c", oidx + 'A');
        }
        
        for (int i = idx - 1; i >= 0; --i) {
            printf("%c", buf[i]);
        }
    }
    
    return 0;
}