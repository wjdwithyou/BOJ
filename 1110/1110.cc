#include <iostream>

int main(){
    int n, a, b, c, d;
    int cnt = 0;
    
    scanf("%d", &n);
    
    a = n;
    
    while (true){
        b = a / 10;
        c = a % 10;
        d = b + c;
    
        a = (10 * c) + (d % 10);
        
        ++cnt;
        
        if (a == n){
            break;
        }
    }
    
    printf("%d", cnt);
    return 0;
}