#include <iostream>
#include <cstring>

int getVowelNum(char[]);
void dfs(char[], char[], int, int, int, int);

int main() {
    char buf[32], chara[16], pw[16];
    int l, c, idx;
    char t;
    char* ptr;
    
    scanf("%d %d", &l, &c);
    while (getchar() != '\n');
    
    fgets(buf, 32, stdin);
    buf[strlen(buf) - 1] = '\0';
    
    chara[0] = strtok(buf, " ")[0];
    
    for (int i = 1; ptr = strtok(NULL, " "); ++i) {
        chara[i] = ptr[0];
    }
    
    for (int i = 0; i < c; ++i) {
        idx = i;
        
        for (int j = i + 1; j < c; ++j) {
            if (chara[idx] > chara[j]) {
                idx = j;
            }
        }
        
        t = chara[i];
        chara[i] = chara[idx];
        chara[idx] = t;
    }
    
    pw[l] = '\0';
    
    dfs(chara, pw, l, c, 0, 1);
    
    return 0;
}

void dfs(char chara[], char pw[], int l, int c, int x, int d) {
    for (int i = x; i < c - l + d; ++i) {
        if (d == l + 1) {
            int vn = getVowelNum(pw);
            
            if (vn && l - vn >= 2) {
                puts(pw);
            }
            break;
        } else {
            pw[d - 1] = chara[i];
            dfs(chara, pw, l, c, i + 1, d + 1);
        }
    }
    
    return;
}

int getVowelNum(char pw[]) {
    int cnt = 0;
    
    for (int i = 0; pw[i] != '\0'; ++i) {
        switch (pw[i]) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                ++cnt;
            default:
                break;
        }
    }
    
    return cnt;
}