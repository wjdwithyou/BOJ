#include <iostream>
#include <cstring>

int chk[131072];

int main() {
    int step, mod, prev, seed, cnt;
    
    while (fscanf(stdin, "%d %d", &step, &mod) != EOF) {
        memset(chk, 0, sizeof(chk));
        
        prev = cnt = 0;
        
        ++chk[prev];
        ++cnt;
        
        while (true) {
            seed = (prev + step) % mod;
            
            if (chk[seed]) {
                break;
            } else {
                ++chk[seed];
                ++cnt;
            }
            
            prev = seed;
        }
        
        printf("%10d%10d %s Choice\n\n", step, mod, (mod == cnt) ? "Good" : "Bad");
    }
    
    return 0;
}