#include <iostream>

int main(){
    int n[3];
    
    for (int i = 0; i < 3; ++i){
        scanf("%d", &n[i]);
    }
    
    for (int i = 0; i < 3; ++i){
        int idx = i;
        int min = n[i];
        int temp;
        
        for (int j = i + 1; j < 3; ++j){
            if (n[j] < min){
                idx = j;
                min = n[j];
            }
        }
        
        temp = n[i];
        n[i] = n[idx];
        n[idx] = temp;
    }
    
    printf("%d", n[1]);
    return 0;
}