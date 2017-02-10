#include <iostream>

int vertex[1024][1024] = { 0, };
int dchk[1024] = { 0, };
int bchk[1024] = { 0, };
int queue[1024];

void DFS(int, int);
void BFS(int, int*, int*);

int main() {
	int n, m, v, a, b;
	int front, back;

	front = back = 0;

	scanf("%d %d %d", &n, &m, &v);

	for (int i = 0; i < m; ++i) {
		scanf("%d %d", &a, &b);
		vertex[a][b] = vertex[b][a] = 1;
	}

	queue[back++] = v;
	++bchk[v];

	DFS(n, v);
	printf("\n");
	BFS(n, &front, &back);

	return 0;
}

void DFS(int n, int v) {
	printf("%d ", v);

	++dchk[v];

	for (int i = 1; i <= n; ++i) {
		if (vertex[v][i] && !dchk[i]) {
			DFS(n, i);
		}
	}

	return;
}

void BFS(int n, int* front, int* back) {
	if (*front == *back) {
		return;
	}

	int temp = queue[(*front)++];

	printf("%d ", temp);

	for (int i = 1; i <= n; ++i) {
		if (vertex[temp][i] && !bchk[i]) {
			queue[(*back)++] = i;
			++bchk[i];
		}
	}

	BFS(n, front, back);
	return;
}