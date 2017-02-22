#include <iostream>
#include <cstring>

int main() {
    int arr[512];
    int k, p, m, t, cnt;
    
    scanf("%d", &k);
    
    for (int i = 0; i < k; ++i) {
        memset(arr, 0, sizeof(arr));
        cnt = 0;
        
        scanf("%d %d", &p, &m);
        
        for (int j = 0; j < p; ++j) {
            scanf("%d", &t);
            (arr[t]) ? ++cnt : ++arr[t];
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}