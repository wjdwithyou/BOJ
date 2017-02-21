#include <iostream>
#include <cstring>

char buf[1048576];

int main() {
    double f;
    int t;
    char* ptr;
    
    scanf("%d", &t);
    
    while (getchar() != '\n');
    
    for (int i = 0; i < t; ++i) {
        fgets(buf, 1048576, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        ptr = strtok(buf, " ");
        f = atof(ptr);
        
        while (ptr = strtok(NULL, " ")) {
            switch (ptr[0]) {
                case '@':
                    f *= 3;
                    break;
                case '%':
                    f += 5;
                    break;
                case '#':
                    f -= 7;
                    break;
                default:
                    break;
            }
        }
        
        printf("%.2f\n", f);
    }
    
    return 0;
}