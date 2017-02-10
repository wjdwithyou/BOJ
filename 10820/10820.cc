#include <iostream>

#define BUF_SIZE 128

int main(){
    char buf[BUF_SIZE];
    int lower, upper, num, space;
    
    while (fgets(buf, BUF_SIZE, stdin)){
        lower = upper = num = space = 0;
        
        for (int i = 0; buf[i] != '\0'; ++i){
            if (buf[i] == ' '){
                ++space;
            }
            else if (buf[i] >= '0' && buf[i] <= '9'){
                ++num;
            }
            else if (buf[i] >= 'A' && buf[i] <= 'Z'){
                ++upper;
            }
            else if (buf[i] >= 'a' && buf[i] <= 'z'){
                ++lower;
            }
            else;
        }
        
        printf("%d %d %d %d\n", lower, upper, num, space);
    }
    
    return 0;
}