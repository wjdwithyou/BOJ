#include <iostream>
#include <cstring>

char buf[2048];

int main() {
    char* ptr;
    int chk;
    
    while (true) {
        chk = 0;
        
        fgets(buf, 2048, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        if (buf[0] == '*') {
            break;
        }
        
        if (buf[0] >= 'a') {
            buf[0] -= 32;
        }
        
        strtok(buf, " ");
        
        while (ptr = strtok(NULL, " ")) {
            if (buf[0] != ((ptr[0] >= 'a') ? ptr[0] - 32 : ptr[0])) {
                ++chk;
                break;
            }
        }
        
        puts((chk) ? "N" : "Y");
    }
    
    return 0;
}