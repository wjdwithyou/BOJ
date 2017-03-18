#include <iostream>

int main() {
    char cambridge[16] = "CAMBRIDGE";
    char buf[128];
    int chk;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        chk = 1;
        
        for (int j = 0; cambridge[j] != '\0'; ++j) {
            if (buf[i] == cambridge[j]) {
                --chk;
                break;
            }
        }
        
        if (chk) {
            printf("%c", buf[i]);
        }
    }
    
    return 0;
}