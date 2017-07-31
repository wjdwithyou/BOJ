#include <iostream>

int arr[512];

int main() {
    int n;
    int cnt = 0;
    
    for (int i = 1; i <= 500; ++i) {
        arr[i] = i * i;
    }
    
    scanf("%d", &n);
    
    for (int i = 1; i < 500; ++i) {
        for (int j = i + 1; j <= 500; ++j) {
            if (arr[i] + n <= arr[j]) {
                if (arr[i] + n == arr[j]) {
                    ++cnt;
                }
                break;
            }
        }
    }
    
    return !printf("%d", cnt);
}