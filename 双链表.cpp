#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
#define ElemType int
typedef struct DNode
{
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;
DLinkNode* initList() {
	DLinkNode* L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->data = 0;
	L->prior = L->next = NULL;
	return L;
}
void headInsert(DLinkNode* L, int data) {//Í·²å·¨
	DLinkNode* node = (DLinkNode*)malloc(sizeof(DLinkNode));
	node->data = data;
	if (L->data == 0)
	{
		node->next = L->next;
		node->prior = L;
		L->next = node;
		L->data++;
	}
	else {
		node->prior = L;
		node->next = L->next;
		L->next->prior = node;
		L->next = node;
		L->data++;
	}
}
void tailInsert(DLinkNode* L, int data) {//Î²²å·¨
	DLinkNode* node = L;
	DLinkNode* n = (DLinkNode*)malloc(sizeof(DLinkNode));
	n->data = data;
	while (node->next)
	{
		node = node->next;
	}
	n->next = node->next;
	node->next = n;
	n->prior = node;
	L->data++;
}
int del(DLinkNode* L, int data) {//É¾³ý

	DLinkNode* node = L->next;
	while (node)
	{
		if (node->data == data)
		{
			node->prior->next = node->next;
			node->next->prior = node->prior;
			free(node);
			return 1;
		}
		node = node->next;
	}
	return 0;
}
void printList(DLinkNode* L)
{
	DLinkNode* node = L->next;
	while (node) {
		printf("%d->", node->data);
		node = node->next;
	}
	printf("NULL\n");
}
void main() {
	DLinkNode* L = initList();
	headInsert(L, 1);
	headInsert(L, 2);
	headInsert(L, 3);
	headInsert(L, 4);
	printList(L);
	tailInsert(L, 5);
	tailInsert(L, 6);
	printList(L);
	del(L, 1);
	printList(L);
}