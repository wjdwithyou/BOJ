#include <iostream>
#include <cstring>

#define NUM_ALPHA 26

int main() {
    char buf[128];
    int alpha[32];
    int n, chk;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        memset(alpha, 0, sizeof(alpha));
        chk = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            ++alpha[buf[j] - ((buf[j] < 'a') ? 'A' : 'a')];
        }
        
        printf("%s", buf);
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            --alpha[buf[j] - ((buf[j] < 'a') ? 'A' : 'a')];
        }
        
        for (int j = 0; j < NUM_ALPHA; ++j) {
            if (alpha[j]) {
                ++chk;
                break;
            }
        }
        
        printf(" & %s are%s anagrams.\n", buf, (chk) ? " NOT" : "");
    }
    
    return 0;
}