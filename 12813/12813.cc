#include <iostream>

#define MAX 100000

char a[MAX + 1], b[MAX + 1];

int main() {
    scanf("%s %s", a, b);
    
    for (int i = 0; i < MAX; ++i) {
        printf("%d", (a[i] == '1' && b[i] == '1'));
    }
    puts("");
    for (int i = 0; i < MAX; ++i) {
        printf("%d", (a[i] == '1' || b[i] == '1'));
    }
    puts("");
    for (int i = 0; i < MAX; ++i) {
        printf("%d", (a[i] != b[i]));
    }
    puts("");
    for (int i = 0; i < MAX; ++i) {
        printf("%d", a[i] != '1');
    }
    puts("");
    for (int i = 0; i < MAX; ++i) {
        printf("%d", b[i] != '1');
    }
    
    return 0;
}