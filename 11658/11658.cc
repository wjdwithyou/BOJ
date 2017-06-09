#include <iostream>

#define MAX 1024

int arr[MAX + 1][MAX + 1], fw[MAX + 1][MAX + 1];

int main() {
	int n, m, w, x, y, c, x1, y1, x2, y2, s;
    
	scanf("%d %d", &n, &m);
    
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			scanf("%d", &arr[i][j]);
            
			for (int k = (j & -j) - 1; k >= 0; --k) {
				fw[i][j] += arr[i][j - k];
			}
		}
	}
    
	for (int i = 0; i < m; ++i) {
		scanf("%d", &w);
        
		if (w) {
			s = 0;
            
			scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
            
			--x1;
            
			for (int a = y1; a <= y2; ++a) {
				for (int b = x2; b; b -= (b & -b)) {
					s += fw[a][b];
				}
				for (int b = x1; b; b -= (b & -b)) {
					s -= fw[a][b];
				}
			}
            
			printf("%d\n", s);
		}
		else {
			scanf("%d %d %d", &y, &x, &c);
            
			c -= arr[y][x];
			arr[y][x] += c;
            
			for (; x <= n; x += (x & -x)) {
				fw[y][x] += c;
			}
		}
	}
    
	return 0;
}