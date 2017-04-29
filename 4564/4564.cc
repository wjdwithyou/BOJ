#include <iostream>

int main() {
    char s[8];
    int n;
    
    while (true) {
        scanf("%s", s);
        
        if (s[0] == '0') {
            break;
        }
        
        while (true) {
            n = 1;
            
            printf("%s ", s);
            
            if (s[1] == '\0') {
                break;
            }
            
            for (int i = 0; s[i] != '\0'; n *= s[i++] - '0');
            
            sprintf(s, "%d", n);
        }
        
        puts("");
    }
    
    return 0;
}