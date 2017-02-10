#include <iostream>

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 2; n != 1; ++i) {
        while (n % i == 0 && n != 1) {
            printf("%d\n", i);
            n /= i;
        }
    }
    
    return 0;
}