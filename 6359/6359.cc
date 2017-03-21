#include <iostream>
#include <cstring>

int main() {
    int room[128];
    int t, n, cnt;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        memset(room, 0, sizeof(room));
        cnt = 0;
        
        scanf("%d", &n);
        
        for (int j = 1; j <= n; ++j) {
            for (int k = j; k <= n; k += j) {
                room[k] += (room[k]) ? -1 : 1;
            }
        }
        
        for (int j = 1; j <= n; ++j) {
            cnt += (room[j]) ? 1 : 0;
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}