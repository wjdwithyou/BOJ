#include <iostream>
#include <cmath>

#define MAX 24

int main() {
    char buf[32];
    int n, s;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        s = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; j < MAX; ++j) {
            if (buf[MAX - j - 1] == '1') {
                s += static_cast<int>(pow(2, j)); 
            }
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}