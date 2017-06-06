#include <iostream>

#define NUM_ALPHA 26

int main() {
    char name[64];
    int n;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        scanf("%s", name);
        
        for (int j = 0; name[j] != '\0'; ++j) {
            name[j] = ((name[j] - 'A' + 1) % NUM_ALPHA) + 'A';
        }
        
        printf("String #%d\n%s\n\n", i, name);
    }
    
    return 0;
}