#include <iostream>

int main() {
    int arr[2] = { 0, };
    int n, t;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ++arr[t];
    }
    
    if (arr[0] > arr[1]) {
        printf("Junhee is not cute!");
    }
    else {
        printf("Junhee is cute!");
    }
    
    return 0;
}