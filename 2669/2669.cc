#include <iostream>

int arr[128][128];

int main() {
    int x1, y1, x2, y2;
    int area = 0;
    
    for (int i = 0; i < 4; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        
        for (int a = y1; a < y2; ++a) {
            for (int b = x1; b < x2; ++b) {
                if (!arr[a][b]) {
                    ++arr[a][b];
                    ++area;
                }
            }
        }
    }
    
    printf("%d", area);
    return 0;
}