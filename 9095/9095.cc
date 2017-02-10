#include <iostream>

int getNum(int, int);

int main() {
    int t, n;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d", &n);
        printf("%d\n", getNum(n, 0));
    }
    
    return 0;
}

int getNum(int n, int sum) {
    int cnt = 0;
    
    for (int cur = 1; cur <= 3; ++cur) {
        int temp = sum + cur;
        
        if (temp < n) {
            cnt += getNum(n, temp);
            continue;
        }
        
        if (temp == n) {
            ++cnt;
        }
        
        break;
    }
    
    return cnt;
}