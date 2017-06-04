#include <iostream>
#include <cstring>

int checkVowel(char);

int main() {
    char pw[32];
    int nv, cv, cc, low;
    
    while (1) {
        nv = cv = cc = low = 0;
        
        scanf("%s", pw);
        
        if (!strcmp("end", pw)) {
            break;
        }
        
        for (int i = 0; pw[i] != '\0'; ++i) {
            if (checkVowel(pw[i])) {
                ++nv;
                ++cv;
                cc = 0;
            } else {
                ++cc;
                cv = 0;
            }
            
            if (!i) {
                continue;
            }
            
            if (cv > 2 || cc > 2 || pw[i] == pw[i - 1] && pw[i] != 'e' && pw[i] != 'o') {
                ++low;
                break;
            }
        }
        
        if (!nv) {
            ++low;
        }
        
        printf("<%s> is%s acceptable.\n", pw, (low) ? " not" : "");
    }
    
    return 0;
}

int checkVowel(char c) {
    char vowel[8] = "aeiou";
    int chk = 0;
    
    for (int i = 0; vowel[i] != '\0'; ++i) {
        if (vowel[i] == c) {
            ++chk;
            break;
        }
    }
    
    return chk;
}