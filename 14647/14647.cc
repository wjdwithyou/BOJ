#include <iostream>

int row[512], col[512];

int main() {
    int n, m, t;
    int sum = 0, max = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (scanf("%d", &t); t; t /= 10) {
                if (t % 10 == 9) {
                    ++row[i];
                    ++col[j];
                    ++sum;
                }
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (max < row[i]) {
            max = row[i];
        }
    }
    for (int j = 0; j < m; ++j) {
        if (max < col[j]) {
            max = col[j];
        }
    }
    
    return !printf("%d", sum - max);
}