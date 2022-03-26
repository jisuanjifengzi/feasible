#include<iostream>
#include<stdio.h>
using namespace std;
typedef struct Node {
	int data;
	struct Node* next;
} Node;
Node* initList() {
	Node* L = (Node*)malloc(sizeof(Node));
	L->data = 0;
	L->next = NULL;
	return L;
}
void headInsert(Node* L, int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->next = L->next;
	L->next = node;
	L->data++;
}
int printList(Node* L) {
	Node* node = L->next;
	int i = 0;
	while (node) {
		cout <<"结点值有:" <<node->data << " ";
		node = node->next;
		i++;
	}
	cout << "一共" << i << "个" << endl;
	cout << endl;
	return i;
}
void find(Node* L1, Node* M1,int min,int max)
{
	Node* intersect = initList();
	Node* T = M1;
	for(int i=0;i<min;i++)
	{
		for (int b = 0; b < max; b++)
		{
         if(L1->data==M1->data)
	    {
		headInsert(intersect, L1->data);
		M1 = M1->next;
	    } 
		 else
		 {
			 M1 = M1->next;
		 }
	    }
		L1 = L1->next;
		M1 = T;
	}
	printList(intersect);
}
int main() {
	Node* L = initList();
	Node* M = initList();
	for (int i = 1; i < 10; i++)
	{
	headInsert(L, i);
	
	}
	for (int b = 2; b < 10;)
	{
		b = b + 2;
		headInsert(M, b);
	}
	int num1=printList(L);
	 int num2=printList(M);	
	 if (num1 < num2)
	 {
       find(L, M,num1,num2);
	 }
	 else {
		 find(M, L,num2,num1);
	 }
}