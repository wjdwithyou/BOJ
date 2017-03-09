#include <iostream>
#include <cstring>

int main() {
    char buf[128];
    char* ptr;
    int sum = 0;
    
    scanf("%s", buf);
    
    sum += atoi(strtok(buf, ","));
    
    while (ptr = strtok(NULL, ",")) {
        sum += atoi(ptr);
    }
    
    printf("%d", sum);
    return 0;
}