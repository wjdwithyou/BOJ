#include <iostream>
#include <cstring>

#define N 10

int main(void) {
    const char* useless[16] = { "i", "pa", "te", "ni", "niti", "a", "ali", "nego", "no", "ili" };
    char buf[128];
    int chk;
    
    setbuf(stdout, NULL);
    
    scanf("%s", buf);
    printf("%c", buf[0] - 32);
    
    while (fscanf(stdin, "%s", buf) != EOF) {
        chk = 0;
        
        for (int i = 0; i < N; ++i) {
            if (!strcmp(useless[i], buf)) {
                ++chk;
                break;
            }
        }
        
        if (!chk) {
            printf("%c", buf[0] - 32);
        }
    }
    
    return 0;
}