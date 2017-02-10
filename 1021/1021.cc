#include <iostream>

typedef struct Node {
	int num;
	Node* prev;
	Node* next;
}Node;

void swapNode(Node*, Node*, int*);
void popFront(Node*, int*);
int getFront(Node*);

int main() {
	Node* head = (Node*)malloc(sizeof(Node));
	int cnt = 0;
	int n, m, t;

	head->prev = head->next = head;

	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; ++i) {
		Node* temp = (Node*)malloc(sizeof(Node));

		temp->num = i;

		temp->prev = head->prev;
		head->prev = temp;
		temp->prev->next = temp;
		temp->next = head;
	}

	for (int i = 0; i < m; ++i) {
		Node* temp = head->next;
		bool chk = false;

		scanf("%d", &t);

		if (getFront(head) == t) {
			popFront(head, &n);
			continue;
		}

		for (int j = n >> 1; j > 0; --j) {
			temp = temp->next;

			if (temp->num == t) {
				chk = true;
				break;
			}
		}

		while (true) {
			if (chk) {
				swapNode(head, head->next, &cnt);
			}
			else {
				swapNode(head->prev, head, &cnt);
			}

			if (getFront(head) == t) {
				popFront(head, &n);
				break;
			}
		}
	}

	printf("%d", cnt);

	while (n) {
		popFront(head, &n);
	}

	free(head);
	return 0;
}

void swapNode(Node* left, Node* right, int* cnt) {
	left->next = right->next;
	right->next->prev = left;
	right->prev = left->prev;
	left->prev->next = right;
	right->next = left;
	left->prev = right;

	++(*cnt);
	return;
}

void popFront(Node* head, int* n) {
	Node* temp = head->next;

	head->next = temp->next;
	temp->next->prev = head;
	free(temp);

	--(*n);
	return;
}

int getFront(Node* head) {
	return head->next->num;
}