#include <iostream>

int main() {
    char a[128], b[128];
    int t, cnt;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        cnt = 0;
        
        scanf("%s %s", a, b);
        
        for (int j = 0; a[j] != '\0'; ++j) {
            cnt += (a[j] != b[j]);
        }
        
        printf("Hamming distance is %d.\n", cnt);
    }
    
    return 0;
}