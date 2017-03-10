#include <iostream>

int main() {
    char x[32], y[32];
    int t;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%s %s", x, y);
        printf("Distances: ");
        
        for (int j = 0; x[j] != '\0'; ++j) {
            printf("%d ", (y[j] >= x[j]) ? y[j] - x[j] : y[j] - x[j] + 26);
        }
        
        printf("\n");
    }
    
    return 0;
}