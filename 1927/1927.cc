#include <iostream>

int p_queue[131072];

void enQueue(int*, int);
void deQueue(int*);

int main(void) {
	int n, x;
	int size = 1;
    
	scanf("%d", &n);
    
	for (int i = 0; i < n; ++i) {
		scanf("%d", &x);
		(x) ? enQueue(&size, x) : deQueue(&size);
	}
    
	return 0;
}

void enQueue(int* size, int x) {
	int temp;
	int cur = (*size)++;
    
	for (p_queue[cur] = x; cur > 1 && p_queue[cur] < p_queue[cur >> 1]; cur >>= 1) {
		temp = p_queue[cur];
		p_queue[cur] = p_queue[cur >> 1];
		p_queue[cur >> 1] = temp;
	}
    
	return;
}

void deQueue(int* size) {
	if (*size <= 1) {
		puts("0");
		return;
	}
    
	int temp, next;
	int cur = 1;
    
	printf("%d\n", p_queue[cur]);
    
	for (p_queue[cur] = p_queue[--(*size)]; (cur << 1) < *size; cur = next) {
		next = (cur << 1) + ((cur << 1) < *size - 1 && p_queue[cur << 1] > p_queue[(cur << 1) + 1]);
        
		if (p_queue[cur] > p_queue[next]) {
			temp = p_queue[cur];
			p_queue[cur] = p_queue[next];
			p_queue[next] = temp;
		}
	}
    
	return;
}