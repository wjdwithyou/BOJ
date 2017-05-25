#include <iostream>

typedef struct Location {
    int x;
    int y;
    int dir;
    int dis;
}Location;

Location store[128];

void setLocation(int, int, int, int, Location*);

int main() {
    Location person;
    int w, h, n, dir, dis, ts;
    int sum = 0;
    
    scanf("%d %d %d", &w, &h, &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%d %d", &dir, &dis);
        setLocation(w, h, dir, dis, &store[i]);
    }
    
    scanf("%d %d", &dir, &dis);
    setLocation(w, h, dir, dis, &person);
    
    for (int i = 0; i < n; ++i) {
        if (store[i].dir == person.dir) {
            sum += abs(store[i].dis - person.dis);
            continue;
        }
        
        if (person.dir == 1 && store[i].dir == 2 || person.dir == 2 && store[i].dir == 1) {
            ts = store[i].x + person.x;
            sum += h + ((ts < w) ? ts : (w << 1) - ts);
        } else if (person.dir == 3 && store[i].dir == 4 || person.dir == 4 && store[i].dir == 3) {
            ts = store[i].y + person.y;
            sum += w + ((ts < h) ? ts : (h << 1) - ts);
        } else {
            sum += abs(store[i].x - person.x) + abs(store[i].y - person.y);
        }
    }
    
    return !printf("%d", sum);
}

void setLocation(int w, int h, int dir, int dis, Location* loc) {
    if (dir == 1) {
        *loc = { dis, 0, dir, dis };
    } else if (dir == 2) {
        *loc = { dis, h, dir, dis };
    } else if (dir == 3) {
        *loc = { 0, dis, dir, dis };
    } else if (dir == 4) {
        *loc = { w, dis, dir, dis };
    }
    
    return;
}