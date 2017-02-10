#include <iostream>

int main() {
    int n, q;
    int seq = 0, sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &q);
        
        if (q) {
            sum += ++seq;
        }
        else {
            seq = 0;
        }
    }
    
    printf("%d", sum);
    return 0;
}