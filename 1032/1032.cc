#include <iostream>
#include <cstring>

int main() {
    char file[64][64] = { 0, };
    int n;
    
    scanf("%d", &n);
    scanf("%s", file[1]);
    
    strcpy(file[0], file[1]);
    
    for (int i = 2; i <= n; ++i) {
        scanf("%s", file[i]);
        
        for (int j = 0; file[i][j] != '\0'; ++j) {
            if (file[0][j] == '?') {
                continue;
            }
            
            if (file[i][j] != file[i - 1][j]) {
                file[0][j] = '?';
            }
        }
    }
    
    printf("%s", file[0]);
    return 0;
}