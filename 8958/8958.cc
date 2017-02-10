#include <iostream>

int main(){
    char buf[128];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i){
        int cnt = 1;
        int sum = 0;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j){
            if (buf[j] == 'O'){
                sum += cnt++;
            }
            else{
                cnt = 1;
            }
        }
        
        printf("%d\n", sum);
    }
    
    return 0;
}