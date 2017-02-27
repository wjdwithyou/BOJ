#include <iostream>
#include <cmath>

#define MAX 262144

int counter[MAX];

int main() {
    char buf[8];
    int a, p;
    int cnt = 0;
    
    scanf("%d %d", &a, &p);
    
    while (++counter[a] <= 2) {
        sprintf(buf, "%d", a);
        
        a = 0;
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            a += static_cast<int>(pow(static_cast<double>(buf[j] - '0'), p));
        }
    }
    
    for (int i = 1; i < MAX; ++i) {
        if (counter[i] == 1) {
            ++cnt;
        }
    }
    
    printf("%d", cnt);
    return 0;
}