#include <iostream>

char map[128][128];

int main(){
    int n;
    int h_cnt = 0;
    int v_cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i){
        int len = 0;
        
        scanf("%s", map[i]);
        
        for (int j = 0; j < n; ++j){
            if (map[i][j] == '.'){
                ++len;
            }
            else{
                if (len >= 2){
                    ++h_cnt;
                    len = 0;
                }
                else if (len == 1){
                    len = 0;
                }
                else;
            }
        }
        
        if (len >= 2){
            ++h_cnt;
        }
    }
    
    for (int j = 0; j < n; ++j){
        int len = 0;
        
        for (int i = 0; i < n; ++i){
            if (map[i][j] == '.'){
                ++len;
            }
            else{
                if (len >= 2){
                    ++v_cnt;
                    len = 0;
                }
                else if (len == 1){
                    len = 0;
                }
                else;
            }
        }
        
        if (len >= 2){
            ++v_cnt;
        }
    }
    
    printf("%d %d", h_cnt, v_cnt);
    return 0;
}