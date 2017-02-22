#include <iostream>

#define NUM_ALPHA 26

int main() {
    char buf[1024];
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        printf("%c", 'A' + ((buf[i] + (NUM_ALPHA - 3) - 'A') % NUM_ALPHA));
    }
    
    return 0;
}