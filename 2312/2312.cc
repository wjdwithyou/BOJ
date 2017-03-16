#include <iostream>

#define MAX 100000

typedef struct Node {
	int num;
	int cnt;
	Node* prev;
	Node* next;
}Node;

int main() {
	Node** arr = static_cast<Node**>(malloc(sizeof(Node*) * (MAX + 1)));
	Node* temp;
	int t, n;
    
	for (int i = 2; i <= MAX; ++i) {
		arr[i] = static_cast<Node*>(malloc(sizeof(Node)));
        arr[i]->num = i;
		arr[i]->prev = arr[i]->next = arr[i];
	}
    
	for (int i = 2; i <= MAX; ++i) {
		if (arr[i]->num == 1) {
			continue;
		}
        
        for (int j = i; j <= MAX; j += i) {
            temp = static_cast<Node*>(malloc(sizeof(Node)));
            
            temp->num = i;
            temp->cnt = 0;
            
            while (!(arr[j]->num % i)) {
                ++temp->cnt;
                arr[j]->num /= i;
            }
            
            temp->prev = arr[j]->prev;
			arr[j]->prev = temp;
			temp->prev->next = temp;
			temp->next = arr[j];
        }
	}
    
	scanf("%d", &t);
    
	for (int i = 0; i < t; ++i) {
		scanf("%d", &n);
        
		for (Node* cur = arr[n]->next; cur != arr[n]; cur = cur->next) {
			printf("%d %d\n", cur->num, cur->cnt);
		}
	}
    
	for (int i = 2; i <= MAX; ++i) {
		while ((temp = arr[i]->next) != arr[i]) {
			arr[i]->next = temp->next;
			temp->next->prev = arr[i];
			free(temp);
		}
        
		free(arr[i]);
	}
    
	free(arr);
	return 0;
}