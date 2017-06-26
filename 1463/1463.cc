#include <iostream>

int arr[1048576];
int queue[1048576];

int bfs(int*, int*);

int main() {
	int n;
	int front = 0, back = 0;
    
	scanf("%d", &n);
    
	queue[back++] = n;
	arr[n] = 0;
    
	return !printf("%d", (n == 1) ? 0 : bfs(&front, &back));
}

int bfs(int* front, int* back) {
	int o_back = *back;
    
	while (*front < o_back) {
		int n = queue[(*front)++];
        
		if (n % 3 == 0 && arr[n / 3] == 0) {
			queue[(*back)++] = n / 3;
			arr[n / 3] = arr[n] + 1;
		}
		if ((n & 1) == 0 && arr[n >> 1] == 0) {
			queue[(*back)++] = n >> 1;
			arr[n >> 1] = arr[n] + 1;
		}
		if (arr[n - 1] == 0) {
			queue[(*back)++] = n - 1;
			arr[n - 1] = arr[n] + 1;
		}
	}
    
	return (arr[1] != 0) ? arr[1] : bfs(front, back);
}