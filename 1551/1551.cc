#include <iostream>
#include <cstring>

int main() {
    char buf[256];
    int arr[32];
    char* ptr;
    int n, k;
    int idx = 0;
    
    scanf("%d %d", &n, &k);
    scanf("%s", buf);
    
    ptr = strtok(buf, ",");
    
    do {
        arr[idx++] = atoi(ptr);
    } while (ptr = strtok(NULL, ","));
    
    for (int i = 0; i < k; ++i, --n) {
        for (int j = 0; j < n; ++j) {
            arr[j] = arr[j + 1] - arr[j];
        }
    }
    
    printf("%d", arr[0]);
    
    for (int i = 1; i < n; ++i) {
        printf(",%d", arr[i]);
    }
    
    return 0;
}