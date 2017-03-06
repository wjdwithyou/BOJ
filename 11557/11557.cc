#include <iostream>
#include <cstring>

int main() {
    char smax[32] = "";
    char s[32];
    int t, n, l, lmax;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        lmax = -1;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%s %d", s, &l);
            
            if (lmax < l) {
                lmax = l;
                strcpy(smax, s);
            }
        }
        
        puts(smax);
    }
    
    return 0;
}