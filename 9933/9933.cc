#include <iostream>
#include <cstring>

typedef struct Element {
    char word[16];
    int len;
}Element;

Element list[128];

int main() {
    int n, ichk;
    int ochk = 1;
    
    scanf("%d", &n);
    
    for (int i = 0; ochk; ++i) {
        scanf("%s", list[i].word);
        list[i].len = strlen(list[i].word);
        
        for (int j = i; j >= 0; --j) {
            if (list[i].len != list[j].len) {
                continue;
            }
            
            ichk = 1;
            
            for (int a = 0, b = list[i].len - 1; a < b; ++a, --b) {
                if (list[i].word[a] != list[j].word[b]) {
                    --ichk;
                    break;
                }
            }
            
            if (ichk) {
                printf("%d %c", list[i].len, list[i].word[list[i].len >> 1]);
                --ochk;
                break;
            }
        }
    }
    
    return 0;
}