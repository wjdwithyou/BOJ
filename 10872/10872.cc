#include <iostream>

#define MAX_NUM 12

int main() {
    int factorial[16];
    int n;
    
    factorial[0] = 1;
    
    for (int i = 1; i <= MAX_NUM; ++i) {
        factorial[i] = factorial[i - 1] * i;
    }
    
    scanf("%d", &n);
    printf("%d", factorial[n]);
    
    return 0;
}