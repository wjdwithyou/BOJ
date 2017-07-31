#include <iostream>

int main() {
    int arr[4], tmp[4];
    int cnt;
    
    while (1) {
        for (int i = 0; i < 4; ++i) {
            scanf("%d", &arr[i]);
        }
        
        if (!arr[0]) {
            break;
        }
        
        for (cnt = 0; arr[0] != arr[1] || arr[1] != arr[2] || arr[2] != arr[3] || arr[3] != arr[0]; ++cnt) {
            for (int i = 0; i < 4; ++i) {
                tmp[i] = abs(arr[i] - arr[(i + 1) % 4]);
            }
            for (int i = 0; i < 4; ++i) {
                arr[i] = tmp[i];
            }
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}