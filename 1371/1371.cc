#include <iostream>

#define NUM_ALPHA 26

char buf[8192];

int main() {
    int alpha[32] = { 0, };
    int max = -1;
    
    while (fgets(buf, 8192, stdin)) {
        for (int i = 0; buf[i] != '\n'; ++i) {
            if (buf[i] == ' ') {
                continue;
            }
            
            ++alpha[buf[i] - 'a'];
        }
    }
    
    for (int i = 0; i < NUM_ALPHA; ++i) {
        if (max < alpha[i]) {
            max = alpha[i];
        }
    }
    for (int i = 0; i < NUM_ALPHA; ++i) {
        if (max == alpha[i]) {
            printf("%c", i + 'a');
        }
    }
    
    return 0;
}