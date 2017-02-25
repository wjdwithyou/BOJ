#include <iostream>
#include <cstring>
#include <cmath>

int main() {
    char buf[8];
    int len;
    int sum = 0;
    
    scanf("%s", buf);
    
    len = strlen(buf);
    
    for (int i = len - 1; i >= 0; --i) {
        sum += ((buf[i] <= '9') ? buf[i] - '0' : buf[i] - 'A' + 10) * static_cast<int>(pow(16, (len - 1) - i)); 
    }
    
    printf("%d", sum);
    return 0;
}