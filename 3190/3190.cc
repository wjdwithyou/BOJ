#include <iostream>

enum Obj{ EMPTY, SNAKE, APPLE };
enum Dir{ LEFT, RIGHT, UP, DOWN };

typedef struct Node {
    int x;
    int y;
    Node* prev;
    Node* next;
}Node;

typedef struct Snake {
    Node* head;
    int dirIdx;
}Snake;

Obj board[128][128];
char dc[16384];

void insertNode(Node*, int, int);
void deleteNode(Node*);

int main() {
    Dir dir[4] = { RIGHT, DOWN, LEFT, UP };
    Snake snake;
    int n, t, tx, ty, x;
    int time = 1;
    char c;
    
    snake.head = static_cast<Node*>(malloc(sizeof(Node)));
    snake.head->prev = snake.head->next = snake.head;
    
    snake.dirIdx = 0;
    
    insertNode(snake.head, 1, 1);
    
    scanf("%d", &n);
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %d", &ty, &tx);
        board[ty][tx] = APPLE;
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        scanf("%d %c", &x, &c);
        dc[x] = c;
    }
    
    for (;; ++time) {
        if (dir[snake.dirIdx] == LEFT) {
            tx = snake.head->next->x - 1;
            ty = snake.head->next->y;
        }
        else if (dir[snake.dirIdx] == RIGHT) {
            tx = snake.head->next->x + 1;
            ty = snake.head->next->y;
        }
        else if (dir[snake.dirIdx] == UP) {
            tx = snake.head->next->x;
            ty = snake.head->next->y - 1;
        }
        else if (dir[snake.dirIdx] == DOWN) {
            tx = snake.head->next->x;
            ty = snake.head->next->y + 1;
        }
        else;
        
        if (tx <= 0 || tx > n || ty <= 0 || ty > n || board[ty][tx] == SNAKE) {
            break;
        }
        
        if (board[ty][tx] != APPLE) {
            deleteNode(snake.head);
        }
        
        insertNode(snake.head, tx, ty);
        
        if (dc[time] != 0) {
            snake.dirIdx += (dc[time] == 'L') ? 3 : 1;
            snake.dirIdx %= 4;
        }
    }
    
    printf("%d", time);
    
    while (snake.head->prev != snake.head) {
        deleteNode(snake.head);
    }
    
    free(snake.head);
    return 0;
}

void insertNode(Node* head, int x, int y){
    Node* temp = static_cast<Node*>(malloc(sizeof(Node)));
    
    temp->x = x;
    temp->y = y;
    
    temp->next = head->next;
    head->next = temp;
    temp->next->prev = temp;
    temp->prev = head;
    
    board[temp->y][temp->x] = SNAKE;
    
    return;
}

void deleteNode(Node* head) {
    Node* temp = head->prev;
    
    board[temp->y][temp->x] = EMPTY;
    
    head->prev = temp->prev;
    temp->prev->next = head;
    free(temp);
    
    return;
}