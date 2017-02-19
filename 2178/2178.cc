#include <iostream>

#pragma warning (disable:4996)

typedef struct Point {
	int x;
	int y;
}Point;

typedef struct Queue {
	Point point;
	int depth;
}Queue;

Queue queue[16384];
char maze[128][128];

int bfs(int*, int*, Point);

int main() {
	Point finish;
	int n, m;
	int front = 0, back = 0;
    
	scanf("%d %d", &n, &m);
    
	finish = { m - 1, n - 1 };
    
	for (int i = 0; i < n; ++i) {
		scanf("%s", maze[i]);
	}
    
	queue[back++] = { { 0, 0 }, 1 };
	--maze[0][0];
    
	printf("%d", bfs(&front, &back, finish));
	return 0;
}

int bfs(int* front, int* back, Point f) {
	int o_back = *back;
    
	while (*front < o_back) {
		Queue temp = queue[(*front)++];
        
		if (temp.point.x == f.x && temp.point.y == f.y) {
			return temp.depth;
		}
        
		if (temp.point.y != f.y && maze[temp.point.y + 1][temp.point.x] == '1') {
			queue[(*back)++] = { temp.point.x, temp.point.y + 1, temp.depth + 1 };
			--maze[temp.point.y + 1][temp.point.x];
		}
		if (temp.point.x != f.x && maze[temp.point.y][temp.point.x + 1] == '1') {
			queue[(*back)++] = { temp.point.x + 1, temp.point.y, temp.depth + 1 };
			--maze[temp.point.y][temp.point.x + 1];
		}
		if (temp.point.y != 0 && maze[temp.point.y - 1][temp.point.x] == '1') {
			queue[(*back)++] = { temp.point.x, temp.point.y - 1, temp.depth + 1 };
			--maze[temp.point.y - 1][temp.point.x];
		}
		if (temp.point.x != 0 && maze[temp.point.y][temp.point.x - 1] == '1') {
			queue[(*back)++] = { temp.point.x - 1, temp.point.y, temp.depth + 1 };
			--maze[temp.point.y][temp.point.x - 1];
		}
	}
    
	return bfs(front, back, f);
}