#include <iostream>

int main() {
    int alpha[32] = { 0, };
    char wheel[32] = { 0, };
    int n, k, s;
    int idx = 0, chk = 0;
    char c;
    
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < k; ++i) {
        scanf("%d %c", &s, &c);
        
        if (chk) {
            continue;
        }
        
        idx = (idx + s) % n;
        
        if (wheel[idx] == 0) {
            if (alpha[c - 'A']++ == 0) {
                wheel[idx] = c;
            }
            else {
                ++chk;
            }
        }
        else if (wheel[idx] == c);
        else {
            ++chk;
        }
    }
    
    if (chk) {
        printf("!");
    }
    else {
        int tdx = idx;
        
        do {
            printf("%c", (wheel[tdx] == 0) ? '?' : wheel[tdx]);
            
            if (--tdx < 0) {
                tdx += n;
            }
        } while (tdx != idx);
    }
    
    return 0;
}