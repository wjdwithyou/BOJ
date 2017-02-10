#include <iostream>

int queue[16384];

void push(int*, int);
int pop(int*);
int isEmpty(int, int);
int getFront(int);
int getBack(int);
int getSize(int, int);

int main(){
    char buf[16];
    int n, x;
    int front_idx, back_idx;
    
    front_idx = back_idx = 0;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i){
        scanf("%s", buf);
        
        switch (buf[0]){
            case 'p':
                if (buf[1] == 'u'){
                    scanf("%d", &x);
                    push(&back_idx, x);
                }
                else{
                    if (isEmpty(front_idx, back_idx)){
                        puts("-1");
                    }
                    else{
                        printf("%d\n", pop(&front_idx));
                    }
                }
                break;
            case 's':
                printf("%d\n", getSize(front_idx, back_idx));
                break;
            case 'e':
                printf("%d\n", isEmpty(front_idx, back_idx));
                break;
            case 'f':
                if (isEmpty(front_idx, back_idx)){
                    puts("-1");
                }
                else{
                    printf("%d\n", getFront(front_idx));
                }
                break;
            case 'b':
                if (isEmpty(front_idx, back_idx)){
                    puts("-1");
                }
                else{
                    printf("%d\n", getBack(back_idx));
                }
                break;
            default:
                break;
        }
    }
    
    return 0;
}

void push(int* back, int x){
    queue[(*back)++] = x;
    return;
}

int pop(int* front){
    return queue[(*front)++];
}

int isEmpty(int front, int back){
    return (front == back)? 1: 0;
}

int getFront(int front){
    return queue[front];
}

int getBack(int back){
    return queue[back - 1];
}

int getSize(int front, int back){
    return back - front;
}