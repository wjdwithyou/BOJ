#include <iostream>

char buf[524288];

int main() {
    char octaf[8][4] = { "0", "1", "10", "11", "100", "101", "110", "111" };
    char octa[8][4] = { "000", "001", "010", "011", "100", "101", "110", "111" };
    
    scanf("%s", buf);
    
    printf("%s", octaf[buf[0] - '0']);
    
    for (int i = 1; buf[i] != '\0'; ++i) {
        printf("%s", octa[buf[i] - '0']);
    }
    
    return 0;
}