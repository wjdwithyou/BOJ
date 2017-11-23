#include <iostream>

void dfs(int, int, int, int, int*);

int main(void) {
    int n;
    int sum = 0, cnt = 0;
    
    scanf("%d", &n);
    
    for (int i = 1; i < 3; ++i) {
        dfs(sum, n, i, 0, &cnt);
    }
    
    return !printf("%d", cnt);
}

void dfs(int sum, int n, int num, int d, int* cnt) {
    sum += num;
    
    if (++d >= n) {
        if (!(sum % 3)) {
            ++(*cnt);
        }
        
        return;
    }
    
    for (int i = 0; i < 3; ++i) {
        dfs(sum, n, i, d, cnt);
    }
    
    return;
}