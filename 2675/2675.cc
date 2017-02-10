#include <iostream>

int main(){
    char buf[32];
    int t, r;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        scanf("%d %s", &r, buf);
        
        for (int j = 0; buf[j] != '\0'; ++j){
            for (int k = 0; k < r; ++k){
                printf("%c", buf[j]);
            }
        }
        
        printf("\n");
    }
    
    return 0;
}