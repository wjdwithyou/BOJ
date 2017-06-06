#include <iostream>

#define MAX 100000

int queue[131072], chk[131072];

int bfs(int*, int*, int, int, int, int);

int main() {
	int a, b, n, m;
	int front = 0, back = 0;
    
	scanf("%d %d %d %d", &a, &b, &n, &m);
    
	queue[back++] = n;
	++chk[n];
    
	return !printf("%d", bfs(&front, &back, a, b, m, 0));
}

int bfs(int* front, int* back, int a, int b, int f, int d) {
	int o_back = *back;
	int temp;
    
	while (*front < o_back) {
		temp = queue[(*front)++];
        
		if (temp == f) {
			return d;
		}
        
		if (temp * a <= MAX && !chk[temp * a]) {
			queue[(*back)++] = temp * a;
			++chk[temp * a];
		}
		if (temp * b <= MAX && !chk[temp * b]) {
			queue[(*back)++] = temp * b;
			++chk[temp * b];
		}
		if (temp + a <= MAX && !chk[temp + a]) {
			queue[(*back)++] = temp + a;
			++chk[temp + a];
		}
		if (temp + b <= MAX && !chk[temp + b]) {
			queue[(*back)++] = temp + b;
			++chk[temp + b];
		}
		if (temp >= a && !chk[temp - a]) {
			queue[(*back)++] = temp - a;
			++chk[temp - a];
		}
		if (temp >= b && !chk[temp - b]) {
			queue[(*back)++] = temp - b;
			++chk[temp - b];
		}
		if (temp < MAX && !chk[temp + 1]) {
			queue[(*back)++] = temp + 1;
			++chk[temp + 1];
		}
		if (temp > 0 && !chk[temp - 1]) {
			queue[(*back)++] = temp - 1;
			++chk[temp - 1];
		}
	}
    
	return bfs(front, back, a, b, f, ++d);
}