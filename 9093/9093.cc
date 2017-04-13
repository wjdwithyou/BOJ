#include <iostream>
#include <cstring>

int main() {
    char buf[1024];
    char* word;
    int t;
    
    scanf("%d", &t);
    while (getchar() != '\n');
    
    for (int i = 0; i < t; ++i) {
        fgets(buf, 1024, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        word = strtok(buf, " ");
        
        do {
            for (int j = strlen(word) - 1; j >= 0; --j) {
                printf("%c", word[j]);
            }
            printf(" ");
        } while (word = strtok(NULL, " "));
        
        puts("");
    }
    
    return 0;
}