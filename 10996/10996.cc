#include <iostream>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= 2 * n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf(((i & 1) != (j & 1))? "*" : " ");
        }
        puts("");
    }
    
    return 0;
}