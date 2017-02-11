#include <iostream>
#include <cstring>

int main() {
    char buf[1024];
    int n, mid;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        mid = strlen(buf) >> 1;
        
        puts((buf[mid] == buf[mid - 1]) ? "Do-it" : "Do-it-Not");
    }
    
    return 0;
}