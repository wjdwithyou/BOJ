#include <iostream>
#include <cstring>

char buf[8192];

int main() {
    char temp[8];
    int n, m, len;
    
    scanf("%d %d", &n, &m);
    
    sprintf(temp, "%d", n);
    len = strlen(temp);
    
    for (int i = 0; i < n * len; i += len, strcat(buf, temp));
    buf[m] = '\0';
    
    printf("%s", buf);
    return 0;
}