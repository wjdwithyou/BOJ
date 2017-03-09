#include <iostream>

int main() {
    int arr[4];
    int idx, temp;
    
    while (true) {
        for (int i = 0; i < 3; ++i) {
            scanf("%d", &arr[i]);
            arr[i] *= arr[i];
        }
        
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            break;
        }
        
        for (int i = 0; i < 3; ++i) {
            idx = i;
            
            for (int j = i; j < 3; ++j) {
                if (arr[idx] > arr[j]) {
                    idx = j;
                }
            }
            
            temp = arr[i];
            arr[i] = arr[idx];
            arr[idx] = temp;
        }
        
        puts((arr[0] + arr[1] == arr[2]) ? "right" : "wrong");
    }
    
    return 0;
}