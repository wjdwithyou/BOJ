#include <iostream>
#include <cstring>

typedef struct Node {
    char element[256];
    int num;
    Node* next;
}Node;

void insertElement(Node*, char[], int);

int main() {
    char buf[256], coef[256], element[256], num[256];
    int coef_idx, element_idx, num_idx;
    int coef_chk, tmp_num, right, cmp, balanced;
    Node* head[2];
    Node* temp;
    
    for (int i = 0; i < 2; ++i) {
        head[i] = static_cast<Node*>(malloc(sizeof(Node)));
        head[i]->next = head[i];
    }
    
    for (int k = 1;; ++k) {
        memset(coef, 0, sizeof(coef));
        memset(element, 0, sizeof(element));
        memset(num, 0, sizeof(num));
        coef_idx = element_idx = num_idx = right = 0;
        coef_chk = balanced = 1;
        
        fgets(buf, 256, stdin);
        buf[strlen(buf) - 1] = '\0';
        
        if (buf[0] == '#') {
            break;
        }
        
        for (int i = 0;; ++i) {
            if (buf[i] >= '0' && buf[i] <= '9') {
                if (coef_chk) {
                    coef[coef_idx++] = buf[i];
                }
                else {
                    num[num_idx++] = buf[i];
                }
            }
            else if (buf[i] >= 'A' && buf[i] <= 'Z') {
                if (coef_chk) {
                    --coef_chk;
                }
                
                if (element_idx) {
                    tmp_num = ((coef_idx) ? atoi(coef) : 1) * ((num_idx) ? atoi(num) : 1);
                    insertElement(head[right], element, tmp_num);
                    
                    memset(element, 0, sizeof(element));
                    memset(num, 0, sizeof(num));
                    element_idx = num_idx = 0;
                }
                
                element[element_idx++] = buf[i];
            }
            else if (buf[i] >= 'a' && buf[i] <= 'z') {
                element[element_idx++] = buf[i];
            }
            else if (buf[i] == '\0' || buf[i] == '+' || buf[i] == '=') {
                tmp_num = ((coef_idx) ? atoi(coef) : 1) * ((num_idx) ? atoi(num) : 1);
                insertElement(head[right], element, tmp_num);
                
                if (buf[i] == '\0') {
                    break;
                }
                else if (buf[i] == '=') {
                    ++right;
                }
                else;
                
                memset(coef, 0, sizeof(coef));
                memset(element, 0, sizeof(element));
                memset(num, 0, sizeof(num));
                coef_idx = element_idx = num_idx = 0;
                
                ++coef_chk;
            }
            else;
        }
        
        while (head[0]->next != head[0] || head[1]->next != head[1]) {
            if (head[0]->next == head[0]) {
                if (balanced) {
                    printf("Equation %d is unbalanced.\n", k);
                    --balanced;
                }
                
                temp = head[1]->next;
                
                printf("You have created %d %s of %s.\n", temp->num, (temp->num == 1) ? "atom" : "atoms", temp->element);
                
                head[1]->next = temp->next;
                free(temp);
            }
            else if (head[1]->next == head[1]) {
                if (balanced) {
                    printf("Equation %d is unbalanced.\n", k);
                    --balanced;
                }
                
                temp = head[0]->next;
                
                printf("You have destroyed %d %s of %s.\n", temp->num, (temp->num == 1) ? "atom" : "atoms", temp->element);
                
                head[0]->next = temp->next;
                free(temp);
            }
            else {
                cmp = strcmp(head[0]->next->element, head[1]->next->element);
                
                if (cmp == 0) {
                    cmp = head[1]->next->num - head[0]->next->num;
                    
                    if (cmp != 0) {
                        if (balanced) {
                            printf("Equation %d is unbalanced.\n", k);
                            --balanced;
                        }
                        
                        if (cmp < 0) {
                            printf("You have destroyed %d %s of %s.\n", -cmp, (-cmp == 1) ? "atom" : "atoms", head[0]->next->element);
                        }
                        else {
                            printf("You have created %d %s of %s.\n", cmp, (cmp == 1) ? "atom" : "atoms", head[1]->next->element);
                        }
                    }
                    
                    temp = head[0]->next;
                    head[0]->next = temp->next;
                    free(temp);
                    temp = head[1]->next;
                    head[1]->next = temp->next;
                    free(temp);
                }
                else {
                    if (balanced) {
                        printf("Equation %d is unbalanced.\n", k);
                        --balanced;
                    }
                    
                    if (cmp < 0) {
                        temp = head[0]->next;
                        
                        printf("You have destroyed %d %s of %s.\n", temp->num, (temp->num == 1) ? "atom" : "atoms", temp->element);
                        
                        head[0]->next = temp->next;
                        free(temp);
                    }
                    else {
                        temp = head[1]->next;
                        
                        printf("You have created %d %s of %s.\n", temp->num, (temp->num == 1) ? "atom" : "atoms", temp->element);
                        
                        head[1]->next = temp->next;
                        free(temp);
                    }
                }
            }
        }
        
        if (balanced) {
            printf("Equation %d is balanced.\n", k);
        }
        else {
            printf("\n");
        }
    }
    
    for (int i = 0; i < 2; ++i) {
        free(head[i]);
    }
    
    return 0;
}

void insertElement(Node* head, char element[], int num) {
    for (Node* cur = head;; cur = cur->next) {
        if (cur->next == head || strcmp(cur->next->element, element) > 0) {
            Node* temp = static_cast<Node*>(malloc(sizeof(Node)));
            
            strcpy(temp->element, element);
            temp->num = num;
            
            temp->next = cur->next;
            cur->next = temp;
            break;
        }
        else if (!strcmp(cur->next->element, element)) {
            cur->next->num += num;
            break;
        }
        else;
    }
    
    return;
}