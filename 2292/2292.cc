#include <iostream>

int main(){
    int n;
    int e = 1;
    
    scanf("%d", &n);
    
    for (int i = 1; ; ++i){
        if (n <= e){
            printf("%d", i);
            break;
        }
        
        e += (6 * i);
    }
    
    return 0;
}