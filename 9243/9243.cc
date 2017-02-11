#include <iostream>

int main() {
    char buf1[1024], buf2[1024];
    int n;
    int chk = 0;
    
    scanf("%d", &n);
    scanf("%s", buf1);
    scanf("%s", buf2);
    
    for (int i = 0; buf1[i] != '\0'; ++i) {
        if ((buf1[i]^buf2[i]) != (n & 1)) {
            ++chk;
            break;
        }
    }
    
    printf("%s", (chk) ? "Deletion failed" : "Deletion succeeded");
    return 0;
}