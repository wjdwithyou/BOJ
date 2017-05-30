#include <iostream>

typedef struct Location {
    int x;
    int y;
}Location;

int arr[1024][1024];
char result[1048576];

void setMin(int, int, Location*);

int main() {
    int idx = 0;
    int r, c;
    char d;
    
    scanf("%d %d", &r, &c);
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            scanf("%d", &arr[i][j]);
        }
    }
    
    if ((r & 1) || (c & 1)) {
        if (r & 1) {
            for (int i = 0; i < r; ++i) {
                d = (i & 1) ? 'L' : 'R';
                
                for (int j = 0; j < c - 1; ++j) {
                    result[idx++] = d;
                }
                
                result[idx++] = 'D';
            }
        } else {
            for (int j = 0; j < c; ++j) {
                d = (j & 1) ? 'U' : 'D';
                
                for (int i = 0; i < r - 1; ++i) {
                    result[idx++] = d;
                }
                
                result[idx++] = 'R';
            }
        }
        
        result[--idx] = '\0';
        return !printf("%s", result);
    }
    
    Location cur = { 0, 0 };
    Location min;
    
    setMin(r, c, &min);
    
    for (; cur.y < min.y - 1; ++cur.y) {
        if (cur.y & 1) {
            for (; cur.x > 0; --cur.x) {
                result[idx++] = 'L';
            }
        } else {
            for (; cur.x < c - 1; ++cur.x) {
                result[idx++] = 'R';
            }
        }
        result[idx++] = 'D';
    }
    
    if (cur.x) {
        for (; cur.x > min.x; --cur.x) {
            if (cur.x & 1) {
                for (; cur.y < min.y; ++cur.y) {
                    result[idx++] = 'D';
                }
            } else {
                for (; cur.y >= min.y; --cur.y) {
                    result[idx++] = 'U';
                }
            }
            result[idx++] = 'L';
        }
        
        result[idx++] = 'L';
        
        for (--cur.x; cur.x >= 0; --cur.x) {
            if (cur.x & 1) {
                for (; cur.y >= min.y; --cur.y) {
                    result[idx++] = 'U';
                }
            } else {
                for (; cur.y < min.y; ++cur.y) {
                    result[idx++] = 'D';
                }
            }
            result[idx++] = 'L';
        }
        
        ++cur.x;
    } else {
        for (; cur.x < min.x; ++cur.x) {
            if (cur.x & 1) {
                for (; cur.y >= min.y + (!min.y); --cur.y) {
                    result[idx++] = 'U';
                }
            } else {
                for (; cur.y < min.y + (!min.y); ++cur.y) {
                    result[idx++] = 'D';
                }
            }
            result[idx++] = 'R';
        }
        
        result[idx++] = 'R';
        
        for (++cur.x; cur.x < c; ++cur.x) {
            if (cur.x & 1) {
                for (; cur.y < min.y + (!min.y); ++cur.y) {
                    result[idx++] = 'D';
                }
            } else {
                for (; cur.y >= min.y + (!min.y); --cur.y) {
                    result[idx++] = 'U';
                }
            }
            result[idx++] = 'R';
        }
        
        --cur.x;
    }
    
    for (--idx; cur.y < r; ++cur.y) {
        if (cur.y & 1) {
            for (; cur.x < c - 1; ++cur.x) {
                result[idx++] = 'R';
            }
        } else {
            for (; cur.x > 0; --cur.x) {
                result[idx++] = 'L';
            }
        }
        result[idx++] = 'D';
    }
    
    result[--idx] = '\0';
    return !printf("%s", result);
}

void setMin(int r, int c, Location* min) {
    int m = 1024;
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (!((i & 1) ^ (j & 1))) {
                continue;
            }
            
            if (m > arr[i][j]) {
                m = arr[i][j];
                *min = { j, i };
            }
        }
    }
    
    return;
}