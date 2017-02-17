#include <iostream>

int main() {
    int in, out;
    int n = 0, max = 0;
    
    for (int i = 0; i < 10; ++i) {
        scanf("%d %d", &out, &in);
        
        n += (in - out);
        
        if (max < n) {
            max = n;
        }
    }
    
    printf("%d", max);
    return 0;
}