#include <iostream>
#include <cstring>

int main() {
    char buf[64];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        puts(((buf[strlen(buf) - 1] - '0') & 1) ? "odd" : "even");
    }
    
    return 0;
}