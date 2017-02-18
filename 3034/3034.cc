#include <iostream>

int main() {
    int n, w, h, len;
    
    scanf("%d %d %d", &n, &w, &h);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &len);
        puts((w * w + h * h >= len * len) ? "DA" : "NE");
    }
    
    return 0;
}