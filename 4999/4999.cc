#include <iostream>
#include <cstring>

int main() {
    char buf[1024];
    int len[2];
    
    for (int i = 0; i < 2; ++i) {
        scanf("%s", buf);
        len[i] = strlen(buf);
    }
    
    printf("%s", (len[0] < len[1]) ? "no" : "go");
    return 0;
}