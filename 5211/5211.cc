#include <iostream>
#include <cstring>

void check(char, int*, int*);

int main() {
    char buf[128];
    char *ptr, *pptr;
    int nc = 0, na = 0;
    
    scanf("%s", buf);
    
    ptr = strtok(buf, "|");
    
    do {
        check(ptr[0], &nc, &na);
        pptr = ptr;
    } while (ptr = strtok(NULL, "|"));
    
    if (nc == na) {
        check(pptr[strlen(pptr) - 1], &nc, &na);
    }
    
    puts((nc > na) ? "C-major" : "A-minor");
    return 0;
}

void check(char c, int* nc, int* na) {
    static char major[4] = "CFG";
    static char minor[4] = "ADE";
    
    for (int i = 0; i < 3; ++i) {
        if (c == major[i]) {
            ++(*nc);
            break;
        }
        if (c == minor[i]) {
            ++(*na);
            break;
        }
    }
    
    return;
}