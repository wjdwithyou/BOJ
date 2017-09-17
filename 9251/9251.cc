#include <iostream>
#include <cstring>

int arr[1024][1024];
char a[1024], b[1024];

int main() {
    int la, lb;
    
    scanf("%s %s", a, b);
    
    la = strlen(a);
    lb = strlen(b);
    
    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            arr[i][j] = (a[i - 1] == b[j - 1])
                ? arr[i - 1][j - 1] + 1
                : ((arr[i - 1][j] > arr[i][j - 1])
                    ? arr[i - 1][j]
                    : arr[i][j - 1]);
        }
    }
    
    return !printf("%d", arr[la][lb]);
}