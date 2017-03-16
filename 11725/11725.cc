#include <iostream>

typedef struct Stack {
    int num;
    Stack* next;
}Stack;

typedef struct Node {
    int parent;
    Stack* link;
}Node;

Node arr[131072];

void dfs(int, int);
void insertStack(Stack*, int);

int main() {
    int n, a, b;
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        arr[i].link = static_cast<Stack*>(malloc(sizeof(Stack)));
        arr[i].link->next = NULL;
    }
    
    for (int i = 2; i <= n; ++i) {
        scanf("%d %d", &a, &b);
        
        insertStack(arr[a].link, b);
        insertStack(arr[b].link, a);
    }
    
    dfs(1, 0);
    
    for (int i = 2; i <= n; ++i) {
        printf("%d\n", arr[i].parent);
    }
    
    return 0;
}

void dfs(int idx, int prev) {
    Stack* temp;
    
    arr[idx].parent = prev;
    
    while (arr[idx].link->next != NULL) {
        temp = arr[idx].link->next;
        
        if (temp->num != prev) {
            dfs(temp->num, idx);
        }
        
        arr[idx].link->next = temp->next;
        free(temp);
    }
    
    free(arr[idx].link);
    return;
}

void insertStack(Stack* stack, int link) {
    Stack* temp = static_cast<Stack*>(malloc(sizeof(Stack)));
    
    temp->num = link;
    
    temp->next = stack->next;
    stack->next = temp;
    
    return;
}