#include <iostream>

int main() {
    int arr[2][2] = { 0, };
    int x, y;
    
    for (int i = 0; i < 3; ++i) {
        scanf("%d %d", &x, &y);
        
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                if (arr[j][k] == 0) {
                    arr[j][k] = (j) ? y : x;
                    break;
                }
                else if (arr[j][k] == ((j) ? y : x)) {
                    arr[j][k] = 0;
                    break;
                }
                else;
            }
        }
    }
    
    for (int j = 0; j < 2; ++j) {
        for (int k = 0; k < 2; ++k) {
            if (arr[j][k]) {
                printf("%d ", arr[j][k]);
                break;
            }
        }
    }
    
    return 0;
}