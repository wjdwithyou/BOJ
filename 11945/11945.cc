#include <iostream>

int main() {
    char buf[16];
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        
        for (int j = m - 1; j >= 0; --j) {
            printf("%c", buf[j]);
        }
        printf("\n");
    }
    
    return 0;
}