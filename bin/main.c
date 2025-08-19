#include <stdio.h>
#include <stdlib.h>
#include <safeclib/safe_str_lib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createNode(int data) {
	Node* newNode =  (Node*)malloc(sizeof(Node));
	if (newNode == NULL) {
		printf("内存分配失败\n");
		exit(1);
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

void freeList(Node* head) {
	Node* temp;
	while (head != NULL) {
		temp = head;
		head = head->next;
		free(temp);
	}
}

Node* pushFront(Node* head,int data) {
	Node* newNode = createNode(data);
	newNode->next = head;
	return newNode;
}

Node* pushBack(Node* head,int data) {
	Node* newNode = createNode(data);
	if (head == NULL) return newNode;
	Node* temp;
	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newNode;
	return head;
}

Node* insertNode(Node* node,int data) {
	Node* newNode = createNode(data);
	if (node == NULL) return newNode;
	newNode->next = node->next;
	node->next = newNode;
	return newNode;
}

Node* deleteNode(Node* head,int data) {
	if (head == NULL) {
		printf("error:null!");
		exit(1);
	}
	Node* current = head;
	Node* temp = NULL;
	if (head->data == data) {
		head = head->next;
		free(current);
		return head;
	}
	while (current->next != NULL && current->next->data != data) {
		current = current->next;
	}
	if (current->next->next == NULL) {
		temp = current->next;
		current->next = NULL;
		free(temp);return head;
	}
	else{
		temp = current->next;
		current->next = current->next->next;
		free(temp);return head;
	}
}

void printList(Node* head) {
	Node* current = head;
	while (current != NULL) {
		printf("%d\n",current->data);
		current = current->next;
	}
}


int main(){
	Node* head = NULL;
	head = createNode(0);
	head = pushFront(head,10);
	head = pushBack(head,20);
	printList(head);
	Node* current = head->next;
	insertNode(head,15);
	printList(head);
	deleteNode(head,15);
	printList(head);
	freeList(head);
	return 0;
}
