#include <iostream>
#include <cstring>

int main() {
    char fbi[4] = "FBI";
    char list[8][16];
    int len, ochk, ichk;
    int cnt = 0;
    
    for (int i = 1; i <= 5; ++i) {
        ochk = 0;
        
        scanf("%s", list[i]);
        len = strlen(list[i]);
        
        for (int j = 0; j < len - 2; ++j) {
            ichk = 1;
            
            for (int k = 0; k < 3; ++k) {
                if (fbi[k] != list[i][j + k]) {
                    --ichk;
                    break;
                }
            }
            
            if (ichk) {
                ++ochk;
                break;
            }
        }
        
        if (ochk) {
            printf("%d ", i);
            ++cnt;
        }
    }
    
    if (!cnt) {
        printf("HE GOT AWAY!");
    }
    
    return 0;
}