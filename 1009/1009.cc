#include <iostream>
#include <cstring>

int main() {
    char mod[16][8] = { "0", "1", "2486", "3971", "46", "5", "6", "7931", "8426", "91" };
    int t, a, b;
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &a, &b);
        
        a %= 10;
        
        printf("%d\n", (a)? mod[a][--b % strlen(mod[a])] - '0' : 10);
    }
    
    return 0;
}