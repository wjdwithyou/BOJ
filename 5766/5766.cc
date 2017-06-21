#include <iostream>

#define MAX 10000

struct Player {
    int num;
    int cnt;
};

Player arr[MAX + 1], temp[MAX + 1];

void divide(int, int);
void merge(int, int, int);

int main() {
    int n, m, t, min, max, cnt;
    
    while (1) {
        min = MAX + 1;
        max = 0;
        
        for (int i = 1; i <= MAX; ++i) {
            arr[i] = { i, 0 };
        }
        
        scanf("%d %d", &n, &m);
        
        if (!n && !m) {
            break;
        }
        
        for (int i = n * m; i > 0; --i) {
            scanf("%d", &t);
            ++arr[t].cnt;
            
            if (min > t) {
                min = t;
            }
            if (max < t) {
                max = t;
            }
        }
        
        divide(min, max + 1);
        
        cnt = arr[min + 1].cnt;
        
        for (int i = min + 1; arr[i].cnt == cnt; ++i) {
            printf("%d ", arr[i].num);
        }
        puts("");
    }
    
    return 0;
}

void divide(int a, int b) {
    if (a + 1 == b) {
        return;
    }
    
    int m = (a + b) >> 1;
    
    divide(a, m);
    divide(m, b);
    merge(a, m, b);
    
    return;
}

void merge(int a, int m, int b) {
    int idx = a;
    int o_a = a;
    int o_m = m;
    
    while (a < o_m && m < b) {
        temp[idx++] = (arr[a].cnt == arr[m].cnt) ? ((arr[a].num < arr[m].num) ? arr[a++] : arr[m++]) : ((arr[a].cnt > arr[m].cnt) ? arr[a++] : arr[m++]);
    }
    
    while (a < o_m) {
        temp[idx++] = arr[a++];
    }
    while (m < b) {
        temp[idx++] = arr[m++];
    }
    
    for (int i = o_a; i < b; ++i) {
        arr[i] = temp[i];
    }
    
    return;
}