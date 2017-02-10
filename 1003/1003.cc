#include <iostream>

int main(){
    int fib[41];
    int t, n;
    
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i < 41; ++i){
        fib[i] = fib[i - 2] + fib[i - 1];
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        scanf("%d", &n);
        printf("%d %d\n", (n)? fib[n - 1] : 1, fib[n]);
    }
    
    return 0;
}