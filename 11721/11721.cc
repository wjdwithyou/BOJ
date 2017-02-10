#include <iostream>

int main(){
    char buf[128];
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i){
        if (i % 10 == 0 && i != 0){
            printf("\n");
        }
        printf("%c", buf[i]);
    }
    
    return 0;
}