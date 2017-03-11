#include <iostream>

int main() {
    char buf[32];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            printf("%c", buf[j] + ((buf[j] >= 'a') ? 0 : 32));
        }
        printf("\n");
    }
    
    return 0;
}