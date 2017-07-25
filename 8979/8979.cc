#include <iostream>

struct Nation {
    int num;
    int gold;
    int silver;
    int bronze;
    int rank;
};

Nation arr[1024];

int main() {
    int n, k;
    
    scanf("%d %d", &n, &k);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d %d %d", &arr[i].num, &arr[i].gold, &arr[i].silver, &arr[i].bronze);
        
        arr[i].rank = 1;
        
        for (int j = 0; j < i; ++j) {
            if (arr[j].gold > arr[i].gold\
                || arr[j].gold == arr[i].gold && arr[j].silver > arr[i].silver\
                || arr[j].gold == arr[i].gold && arr[j].silver == arr[i].silver && arr[j].bronze > arr[i].bronze) {
                ++arr[i].rank;
            } else if (arr[j].gold < arr[i].gold\
                || arr[j].gold == arr[i].gold && arr[j].silver < arr[i].silver\
                || arr[j].gold == arr[i].gold && arr[j].silver == arr[i].silver && arr[j].bronze < arr[i].bronze) {
                ++arr[j].rank;
            }
        }
    }
    
    for (int i = 0; i < n; ++i) {
        if (arr[i].num == k) {
            printf("%d", arr[i].rank);
            break;
        }
    }
    
    return 0;
}