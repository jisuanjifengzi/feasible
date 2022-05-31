#include <iostream>
#include <stack>
using namespace std;
typedef char datatype;
//����������������ʾ��Ҳ�������������ʾ
typedef struct node {
	datatype data;
	struct node* lchild;
	struct node* rchild;
}Node;
typedef Node* Btree;

//�����µĽṹ��list������Btree��int��������ʵ�ֺ���ǵݹ��㷨
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

//��������ǵݹ��㷨
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
	//ǰ�����������
	Btree TreeOne = preCreateBT();
	//��������ǵݹ��㷨
	PostOrderNoRecur(TreeOne);
}
//����������ݹ飩
	//PreOrder(TreeOne);

	//����������ݹ飩
	//InOrder(TreeOne);

	//����������ݹ飩
	//PostOrder(TreeOne);

	//��������ǵݹ��㷨
	//PreOrderNoRecur(TreeOne);

	//��������ǵݹ��㷨
	//InOrderNoRecur(TreeOne);
//�������
/*
void PreOrder(Btree BT) {
	if (BT != NULL) {
		cout << BT->data<<endl;
		PreOrder(BT->lchild);
		PreOrder(BT->rchild);
	}
}
*/

//�������
/*
void InOrder(Btree BT) {
	if (BT != NULL) {
		InOrder(BT->lchild);
		cout << BT->data << endl;
		InOrder(BT->rchild);
	}
}
*/

//�������
/*
void PostOrder(Btree BT) {
	if (BT != NULL) {
		PostOrder(BT->lchild);
		PostOrder(BT->rchild);
		cout << BT->data << endl;
	}
}
*/

//��������ǵݹ��㷨
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

//��������ǵݹ��㷨
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