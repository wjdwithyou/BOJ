#include <iostream>
#include <cstring>

char pre[16][16] = { "", "", "double", "triple", "quadruple", "quintuple", "sextuple", "septuple", "octuple", "nonuple", "decuple" };
char num[16][8] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void printNum(int, int);

int main() {
    char pn[1024], format[1024];
    char* ptr;
    int t, ck, mk, tcnt;
    
    scanf("%d", &t);
    
    for (int i = 1; i <= t; ++i) {
        ck = 0;
        
        scanf("%s %s", pn, format);
        printf("Case #%d: ", i);
        
        ptr = strtok(format, "-");
        
        do {
            mk = ck + atoi(ptr);
            tcnt = 1;
            
            for (;ck < mk; ++ck) {
                if (pn[ck + 1] == pn[ck] && ck + 1 != mk) {
                    ++tcnt;
                }
                else {
                    printNum(tcnt, pn[ck] - '0');
                    tcnt = 1;
                }
            }
        } while (ptr = strtok(NULL, "-"));
        
        printf("\n");
    }
    
    return 0;
}

void printNum(int tcnt, int cur) {
    if (tcnt >= 2 && tcnt <= 10) {
        printf("%s ", pre[tcnt]);
    }
    
    for (int i = 0; i < ((tcnt > 10) ? tcnt : 1); ++i) {
        printf("%s ", num[cur]);
    }
    
    return;
}