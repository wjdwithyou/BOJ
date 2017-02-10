#include <iostream>
#include <cstring>

int main(){
    char a[64];
    char b[64];
    int len;
    
    scanf("%s %s", a, b);
    
    if (strlen(a) != strlen(b)){
        len = (strlen(a) > strlen(b))? strlen(a): strlen(b);
        
        if (strlen(a) > strlen(b)){
            len = strlen(a);
            
            for (int i = len - 1; i >= 0; --i){
                printf("%c", a[i]);
            }
        }
        else{
            len = strlen(b);
            
            for (int i = len - 1; i >= 0; --i){
                printf("%c", b[i]);
            }
        }
    }
    else{
        len = strlen(a);
        
        for (int i = len - 1; i >= 0; --i){
            if (a[i] > b[i]){
                for (int i = len - 1; i >= 0; --i){
                    printf("%c", a[i]);
                }
                
                return 0;
            }
            else if (a[i] < b[i]){
                for (int i = len - 1; i >= 0; --i){
                    printf("%c", b[i]);
                }
                
                return 0;
            }
            else;
        }
    }
    
    return 0;
}