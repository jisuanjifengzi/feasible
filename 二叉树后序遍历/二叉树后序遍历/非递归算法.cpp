#include <iostream>
#include <stack>
using namespace std;
typedef char datatype;
//二叉树的左右链表示，也叫做二叉链表表示
typedef struct node {
	datatype data;
	struct node* lchild;
	struct node* rchild;
}Node;
typedef Node* Btree;

//创建新的结构体list，包含Btree和int，来帮助实现后序非递归算法
typedef struct list {
	Btree ptr;
	int flag;
}List;

Btree preCreateBT() {
	Btree T;
	char ch;
	cin >> ch;
	if (ch == '#') {
		T = NULL;
	}
	else {
		T = new node;
		T->data = ch;
		T->lchild = preCreateBT();
		T->rchild = preCreateBT();
	}
	return T;
}

//后序遍历非递归算法
void PostOrderNoRecur(Btree root) {
	stack<List> newS;
	while (root != NULL || !newS.empty()) 
	{
		while (root != NULL) {
			List element;
			element.ptr = root;
			element.flag = 1;
			newS.push(element);
			root = root->lchild;
		}
		while (!newS.empty() && newS.top().flag == 2) {
			cout << newS.top().ptr->data << endl;
			newS.pop();
		}
		if (!newS.empty()) {
			newS.top().flag = 2;
			root = newS.top().ptr->rchild;
		}
	}
}

int main() 
{
	//前序遍历创建树
	Btree TreeOne = preCreateBT();
	//后序遍历非递归算法
	PostOrderNoRecur(TreeOne);
}
//先序遍历（递归）
	//PreOrder(TreeOne);

	//中序遍历（递归）
	//InOrder(TreeOne);

	//后序遍历（递归）
	//PostOrder(TreeOne);

	//先序遍历非递归算法
	//PreOrderNoRecur(TreeOne);

	//中序遍历非递归算法
	//InOrderNoRecur(TreeOne);
//先序遍历
/*
void PreOrder(Btree BT) {
	if (BT != NULL) {
		cout << BT->data<<endl;
		PreOrder(BT->lchild);
		PreOrder(BT->rchild);
	}
}
*/

//中序遍历
/*
void InOrder(Btree BT) {
	if (BT != NULL) {
		InOrder(BT->lchild);
		cout << BT->data << endl;
		InOrder(BT->rchild);
	}
}
*/

//后序遍历
/*
void PostOrder(Btree BT) {
	if (BT != NULL) {
		PostOrder(BT->lchild);
		PostOrder(BT->rchild);
		cout << BT->data << endl;
	}
}
*/

//先序遍历非递归算法
/*
void PreOrderNoRecur(Btree root) {
	stack<Btree> S;
	while (root != NULL || !S.empty()) {
		while (root != NULL) {
			cout << root->data << endl;
			S.push(root);
			root = root->lchild;
		}

		if (!S.empty()) {
			root = S.top();
			S.pop();
			root = root->rchild;
		}
	}
}
*/

//中序遍历非递归算法
/*
void InOrderNoRecur(Btree root) {
	stack<Btree> S;
	while (root != NULL || !S.empty()) {
		while (root != NULL) {
			S.push(root);
			root = root->lchild;
		}

		if (!S.empty()) {
			root = S.top();
			cout << root->data << endl;
			S.pop();
			root = root->rchild;
		}
	}
}
*/