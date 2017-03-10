#include <iostream>

int arr[131072];

int main() {
    int k, t;
    int idx = 0, sum = 0;
    
    scanf("%d", &k);
    
    for (int i = 0; i < k; ++i) {
        scanf("%d", &t);
        
        if (t) {
            arr[idx++] = t;
            sum += t;
        } else {
            sum -= arr[--idx];
        }
    }
    
    printf("%d", sum);
    return 0;
}