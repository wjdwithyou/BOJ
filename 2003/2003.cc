#include <iostream>

int arr[16384];

int main() {
    int sum = 0, cnt = 0;
    int front = 0, back = 0;
    int n, m;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }
    
    while (back <= n || sum >= m) {
        if (sum < m) {
            sum += arr[++back];
        } else if (sum > m) {
            sum -= arr[++front];
        } else {
            sum += arr[++back];
            sum -= arr[++front];
            ++cnt;
        }
    }
    
    return !printf("%d", cnt);
}