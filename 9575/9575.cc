#include <iostream>

typedef struct Node {
    int num;
    Node* next;
}Node;

void insertNode(Node*, int);

int main() {
    char buf[8];
    Node* node[4];
    Node* temp;
    int t, n, e, sum, chk, cnt;
    Node* lucky = static_cast<Node*>(malloc(sizeof(Node)));
    
    lucky->next = NULL;
    
    for (int j = 0; j < 3; ++j) {
        node[j] = static_cast<Node*>(malloc(sizeof(Node)));
        node[j]->next = NULL;
    }
    
    scanf("%d", &t);
    
    for (int i = 0; i < t; ++i) {
        cnt = 0;
        
        for (int j = 0; j < 3; ++j) {
            scanf("%d", &n);
            
            for (int k = 0; k < n; ++k) {
                scanf("%d", &e);
                
                for (Node* cur = node[j];; cur = cur->next) {
                    if (!cur->next || cur->next->num > e) {
                        insertNode(cur, e);
                        break;
                    } else if (cur->next->num == e) {
                        break;
                    } else;
                }
            }
        }
        
        for (Node* acur = node[0]->next; acur; acur = acur->next) {
            for (Node* bcur = node[1]->next; bcur; bcur = bcur->next) {
                for (Node* ccur = node[2]->next; ccur; ccur = ccur->next) {
                    chk = 1;
                    sum = acur->num + bcur->num + ccur->num;
                    
                    sprintf(buf, "%d", sum);
                    
                    for (int c = 0; buf[c] != '\0'; ++c) {
                        if (buf[c] != '5' && buf[c] != '8') {
                            --chk;
                            break;
                        }
                    }
                    
                    if (chk) {
                        for (Node* cur = lucky;; cur = cur->next) {
                            if (!cur->next || cur->next->num > sum) {
                                insertNode(cur, sum);
                                ++cnt;
                                break;
                            } else if (cur->next->num == sum) {
                                break;
                            } else;
                        }
                    }
                }
            }
        }
        
        printf("%d\n", cnt);
        
        for (int j = 0; j < 3; ++j) {
            while (temp = node[j]->next) {
                node[j]->next = temp->next;
                free(temp);
            }
        }
        
        while (temp = lucky->next) {
            lucky->next = temp->next;
            free(temp);
        }
    }
    
    for (int j = 0; j < 3; ++j) {
        free(node[j]);
    }
    
    free(lucky);
    return 0;
}

void insertNode(Node* cur, int num) {
    Node* temp = static_cast<Node*>(malloc(sizeof(Node)));
    
    temp->num = num;
    
    temp->next = cur->next;
    cur->next = temp;
    
    return;
}