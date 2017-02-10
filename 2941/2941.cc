#include <iostream>

int main(){
    char buf[128];
    int len = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i){
        ++len;
        
        switch (buf[i]){
            case '=':
                if (buf[i - 1] == 'z' && buf[i - 2] == 'd'){
                    len -= 2;
                    break;
                }
            case '-':
                --len;
                break;
            case 'j':
                if (buf[i - 1] == 'l' || buf[i - 1] == 'n'){
                    --len;
                }
                break;
            default:
                break;
        }
    }
    
    printf("%d", len);
    return 0;
}