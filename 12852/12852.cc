#include <iostream>

typedef struct Node {
    int cnt;
    int prev;
}Node;

Node arr[1048576];
int queue[1048576];
int stack[1048576];

int bfs(int*, int*);

int main() {
	int n;
	int front = 0, back = 0, idx = 0;
    
	scanf("%d", &n);
	queue[back++] = n;
    arr[n] = { 0, 0 };
    
	printf("%d\n", bfs(&front, &back));
    
    for (int i = 1;; i = arr[i].prev) {
        stack[idx++] = i;
        
        if (i == n) {
            break;
        }
    }
    
    while (idx) {
        printf("%d ", stack[--idx]);
    }
    
	return 0;
}

int bfs(int* front, int* back) {
	int n = queue[(*front)++];
    
	if (!(n % 3) && !arr[n / 3].cnt) {
		queue[(*back)++] = n / 3;
        arr[n / 3] = { arr[n].cnt + 1, n };
	}
	if (!(n & 1) && !arr[n >> 1].cnt) {
		queue[(*back)++] = n >> 1;
		arr[n >> 1] = { arr[n].cnt + 1, n };
	}
	if (!arr[n - 1].cnt) {
		queue[(*back)++] = n - 1;
		arr[n - 1] = { arr[n].cnt + 1, n };
	}

	return (arr[1].cnt != 0) ? arr[1].cnt : bfs(front, back);
}