#include <iostream>
#include <cstring>

int getGCD(int, int);

int main() {
    char buf[2048];
    int arr[128];
    int n, cnt, max, g;
    char* ptr;
    
    scanf("%d", &n);
    while (getchar() != '\n');
    
    for (int i = 0; i < n; ++i) {
        fgets(buf, 2048, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        max = 0;
        
        ptr = strtok(buf, " ");
        
        for (int j = 0;; ++j) {
            arr[j] = atoi(ptr);
            
            if (!(ptr = strtok(NULL, " "))) {
                cnt = ++j;
                break;
            }
        }
        
        for (int j = 0; j < cnt; ++j) {
            for (int k = j + 1; k < cnt; ++k) {
                g = getGCD(arr[j], arr[k]);
                
                if (max < g) {
                    max = g;
                }
            }
        }
        
        printf("%d\n", max);
    }
    
    return 0;
}

int getGCD(int a, int b) {
    int t;
    
    if (a > b) {
        t = b;
        b = a;
        a = t;
    }
    
    do {
        t = b % a;
        b = a;
        a = t;
    } while (a);
    
    return b;
}