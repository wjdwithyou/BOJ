#include <iostream>
#include <ctime>

#define MAX_NUM 9

int main() {
    int height[16];
    int min_idx, e1, e2;
    int all = 0;
    
    srand(static_cast<unsigned>(time(NULL)));
    
    for (int i = 0; i < MAX_NUM; ++i) {
        scanf("%d", &height[i]);
        all += height[i];
    }
    
    for (int i = 0; i < MAX_NUM; ++i) {
        min_idx = i;
        
        for (int j = i + 1; j < MAX_NUM; ++j) {
            if (height[min_idx] > height[j]) {
                min_idx = j;
            }
        }
        
        int temp = height[i];
        height[i] = height[min_idx];
        height[min_idx] = temp;
    }
    
    do {
        e1 = rand() % MAX_NUM;
        
        do {
            e2 = rand() % MAX_NUM;
        } while (e1 == e2);
    } while (height[e1] + height[e2] != all - 100);
    
    for (int i = 0; i < MAX_NUM; ++i) {
        if (i == e1 || i == e2) {
            continue;
        }
        
        printf("%d\n", height[i]);
    }
    
    return 0;
}