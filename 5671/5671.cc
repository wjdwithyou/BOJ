#include <iostream>
#include <cstring>

#define MAX 5000

int arr[MAX + 1];

int main() {
    int counter[16];
    char buf[8];
    int n, m, chk;
    
    for (int i = 1; i <= MAX; ++i) {
        memset(counter, 0, sizeof(counter));
        chk = 1;
        
        sprintf(buf, "%d", i);
        
        for (int j = 0; buf[j] != '\0'; ++j) {
            if (++counter[buf[j] - '0'] > 1) {
                --chk;
                break;
            }
        }
        
        arr[i] = arr[i - 1] + chk;
    }
    
    while (fscanf(stdin, "%d %d", &n, &m) != EOF) {
        printf("%d\n", arr[m] - arr[n - 1]);
    }
    
    return 0;
}