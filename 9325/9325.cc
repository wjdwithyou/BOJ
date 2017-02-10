#include <iostream>

int main(){
    int t, s, n, sum;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        int on, op;
        
        sum = 0;
        
        scanf("%d", &s);
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j){
            scanf("%d %d", &on, &op);
            
            sum += (on * op);
        }
        
        sum += s;
        
        printf("%d\n", sum);
    }
    
    return 0;
}