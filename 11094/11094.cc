#include <iostream>
#include <cstring>

int main() {
    char simon[16] = "Simon says";
    char buf[128];
    int n, chk;
    int len = strlen(simon);
    
    scanf("%d", &n);
    while (getchar() != '\n');
    
    for (int i = 0; i < n; ++i) {
        chk = 0;
        
        fgets(buf, 128, stdin);
        
        for (int j = 0; j < len; ++j) {
            if (simon[j] != buf[j]) {
                ++chk;
                break;
            }
        }
        
        if (!chk) {
            printf("%s", &buf[len]);
        }
    }
    
    return 0;
}