#include <iostream>
#include <cstring>

struct Book {
    char name[64];
    int cnt;
};

Book arr[1024];

int main() {
    char buf[64];
    Book* max = &arr[0];
    int n;
    int k = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s", buf);
        
        for (int j = 0;; ++j) {
            if (!arr[j].cnt) {
                strcpy(arr[j].name, buf);
                arr[j].cnt = 1;
                ++k;
                break;
            } else if (!strcmp(arr[j].name, buf)) {
                ++arr[j].cnt;
                break;
            }
        }
    }
    
    for (int i = 1; i < k; ++i) {
        if (max->cnt < arr[i].cnt || max->cnt == arr[i].cnt && strcmp(max->name, arr[i].name) > 0) {
            max = &arr[i];
        }
    }
    
    return !printf("%s", max->name);
}