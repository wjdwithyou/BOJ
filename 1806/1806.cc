#include <iostream>

#define BN 131072

int arr[BN];

int main() {
    int n, s;
    int min = BN;
    int front = 0, back = 0, sum = 0;
    
    scanf("%d %d", &n, &s);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        
        if (arr[i] >= s) {
            return !printf("1");
        }
    }
    
    while (back <= n) {
        if (sum < s) {
            sum += arr[back++];
            continue;
        }
        
        if (min > back - front) {
            min = back - front;
            
            if (min < 3) {
                return !printf("2");
            }
        }
        
        sum -= arr[front++];
    }
    
    return !printf("%d", (min == BN) ? 0 : min);
}