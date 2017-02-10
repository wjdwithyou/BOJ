#include <iostream>

int main(){
    char buf[128];
    
    scanf("%s", buf);
    
    for (char c = 'a'; c <= 'z'; ++c){
        int idx = -1;
        
        for (int i = 0; buf[i] != '\0'; ++i){
            if (buf[i] == c){
                idx = i;
                break;
            }
        }
        
        printf("%d ", idx);
    }
    
    return 0;
}