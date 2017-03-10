#include <iostream>
#include <cstring>

int arr[1024];

int main() {
    int n, v, s, max;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        memset(arr, 0, sizeof(arr));
        max = 0;
        
        scanf("%d", &v);
        
        for (int j = 0; j < v; ++j) {
            scanf("%d", &s);
            ++arr[s];
        }
        
        for (int j = 1; j <= 1000; ++j) {
            if (arr[max] < arr[j]) {
                max = j;
            }
        }
        
        printf("%d\n", max);
    }
    
    return 0;
}