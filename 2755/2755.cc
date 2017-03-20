#include <iostream>

int main() {
    float grade[8] = { 4.0, 3.0, 2.0, 1.0, 0.0, 0.0 };
    char buf1[128], buf2[4];
    int n, t;
    int tsum = 0;
    float temp;
    float buf2sum = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %s", buf1, &t, buf2);
        
        tsum += t;
        
        temp = grade[buf2[0] - 'A'];
        
        if (buf2[1] == '+') {
            temp += 0.3f;
        } else if (buf2[1] == '-') {
            temp -= 0.3f;
        } else;
        
        buf2sum += t * temp;
    }
    
    printf("%.2f", buf2sum / tsum);
    return 0;
}