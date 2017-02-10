#include <iostream>

int main(){
    char buf[16];
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i){
        int idx;
        char temp;
        char max = '0' - 1;
        
        for (int j = i; buf[j] != '\0'; ++j){
            if (buf[j] > max){
                idx = j;
                max = buf[j];
            }
        }
        
        temp = buf[i];
        buf[i] = buf[idx];
        buf[idx] = temp;
    }
    
    printf("%s", buf);
    return 0;
}