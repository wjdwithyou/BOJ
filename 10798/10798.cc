#include <iostream>

int main() {
    char arr[8][16] = { 0, };
    
    for (int i = 0; i < 5; ++i) {
        scanf("%s", arr[i]);
    }
    
    for (int j = 0; j < 15; ++j) {
        for (int i = 0; i < 5; ++i) {
            if (arr[i][j]) {
                printf("%c", arr[i][j]);
            }
        }
    }
    
    return 0;
}