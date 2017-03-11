#include <iostream>
#include <cstring>

#define NUM_ALPHA 26

int main() {
    char buf[1024];
    int alpha[32];
    int t, s;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        memset(alpha, 0, sizeof(alpha));
        s = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            ++alpha[buf[j] - 'A'];
        }
        
        for (int j = 0; j < NUM_ALPHA; ++j) {
            if (!alpha[j]) {
                s += j + 'A';
            }
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}