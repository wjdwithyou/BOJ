#include <iostream>
#include <cstring>

int main() {
    char name[32], buf[32];
    int n, k, m, j;
    int max = -1, cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        scanf("%d %d", &k, &m);
        
        for (j = 0; k <= m; ++j, m -= (k - 2));
        
        if (max < j) {
            max = j;
            strcpy(name, buf);
        }
        
        cnt += j;
    }
    
    printf("%d\n%s", cnt, name);
    return 0;
}