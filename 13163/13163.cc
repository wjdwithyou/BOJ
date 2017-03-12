#include <iostream>
#include <cstring>

int main() {
    char buf[128];
    int n;
    char* ptr;
    
    scanf("%d", &n);
    while (getchar() != '\n');
    
    for (int i = 0; i < n; ++i) {
        fgets(buf, 128, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        strtok(buf, " ");
        printf("god");
        
        while (ptr = strtok(NULL, " ")) {
            printf("%s", ptr);
        }
        
        printf("\n");
    }
    
    return 0;
}