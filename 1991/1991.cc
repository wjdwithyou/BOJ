#include <iostream>

typedef struct Node {
    char c;
    Node* left;
    Node* right;
}Node;

void preorder(Node*);
void inorder(Node*);
void postorder(Node*);

int main() {
    Node** alpha;
    int n;
    char curr, left, right;
    
    scanf("%d", &n);
    
    alpha = static_cast<Node**>(malloc(sizeof(Node*) * n));
    
    for (int i = 0; i < n; ++i) {
        alpha[i] = static_cast<Node*>(malloc(sizeof(Node)));
        alpha[i]->c = i + 'A';
    }
    
    for (int i = 0; i < n; ++i) {
        while (getchar() != '\n');
        scanf("%c %c %c", &curr, &left, &right);
        
        alpha[curr - 'A']->left = (left != '.') ? alpha[left - 'A'] : NULL;
        alpha[curr - 'A']->right = (right != '.') ? alpha[right - 'A'] : NULL;
    }
    
    preorder(alpha[0]);
    puts("");
    inorder(alpha[0]);
    puts("");
    postorder(alpha[0]);
    
    for (int i = 0; i < n; ++i) {
        free(alpha[i]);
    }
    
    free(alpha);
    return 0;
}

void preorder(Node* curr) {
    if (curr) {
        printf("%c", curr->c);
        preorder(curr->left);
        preorder(curr->right);
    }
    
    return;
}

void inorder(Node* curr) {
    if (curr) {
        inorder(curr->left);
        printf("%c", curr->c);
        inorder(curr->right);
    }
    
    return;
}

void postorder(Node* curr) {
    if (curr) {
        postorder(curr->left);
        postorder(curr->right);
        printf("%c", curr->c);
    }
    
    return;
}