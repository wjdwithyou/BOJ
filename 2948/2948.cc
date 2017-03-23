#include <iostream>

int main() {
    char dayList[8][16] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
    int dateList[16] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    int d, m, day;
    
    scanf("%d %d", &d, &m);
    
    day = d + 2;
    
    for (int i = 1; i < m; ++i) {
        day += dateList[i];
    }
    
    printf("%s", dayList[day % 7]);
    return 0;
}