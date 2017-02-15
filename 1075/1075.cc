#include <iostream>

int main() {
    int n, f;
    
    scanf("%d", &n);
    scanf("%d", &f);
    
    n = (n / 100) * 100;
    
    while (true) {
        if (n % f == 0) {
            break;
        }
        
        ++n;
    }
    
    n %= 100;
    
    if (n < 10) {
        printf("0");
    }
    
    printf("%d", n);
    return 0;
}