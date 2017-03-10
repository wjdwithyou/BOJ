#include <iostream>

int main() {
    int arr[64];
    int k, n, idx, temp, max;
    
    scanf("%d", &k);
    
    for (int i = 1; i <= k; ++i) {
        max = 0;
        
        scanf("%d", &n);
        
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[j]);
        }
        
        for (int a = 0; a < n; ++a) {
            idx = a;
            
            for (int b = a + 1; b < n; ++b) {
                if (arr[idx] > arr[b]) {
                    idx = b;
                }
            }
            
            temp = arr[a];
            arr[a] = arr[idx];
            arr[idx] = temp;
        }
        
        for (int j = 1; j < n; ++j) {
            if (max < arr[j] - arr[j - 1]) {
                max = arr[j] - arr[j - 1];
            }
        }
        
        printf("Class %d\n", i);
        printf("Max %d, Min %d, Largest gap %d\n", arr[n - 1], arr[0], max);
    }
    
    return 0;
}