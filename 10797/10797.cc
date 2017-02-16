#include <iostream>

int main() {
    int d, c;
    int cnt = 0;
    
    scanf("%d", &d);
    
    for (int i = 0; i < 5; ++i) {
        scanf("%d", &c);
        
        if (d == c) {
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}