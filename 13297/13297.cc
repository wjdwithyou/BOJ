#include <iostream>
#include <cstring>

int main() {
    char buf[128];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        printf("%d\n", strlen(buf));
    }
    
    return 0;
}