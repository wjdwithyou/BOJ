#include <iostream>
#include <cstring>

int dfs(int[][32], int, int, int, int);

int main() {
    int arr[32][32];
    int n, t;
    int max = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    for (int i = 0; i < 4; ++i) {
        t = dfs(arr, n, i, 0, 1);
        
        if (max < t) {
            max = t;
        }
    }
    
    return !printf("%d", max);
}

int dfs(int prev[][32], int n, int dir, int pmax, int depth) {
    if (depth > 5) {
        return pmax;
    }
    
    int arr[32][32];
    int idx, t, rmax;
    int max = 0;
    
    memcpy(arr, prev, sizeof(arr));
    
    if (dir == 0) { 
        for (int j = 0; j < n; ++j) {
            idx = n - 1;
            
            for (int i = n - 1; i >= 0; --i) {
                if (!arr[i][j]) {
                    continue;
                }
                
                for (int k = i - 1;; --k) {
                    if (k < 0) {
                        arr[idx--][j] = arr[i][j];
                        break;
                    }
                    
                    if (!arr[k][j]) {
                        continue;
                    }
                    
                    if (arr[i][j] == arr[k][j]) {
                        arr[idx--][j] = arr[i][j] << 1;
                        i = k;
                    } else {
                        arr[idx--][j] = arr[i][j];
                    }
                    
                    break;
                }
            }
            
            while (idx >= 0) {
                arr[idx--][j] = 0;
            }
        }
    } else if (dir == 1) {
        for (int i = 0; i < n; ++i) {
            idx = n - 1;
            
            for (int j = n - 1; j >= 0; --j) {
                if (!arr[i][j]) {
                    continue;
                }
                
                for (int k = j - 1;; --k) {
                    if (k < 0) {
                        arr[i][idx--] = arr[i][j];
                        break;
                    }
                    
                    if (!arr[i][k]) {
                        continue;
                    }
                    
                    if (arr[i][j] == arr[i][k]) {
                        arr[i][idx--] = arr[i][j] << 1;
                        j = k;
                    } else {
                        arr[i][idx--] = arr[i][j];
                    }
                    
                    break;
                }
            }
            
            while (idx >= 0) {
                arr[i][idx--] = 0;
            }
        }
    } else if (dir == 2) {
        for (int j = 0; j < n; ++j) {
            idx = 0;
            
            for (int i = 0; i < n; ++i) {
                if (!arr[i][j]) {
                    continue;
                }
                
                for (int k = i + 1;; ++k) {
                    if (k >= n) {
                        arr[idx++][j] = arr[i][j];
                        break;
                    }
                    
                    if (!arr[k][j]) {
                        continue;
                    }
                    
                    if (arr[i][j] == arr[k][j]) {
                        arr[idx++][j] = arr[i][j] << 1;
                        i = k;
                    } else {
                        arr[idx++][j] = arr[i][j];
                    }
                    
                    break;
                }
            }
            
            while (idx < n) {
                arr[idx++][j] = 0;
            }
        }
    } else if (dir == 3) {
        for (int i = 0; i < n; ++i) {
            idx = 0;
            
            for (int j = 0; j < n; ++j) {
                if (!arr[i][j]) {
                    continue;
                }
                
                for (int k = j + 1;; ++k) {
                    if (k >= n) {
                        arr[i][idx++] = arr[i][j];
                        break;
                    }
                    
                    if (!arr[i][k]) {
                        continue;
                    }
                    
                    if (arr[i][j] == arr[i][k]) {
                        arr[i][idx++] = arr[i][j] << 1;
                        j = k;
                    } else {
                        arr[i][idx++] = arr[i][j];
                    }
                    
                    break;
                }
            }
            
            while (idx < n) {
                arr[i][idx++] = 0;
            }
        }
    } else;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (max < arr[i][j]) {
                max = arr[i][j];
            }
        }
    }
    
    rmax = (max > pmax) ? max : pmax;
    
    for (int i = 0; i < 4; ++i) {
        t = dfs(arr, n, i, max, depth + 1);
        
        if (rmax < t) {
            rmax = t;
        }
    }
    
    return rmax;
}