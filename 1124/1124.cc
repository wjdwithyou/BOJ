#include <iostream>

typedef struct Node {
    int remain;
    int cnt;
}Node;

Node arr[131072];

int main() {
	int a, b;
	int cnt = 0;
    
	scanf("%d %d", &a, &b);
    
    arr[0].cnt = arr[1].cnt = 1;
    
    for (int i = 2; i <= b; ++i) {
        arr[i].remain = i;
        arr[i].cnt = 0;
    }
    
    for (int i = 2; i <= (b >> 1); ++i) {
        if (arr[i].remain != 1) {
            for (int j = 2 * i; j <= b; j += i) {
                while (!(arr[j].remain % i)) {
                    arr[j].remain /= i;
                    ++arr[j].cnt;
                }
            }
        }
    }
    
    for (int i = a; i <= b; ++i) {
        if (!arr[arr[i].cnt].cnt) {
            ++cnt;
        }
    }
    
	printf("%d", cnt);
	return 0;
}