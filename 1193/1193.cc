#include <iostream>

int main(){
    int x;
    int k = 0;
    int a, b;
    
    scanf("%d", &x);
    
    for (int i = 1; ; ++i){
        k += i;
        
        if (x <= k){
            if (i % 2 == 0){
                a = i - (k - x);
                b = 1 + (k - x);
            }
            else{
                a = 1 + (k - x);
                b = i - (k - x);
            }
            
            break;
        }
    }
    
    printf("%d/%d", a, b);
    return 0;
}