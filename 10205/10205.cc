#include <iostream>

int main() {
    char buf[128];
    int k, h;
    
    scanf("%d", &k);
    
    for (int i = 1; i <= k; ++i) {
        scanf("%d", &h);
        scanf("%s", buf);
        
        for (int j = 0; h > 0 && buf[j] != '\0'; ++j) {
            (buf[j] == 'c') ? ++h : --h;
        }
        
        printf("Data Set %d:\n%d\n\n", i, h);
    }
    
    return 0;
}