#include <iostream>
#include <cstring>

int arr[512][512], temp[512][512];

void getBoundary(int[], int[], int*, int*, int*, int*);
void dfs(int, int, int, int, int, int);

int main() {
    int srow[512] = { 0, };
    int scol[512] = { 0, };
    int n, m, n0, er, ec, chk;
    int br = 1, bc = 1;
    
    scanf("%d %d", &n, &m);
    
    br = bc = 1;
    er = n - 2;
    ec = m - 2;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            scanf("%d", &arr[i][j]);
            
            srow[i] += arr[i][j];
            scol[j] += arr[i][j];
        }
    }
    
    getBoundary(srow, scol, &br, &er, &bc, &ec);
    
    for (int k = 1;; ++k) {
        chk = 0;
        
        for (int i = br; i <= er; ++i) {
            for (int j = bc; j <= ec; ++j) {
                if (!arr[i][j]) {
                    continue;
                }
                
                n0 = 0;
                
                n0 += !arr[i + 1][j];
                n0 += !arr[i][j + 1];
                n0 += !arr[i - 1][j];
                n0 += !arr[i][j - 1];
                
                temp[i][j] = arr[i][j] - n0;
                
                if (temp[i][j] < 0) {
                    temp[i][j] = 0;
                }
            }
        }
        
        memset(srow, 0, sizeof(srow));
        memset(scol, 0, sizeof(scol));
        
        for (int i = br; i <= er; ++i) {
            for (int j = bc; j <= ec; ++j) {
                arr[i][j] = temp[i][j];
                
                srow[i] += arr[i][j];
                scol[j] += arr[i][j];
            }
        }
        
        for (int i = br; i <= er; ++i) {
            for (int j = bc; j <= ec; ++j) {
                if (temp[i][j]) {
                    if (chk++) {
                        break;
                    } else {
                        dfs(br, er, bc, ec, i, j);
                    }
                }
            }
            
            if (chk > 1) {
                break;
            }
        }
        
        if (chk != 1) {
            printf("%d", (chk) ? k : 0);
            break;
        }
        
        getBoundary(srow, scol, &br, &er, &bc, &ec);
    }
    
    return 0;
}

void getBoundary(int srow[], int scol[], int* br, int* er, int* bc, int* ec) {
    int nbr, ner, nbc, nec;
    
    for (int i = *br; i <= *er; ++i) {
        if (srow[i]) {
            nbr = i;
            break;
        }
    }
    for (int i = *er; i >= *br; --i) {
        if (srow[i]) {
            ner = i;
            break;
        }
    }
    for (int j = *bc; j <= *ec; ++j) {
        if (scol[j]) {
            nbc = j;
            break;
        }
    }
    for (int j = *ec; j >= *bc; --j) {
        if (scol[j]) {
            nec = j;
            break;
        }
    }
    
    *br = nbr;
    *er = ner;
    *bc = nbc;
    *ec = nec;
    
    return;
}

void dfs(int br, int er, int bc, int ec, int i, int j) {
    temp[i][j] = 0;
    
    if (temp[i + 1][j]) {
        dfs(br, er, bc, ec, i + 1, j);
    }
    if (temp[i][j + 1]) {
        dfs(br, er, bc, ec, i, j + 1);
    }
    if (temp[i - 1][j]) {
        dfs(br, er, bc, ec, i - 1, j);
    }
    if (temp[i][j - 1]) {
        dfs(br, er, bc, ec, i, j - 1);
    }
    
    return;
}