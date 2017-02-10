#include <iostream>

int main(){
    int apt[16][16];
    int t;
    
    for (int i = 1; i <= 14; ++i){
        apt[i][1] = 1;
    }
    
    for (int j = 1; j <= 14; ++j){
        apt[0][j] = j;
    }
    
    for (int i = 1; i <= 14; ++i){
        for (int j = 2; j <= 14; ++j){
            apt[i][j] = apt[i - 1][j] + apt[i][j - 1];
        }
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        int k, n;
        
        scanf("%d", &k);
        scanf("%d", &n);
        
        printf("%d\n", apt[k][n]);
    }
    
    return 0;
}