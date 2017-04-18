#include <iostream>
#include <cstring>

int main() {
    char buf[1024];
    char* ptr;
    int t, sum;
    
    scanf("%d", &t);
    while (getchar() != '\n');
    
    for (int i = 0; i < t; ++i) {
        sum = 0;
        
        fgets(buf, 1024, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        ptr = strtok(buf, " ");
        
        do {
            sum += atoi(ptr);
        } while (ptr = strtok(NULL, " "));
        
        printf("%d\n", sum);
    }
    
    return 0;
}