#include <iostream>
#include <cstring>
#include <cmath>

int main() {
    char buf[64];
    char* ptr;
    int h;
    int t = 1;
    
    fgets(buf, 64, stdin);
    buf[strlen(buf) - 1] = '\0';
    
    h = atoi(strtok(buf, " "));
    ptr = strtok(NULL, " ");
    
    for (int i = 0; ptr && ptr[i] != '\0'; ++i) {
        t <<= 1;
        
        if (ptr[i] == 'R') {
            t += 1;
        }
    }
    
    return !printf("%d", static_cast<int>(pow(2, ++h)) - t);
}