#include <iostream>

int main(){
    char stack[32];
    char buf[64];
    int t;
    int stack_idx;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        stack_idx = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j){
            if (buf[j] == '('){
                stack[stack_idx++] = buf[j];
            }
            else{
                if (--stack_idx < 0){
                    break;
                }
            }
        }
        
        if (stack_idx == 0){
            puts("YES");
        }
        else{
            puts("NO");
        }
    }
    
    return 0;
}