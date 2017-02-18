#include <iostream>

int main() {
    int counter[128] = { 0, };
    int t;
    int idx = 0, sum = 0;
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d", &t);
        
        sum += t;
        t /= 10;
        
        ++counter[t];
        
        if (counter[idx] < counter[t]) {
            idx = t;
        }
    }
    
    printf("%d\n%d", sum / 10, idx * 10);
    return 0;
}