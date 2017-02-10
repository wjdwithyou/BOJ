#include <iostream>

int main() {
    int arr[8] = { 0, };
    int t;
    int idx = 1;
    
    for (int i = 0; i < 3; ++i) {
        scanf("%d", &t);
        ++arr[t];
    }
    
    for (int i = 2; i <= 6; ++i) {
        if (arr[idx] <= arr[i]) {
            idx = i;
        }
    }
    
    if (arr[idx] == 3) {
        printf("%d", idx * 1000 + 10000);
    }
    else if (arr[idx] == 2) {
        printf("%d", idx * 100 + 1000);
    }
    else {
        printf("%d", idx * 100);
    }
    
    return 0;
}