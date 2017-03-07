#include <iostream>
#include <cstring>
#include <cmath>

char color[16][8] = {
    "black",
    "brown",
    "red",
    "orange",
    "yellow",
    "green",
    "blue",
    "violet",
    "grey",
    "white"
};

int main() {
    char buf[8];
    int j;
    unsigned long long int r = 0;
    
    for (int i = 0; i < 3; ++i) {
        scanf("%s", buf);
        
        for (j = 0; j < 10; ++j) {
            if (!strcmp(color[j], buf)) {
                break;
            }
        }
        
        switch (i) {
            case 0:
                r += j * 10;
                break;
            case 1:
                r += j;
                break;
            case 2:
                r *= static_cast<int>(pow(10, j));
                break;
            default:
                break;
        }
    }
    
    printf("%llu", r);
    return 0;
}