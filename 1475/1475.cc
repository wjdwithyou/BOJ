#include <iostream>

int main(){
    int cnt[10] = {0,};
    char n[8];
    int max = 0;
    bool chk = false;
    
    scanf("%s", n);
    
    for (int i = 0; i < n[i] != '\0'; ++i){
        int idx = n[i] - '0';
        
        if (idx == 6 || idx == 9){
            if (!chk){
                chk = true;
            }
            else{
                ++cnt[9];
                chk = false;
            }
        }
        else{
            ++cnt[idx];
        }
    }
    
    if (chk){
        ++cnt[9];
    }
    
    for (int i = 0; i < 10; ++i){
        if (cnt[i] > max){
            max = cnt[i];
        }
    }
    
    printf("%d", max);
    return 0;
}