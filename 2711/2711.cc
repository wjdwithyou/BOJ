#include <iostream>

int main() {
    char buf[128];
    int t, l;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i){
        scanf("%d %s", &l, buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            if (j == l - 1){
                continue;
            }
            
            printf("%c", buf[j]);
        }
        printf("\n");
    }
    
    return 0;
}