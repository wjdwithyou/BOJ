#include <iostream>
#include <cstring>

int arr[1024][1024];
char a[1024], b[1024], lcs[1024];

int main(void) {
    int la, lb;
    
    scanf("%s %s", &a[1], &b[1]);
    
    la = strlen(&a[1]);
    lb = strlen(&b[1]);
    
    for (int i = 1; i <= la; ++i) {
        for (int j = 1; j <= lb; ++j) {
            arr[i][j] = (a[i] == b[j])
                ? arr[i - 1][j - 1] + 1
                : ((arr[i - 1][j] > arr[i][j - 1])
                    ? arr[i - 1][j]
                    : arr[i][j - 1]);
        }
    }
    
    printf("%d\n", arr[la][lb]);
    
    lcs[arr[la][lb]] = '\0';
    
    for (int i = la, j = lb, k = arr[la][lb] - 1; k >= 0;) {
        if (a[i] == b[j]) {
            lcs[k--] = a[i];
            --i, --j;
        } else {
            (arr[i - 1][j] > arr[i][j - 1]) ? --i : --j;
        }
    }
    
    return !printf("%s", lcs);
}