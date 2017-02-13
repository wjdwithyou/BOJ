#include <iostream>

typedef struct Node {
	int n;
	Node* next;
}Node;

int getClusterSize(char[][32], int, int, int);

int main() {
	char map[32][32];
	Node *head, *temp;
	int n;
    int cnt = 0;

	head = static_cast<Node*>(malloc(sizeof(Node)));
	head->next = NULL;

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%s", map[i]);
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (map[i][j] != '0') {
				temp = static_cast<Node*>(malloc(sizeof(Node)));
				temp->n = getClusterSize(map, n, i, j);

				for (Node* cur = head;; cur = cur->next) {
					if (cur->next == NULL || cur->next->n > temp->n) {
						temp->next = cur->next;
						cur->next = temp;
						break;
					}
				}
                
                ++cnt;
			}
		}
	}
    
    printf("%d\n", cnt);

	while (head->next != NULL) {
		temp = head->next;

		printf("%d\n", temp->n);

		head->next = temp->next;
		free(temp);
	}

	free(head);
	return 0;
}

int getClusterSize(char map[][32], int n, int i, int j) {
    int cnt = 1;
    
	map[i][j] = '0';
    
	if (i != n - 1 && map[i + 1][j] != '0') {
		cnt += getClusterSize(map, n, i + 1, j);
	}
	if (j != n - 1 && map[i][j + 1] != '0') {
		cnt += getClusterSize(map, n, i, j + 1);
	}
	if (i != 0 && map[i - 1][j] != '0') {
		cnt += getClusterSize(map, n, i - 1, j);
	}
	if (j != 0 && map[i][j - 1] != '0') {
		cnt += getClusterSize(map, n, i, j - 1);
	}

	return cnt;
}