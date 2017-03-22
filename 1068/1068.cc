#include <iostream>

typedef struct Node {
    int num;
    int nListCnt;
    Node* nList[64];
}Node;

int search(Node*[], int, int);

int main() {
    Node* tree[64];
    int n, t, k, root_idx;
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        tree[i] = static_cast<Node*>(malloc(sizeof(Node)));
        tree[i]->num = i;
        tree[i]->nListCnt = 0;
    }
    
    for (int i = 0; i < n; ++i) {
        scanf("%d", &t);
        
        if (t == -1) {
            root_idx = i;
        } else {
            tree[t]->nList[tree[t]->nListCnt++] = tree[i];
        }
    }
    
    scanf("%d", &k);
    printf("%d", search(tree, root_idx, k));
    
    for (int i = 0; i < n; ++i) {
        free(tree[i]);
    }
    
    return 0;
}

int search(Node* tree[], int idx, int k) {
    if (k == idx) {
        return 0;
    }
    
    if (!tree[idx]->nListCnt) {
        return 1;
    } else {
        int temp;
        int sum = 0;
        
        for (int i = 0; i < tree[idx]->nListCnt; ++i) {
            temp = search(tree, tree[idx]->nList[i]->num, k);
            sum += (tree[idx]->nListCnt == 1 && !temp) ? 1 : temp;
        }
        
        return sum;
    }
}