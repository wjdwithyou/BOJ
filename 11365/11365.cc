#include <iostream>
#include <cstring>

char buf[1048576];

int main() {
    char end[4] = "END";
    
    while (true) {
        fgets(buf, 1048576, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        if (!strcmp(end, buf)) {
            break;
        }
        
        for (int i = strlen(buf) - 1; i >= 0; --i) {
            printf("%c", buf[i]);
        }
        printf("\n");
    }
    
    return 0;
}