#include <iostream>

#define MAX 64

char arr[MAX + 1][MAX + 1];

void qt(int, int, int, int);

int main() {
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", arr[i]);
    }
    
    qt(0, 0, n, n);
    
    return 0;
}

void qt(int x1, int y1, int x2, int y2) {
    int d = (x2 - x1) >> 1;
    
    if (!d) {
        printf("%c", arr[y1][x1]);
        return;
    }
    
    int c[2] = { 0 };
    
    for (int i = y1; i < y2; ++i) {
        for (int j = x1; j < x2; ++j) {
            ++c[arr[i][j] - '0'];
        }
    }
    
    if (!c[0] || !c[1]) {
        printf("%d", c[0] == 0);
        return;
    }
    
    printf("(");
    
    for (int i = y1; i < y2; i += d) {
        for (int j = x1; j < x2; j += d) {
            qt(j, i, j + d, i + d);
        }
    }
    
    printf(")");
    return;
}