#include <iostream>

int arr[1024];

int main() {
    int n;
    
    ++arr[2];
    
    scanf("%d", &n);
    
    for (int i = 5; i <= n; ++i) {
        arr[i] = !(arr[i - 4] || arr[i - 3] || arr[i - 1]);
    }
    
    return !printf("%s", (arr[n]) ? "CY" : "SK");
}