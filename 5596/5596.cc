#include <iostream>

int main() {
    int arr[2] = { 0, };
    int temp;
    
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 4; ++j) {
            scanf("%d", &temp);
            arr[i] += temp;
        }
    }
    
    printf("%d", (arr[0] > arr[1]) ? arr[0] : arr[1]);
    return 0;
}