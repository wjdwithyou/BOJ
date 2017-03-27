#include <iostream>

int main() {
    char buf[64];
    int arr[4] = { 1 };
    int idx, temp;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        idx = buf[i] - 'A';
        
        temp = arr[idx];
        arr[idx] = arr[(idx + 1) % 3];
        arr[(idx + 1) % 3] = temp;
    }
    
    for (int i = 0; i < 3; ++i) {
        if (arr[i]) {
            printf("%d", i + 1);
            break;
        }
    }
    
    return 0;
}