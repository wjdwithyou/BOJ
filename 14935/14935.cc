#include <iostream>

int main(void) {
    char buf[128];
    
    setbuf(stdout, NULL);
    
    scanf("%s", buf);
    
    return !printf("FA");
}