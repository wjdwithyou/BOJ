#include <iostream>

int main() {
    int a, b;
    int cnt = 1, sum = 0;
    
    scanf("%d %d", &a, &b);
    
    for (int i = 1; b >= cnt; ++i) {
        for (int j = 0; j < i && b >= cnt; ++j, ++cnt) {
            if (a <= cnt) {
                sum += i;
            }
        }
    }
    
    printf("%d", sum);
    return 0;
}