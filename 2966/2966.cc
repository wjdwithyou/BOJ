#include <iostream>

typedef struct Person {
    char id[8];
    char gt[8];
    int gtlen;
    int cnt;
}Person;

int main() {
    Person person[4] = { { "Adrian", "ABC", 3, 0 }, { "Bruno", "BABC", 4, 0 }, { "Goran", "CCAABB", 6, 0 } };
    char buf[128];
    int n;
    int max = 0;
    
    scanf("%d", &n);
    scanf("%s", buf);
    
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < n; ++j) {
            if (buf[j] == person[i].gt[j % person[i].gtlen]) {
                ++person[i].cnt;
            }
        }
        
        if (max < person[i].cnt) {
            max = person[i].cnt;
        }
    }
    
    printf("%d\n", max);
    
    for (int i = 0; i < 3; ++i) {
        if (max == person[i].cnt) {
            puts(person[i].id);
        }
    }
    
    return 0;
}