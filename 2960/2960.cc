#include <iostream>

int pn[1024];

int main() {
    int n, k;
    int cnt = 0;
    
    scanf("%d %d", &n, &k);
    
    for (int i = 2; i <= n && cnt < k; ++i) {
        if (pn[i]) {
            continue;
        }
        
        for (int j = i; j <= n && cnt < k; j += i) {
            if (pn[j]) {
                continue;
            }
            
            ++pn[j];
            
            if (++cnt == k) {
                printf("%d", j);
            }
        }
    }
    
    return 0;
}