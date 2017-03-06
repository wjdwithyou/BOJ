#include <iostream>

#define MAX_NUM 100000000

char arr[MAX_NUM + 1];

int main() {
    int a, b, t, cnt;
    
    scanf("%d %d", &a, &b);
    
    cnt = a;
    
    for (int i = 0; i < a; ++i) {
        scanf("%d", &t);
        ++arr[t];
    }
    
    for (int i = 0; i < b; ++i) {
        scanf("%d", &t);
        (arr[t]) ? --cnt : ++cnt;
    }
    
    printf("%d", cnt);
    return 0;
}