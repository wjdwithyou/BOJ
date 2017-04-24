#include <iostream>
#include <cstring>

#define MAX 100

int main() {
    int arr[128];
    char buf[64];
    char* ptr;
    int cnt, len;
    
    while (true) {
        memset(arr, 0, sizeof(arr));
        
        cnt = 0;
        
        fgets(buf, 64, stdin);
        len = strlen(buf);
        
        if (len == 3) {
            break;
        }
        
        buf[--len] = '\0';
        
        ptr = strtok(buf, " ");
        
        do {
            ++arr[atoi(ptr)];
        } while (ptr = strtok(NULL, " "));
        
        for (int i = (MAX >> 1) - 1; i > 0; --i) {
            cnt += (arr[i] && arr[i << 1]);
        }
        
        printf("%d\n", cnt);
    }
    
    return 0;
}