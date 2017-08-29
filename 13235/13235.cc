#include <iostream>
#include <cstring>

int main() {
    char buf[32];
    int chk = 0;
    
    scanf("%s", buf);
    
    for (int i = 0, j = strlen(buf) - 1; i < j && !chk; ++i, --j) {
        if (buf[i] != buf[j]) {
            ++chk;
        }
    }
    
    return !printf("%s", (chk) ? "false" : "true");
}