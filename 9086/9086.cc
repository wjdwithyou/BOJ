#include <iostream>
#include <cstring>

int main() {
    char buf[1024];
    int t;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%s", buf);
        printf("%c", buf[0]);
        printf("%c", buf[strlen(buf) - 1]);
        printf("\n");
    }
    
    return 0;
}