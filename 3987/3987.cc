#include <iostream>
#include <cstring>

int chk[512][512];
char arr[512][512];

void move(int*, int*, int);
int getDir(char, int);
char getDirChar(int);

int main() {
    int n, m, r, c, pr, pc, d, md;
    int mt = -1, v = 0;
    
    scanf("%d %d", &n, &m);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", arr[i]);
    }
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0b0001; !v && i <= 0b1000; i <<= 1) {
        memset(chk, 0, sizeof(chk));
        
        pr = r - 1;
        pc = c - 1;
        d = i;
        
        for (int t = 0;; ++t) {
            if (pr < 0 || pr >= n || pc < 0 || pc >= m) {
                if (mt < t) {
                    md = i;
                    mt = t;
                }
                break;
            } else if (arr[pr][pc] == '.') {
                move(&pr, &pc, d);
            } else if (arr[pr][pc] == 'C') {
                if (mt < t) {
                    md = i;
                    mt = t;
                }
                break;
            } else {
                if (chk[pr][pc] & d) {
                    md = i;
                    ++v;
                    break;
                } else {
                    chk[pr][pc] += d;
                    d = getDir(arr[pr][pc], d);
                    
                    move(&pr, &pc, d);
                }
            }
        }
    }
    
    printf("%c\n", getDirChar(md));
    
    (v) ? printf("Voyager") : printf("%d", mt);
    
    return 0;
}

void move(int* pr, int* pc, int d) {
    if (d < 0b0100) {
        (d & 0b0101) ? --(*pr) : ++(*pc);
    } else {
        (d & 0b0101) ? ++(*pr) : --(*pc);
    }
    
    return;
}

int getDir(char p, int d) {
    if (p == '/') {
        switch (d) {
            case 0b0001:
                return 0b0010;
            case 0b0010:
                return 0b0001;
            case 0b0100:
                return 0b1000;
            case 0b1000:
                return 0b0100;
            default:
                return 0;
        }
    } else {
        switch (d) {
            case 0b0001:
                return 0b1000;
            case 0b0010:
                return 0b0100;
            case 0b0100:
                return 0b0010;
            case 0b1000:
                return 0b0001;
            default:
                return 0;
        }
    }
}

char getDirChar(int d) {
    switch (d) {
        case 0b0001:
            return 'U';
        case 0b0010:
            return 'R';
        case 0b0100:
            return 'D';
        case 0b1000:
            return 'L';
        default:
            return 0;
    }
}