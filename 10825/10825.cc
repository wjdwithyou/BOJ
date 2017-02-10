#include <iostream>
#include <cstring>

typedef struct Node {
    char name[16];
    Node* next;
}Node;

Node* score[128][128][128];

int main() {
    char buf[16];
    int n, k, e, m;
    
    for (int i = 1; i <= 100; ++i) {
        for (int j = 1; j <= 100; ++j) {
            for (int k = 1; k <= 100; ++k) {
                score[i][j][k] = static_cast<Node*>(malloc(sizeof(Node)));
                score[i][j][k]->next = NULL;
            }
        }
    }
    
    scanf("%d", &n);
    
    for (int i = 0; i < n; ++i) {
        scanf("%s %d %d %d", buf, &k, &e, &m);
        
        for (Node* cur = score[k][e][m];; cur = cur->next) {
            if (cur->next == NULL || strcmp(buf, cur->next->name) < 0) {
                Node* temp = static_cast<Node*>(malloc(sizeof(Node)));
                
                strcpy(temp->name, buf);
                
                temp->next = cur->next;
                cur->next = temp;
                break;
            }
        }
    }
    
    for (int i = 100; i >= 1; --i) {
        for (int j = 1; j <= 100; ++j) {
            for (int k = 100; k >= 1; --k) {
                Node* head = score[i][j][k];
                
                while (head->next != NULL) {
                    Node* cur = head->next;
                    
                    puts(cur->name);
                    
                    head->next = cur->next;
                    free(cur);
                }
                
                free(head);
            }
        }
    }
    
    return 0;
}