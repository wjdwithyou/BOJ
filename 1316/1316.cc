#include <iostream>

int main(){
    char buf[128];
    int n;
    int cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i){
        int alpha[26] = {0,};
        int prev_idx = -1;
        bool chk = true;
        
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j){
            int idx = buf[j] - 'a';
            
            if (alpha[idx] != 0 && idx != prev_idx){
                chk = false;
                break;
            }
            
            ++alpha[idx];
            prev_idx = idx;
        }
        
        if (chk){
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}