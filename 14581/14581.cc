#include <iostream>

int main() {
    char id[32];
    
    scanf("%s", id);
    
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            printf(":%s:", (!i && !j) ? id : "fan");
        }
        puts("");
    }
    
    return 0;
}