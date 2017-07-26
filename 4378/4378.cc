#include <iostream>

char buf[67108864];

int main() {
    char hash[128] = "                                       ;    M0,.9`12345678 L -    VXSWDFGUHJKNBIO EARYCQZT P][";
    
    while (fgets(buf, 67108864, stdin)) {
        for (int i = 0; buf[i] != '\n'; ++i) {
            buf[i] = hash[buf[i]];
        }
        
        printf("%s", buf);
    }
    
    return 0;
}