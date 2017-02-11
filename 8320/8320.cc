#include <iostream>

int main() {
    int n, t;
    int s = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= 100; ++i) {
        t = (n / i - (i - 1));
        
        if (t > 0) {
            s += t;
        }
        else {
            break;
        }
    }
    
    printf("%d", s);
    return 0;
}