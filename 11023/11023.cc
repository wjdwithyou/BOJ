#include <iostream>
#include <cstring>

int main() {
    char buf[1024];
    char* ptr;
    int sum = 0;
    
    fgets(buf, 1024, stdin);
    buf[strlen(buf) - 1] = '\0';
    
    sum += atoi(strtok(buf, " "));
    
    while (ptr = strtok(NULL, " ")) {
        sum += atoi(ptr);
    }
    
    printf("%d", sum);
    return 0;
}