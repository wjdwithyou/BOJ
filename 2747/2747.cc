#include <iostream>

int main(){
    int fib[64];
    int n;
    
    fib[0] = 0;
    fib[1] = 1;
    
    scanf("%d", &n);
    
    for (int i = 2; i <= n; ++i){
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    
    printf("%d", fib[n]);
    return 0;
}