#include <iostream>

int main() {
    char buf[16];
    int n;
    int a = 0, b = 0;
    
    scanf("%d", &n);
    scanf("%s", buf);
    
    for (int i = 0; i < n; ++i) {
        (buf[i] == 'A') ? ++a : ++b;
    }
    
    printf("%s", (a > b) ? "A" : ((a < b) ? "B" : "Tie"));
    return 0;
}