#include <iostream>
#include <cstring>

#define MAX_LEN 52

int main() {
    int o_alpha[32] = { 0, };
    int i_alpha[32];
    char buf[64];
    int cnt = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; i < MAX_LEN; ++i) {
        if (o_alpha[buf[i] - 'A']) {
            continue;
        }
        
        memset(i_alpha, 0, sizeof(i_alpha));
        
        for (int j = (i + 1) % MAX_LEN; !i_alpha[buf[i] - 'A']; j = (j + 1) % MAX_LEN) {
            ++i_alpha[buf[j] - 'A'];
        }
        
        for (int j = 0; j < (MAX_LEN >> 1); ++j) {
            if (i_alpha[j] == 1 && j != buf[i] - 'A') {
                ++cnt;
            }
        }
        
        ++o_alpha[buf[i] - 'A'];
    }
    
    return !printf("%d", cnt >> 1);
}