#include <iostream>
#include <cstring>
#include <cmath>

int main() {
    char buf[16];
    int len;
    int sum = 0;
    
    scanf("%s", buf);
    len = strlen(buf);
    
    for (int i = 1; i < len; ++i) {
        sum += i * 9 * static_cast<int>(pow(10, i - 1));
    }
    
    sum += len * (atoi(buf) - static_cast<int>(pow(10, len - 1)) + 1);
    
    printf("%d", sum);
    return 0;
}