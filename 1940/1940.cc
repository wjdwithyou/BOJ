#include <iostream>

#define MAX 10000000

int material[MAX + 1];

int main() {
    int n, m, t;
    int cnt = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        ++material[t];
    }
    
    for (int i = 1, j = m - 1; i < j; ++i, --j) {
        cnt += (material[i] < material[j]) ? material[i] : material[j];
    }
    
    return !printf("%d", cnt);
}