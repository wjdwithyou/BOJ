#include <iostream>

int main() {
    char gan[16] = "6789012345";
    char ji[16] = "IJKLABCDEFGH";
    int n;
    
    scanf("%d", &n);
    printf("%c%c", ji[n % 12], gan[n % 10]);
    
    return 0;
}