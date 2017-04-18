#include <iostream>
#include <cstring>

int main() {
    char buf[128], temp[32];
    int alpha[32];
    int n, idx;
    
    scanf("%d", &n);
    while (getchar() != '\n');
    
    for (int i = 0; i < n; ++i) {
        memset(alpha, 0, sizeof(alpha));
        
        fgets(buf, 128, stdin);
        
        for (int j = 0; buf[j] != '\n'; ++j) {
            if (buf[j] >= 'A' && buf[j] <= 'Z') {
                ++alpha[buf[j] - 'A'];
            } else if (buf[j] >= 'a' && buf[j] <= 'z') {
                ++alpha[buf[j] - 'a'];
            } else;
        }
        
        idx = 0;
        
        for (int j = 0; j < 26; ++j) {
            if (!alpha[j]) {
                temp[idx++] = j + 'a';
            }
        }
        
        temp[idx] = '\0';
        
        if (idx) {
            printf("missing %s\n", temp);
        } else {
            puts("pangram");
        }
    }
    
    return 0;
}