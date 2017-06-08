#include <iostream>
#include <cstring>
#include <cmath>

#define MAX 7

int main() {
    int output[8];
    char input[8];
    int from, to, len, num, t, chk;
    
    while (fscanf(stdin, "%s %d %d", input, &from, &to) != EOF) {
        len = strlen(input);
        num = 0;
        
        for (int i = 0; i < len; ++i) {
            num += ((input[i] < 'A') ? input[i] - '0' : input[i] - 'A' + 10) * static_cast<int>(pow(from, len - 1 - i));
        }
        
        if (num >= static_cast<int>(pow(to, MAX))) {
            puts("  ERROR");
            continue;
        }
        
        for (int i = MAX - 1; i >= 0; --i) {
            t = static_cast<int>(pow(to, i));
            output[MAX - 1 - i] = num / t;
            num %= t;
        }
        
        chk = 0;
        
        for (int i = 0; i < MAX; ++i) {
            if (!chk && !output[i]) {
                printf(" ");
                continue;
            }
            
            ++chk;
            
            printf("%c", (output[i] < 10) ? output[i] + '0' : output[i] - 10 + 'A');
        }
        
        puts("");
    }
    
    return 0;
}