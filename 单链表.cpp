#include<stdio.h>
#include<iostream>
using namespace std;
#define TRUE 1;
#define FALSE 0;
typedef struct Node {
	int data;
	struct Node* next;
}Node;
Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	return L;
}
void headInsert(Node* L,int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	L->next = node;
	L->data++;
}
void tailInsert(Node* L, int data)
{
	Node* node = L;
	for (int i = 0; i < L->data; i++) {
		node = node->next;
	}
	Node* n = (Node*)malloc(sizeof(Node));
	n->data = data;
	n->next = NULL;
	node->next = n;
	L->data++;
}
int del(Node* L, int data) {
	Node* preNode = L;
	Node* node = L->next;
	while (node) {
		if (node->data == data)
		{
			preNode->next = node->next;
			free(node);
			return TRUE;
		}
		preNode = node;
		node = node->next;
	}
	return FALSE;
}
void printList(Node* L) {
	Node* node = L->next;
	while (node) {
		printf("node=%d\n", node->data);
		node = node->next;
	}
}
int main() {
	Node* L = initList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	printList(L);
	tailInsert(L, 4);
	printList(L);
	if (del(L, 10))
	{
		cout<<"success"<<endl;
	}
	else {
		cout << "fail" << endl;
	}
	del(L, 3);
		printList(L);
	return 0;
}