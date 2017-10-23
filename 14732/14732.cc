#include <iostream>

int arr[512][512];

int main(void) {
    int n, x1, y1, x2, y2;
    int area = 0;
    
    scanf("%d", &n);
    
    for (int k = 0; k < n; ++k) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        for (int i = y1; i < y2; ++i) {
            for (int j = x1; j < x2; ++j) {
                if (arr[i][j]) {
                    continue;
                }
                
                ++arr[i][j];
                ++area;
            }
        }
    }
    
    return !printf("%d", area);
}