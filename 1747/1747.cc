#include <iostream>
#include <cstring>

#define M2AX 2000000

int pn[M2AX];

int main() {
    char buf[8];
    int n, chk;
    
    pn[0] = pn[1] = 1;
    
    for (int i = 2; i < M2AX; ++i) {
        if (pn[i]) {
            continue;
        }
        
        for (int j = i << 1; j < M2AX; j += i) {
            ++pn[j];
        }
    }
    
    scanf("%d", &n);
    
    for (int i = n; i < M2AX; ++i) {
        if (pn[i]) {
            continue;
        }
        
        chk = 0;
        
        sprintf(buf, "%d", i);
        
        for (int j = 0, k = strlen(buf) - 1; j < k && !chk; ++j, --k) {
            if (buf[j] != buf[k]) {
                ++chk;
            }
        }
        
        if (!chk) {
            printf("%d", i);
            break;
        }
    }
    
    return 0;
}