#include <iostream>

char buf[128][128];

int main(){
    int n, k;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i){
        scanf("%s", buf[i]);
    }
    
    scanf("%d", &k);
    
    switch (k){
        case 1:
            for (int i = 0; i < n; ++i){
                printf("%s\n", buf[i]);
            }
            break;
        case 2:
            for (int i = 0; i < n; ++i){
                for (int j = n - 1; j >= 0; --j){
                    printf("%c", buf[i][j]);
                }
                printf("\n");
            }
            break;
        case 3:
            for (int i = n - 1; i >= 0; --i){
                printf("%s\n", buf[i]);
            }
            break;
        default:
            break;
    }
    
    return 0;
}