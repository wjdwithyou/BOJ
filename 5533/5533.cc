#include <iostream>

int arr[256][4];

int main() {
    int chk[128][4] = { 0 };
    int n, s;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &arr[i][j]);
            ++chk[arr[i][j]][j];
        }
    }
    
    for (int i = 0; i < n; ++i) {
        s = 0;
        
        for (int j = 0; j < 3; ++j) {
            if (chk[arr[i][j]][j] == 1) {
                s += arr[i][j];
            }
        }
        
        printf("%d\n", s);
    }
    
    return 0;
}