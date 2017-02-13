#include <iostream>

int main() {
    char vowel[8] = "aeiou";
    char buf[128];
    int cnt = 0;
    
    scanf("%s", buf);
    
    for (int i = 0; buf[i] != '\0'; ++i) {
        for (int j = 0; vowel[j] != '\0'; ++j) {
            if (buf[i] == vowel[j]) {
                ++cnt;
                break;
            }
        }
    }
    
    printf("%d", cnt);
    return 0;
}