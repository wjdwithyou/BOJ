#include <iostream>

char a[16384], b[16384];

int main() {
    unsigned long long int sum = 0;
    
    scanf("%s %s", a, b);
    
    for (int i = 0; a[i] != '\0'; ++i) {
        if (a[i] == '0') {
            continue;
        }
        
        for (int j = 0; b[j] != '\0'; ++j) {
            sum += (a[i] - '0') * (b[j] - '0');
        }
    }
    
    printf("%llu", sum);
    return 0;
}