#include<iostream>
#include<malloc.h>
#include<stdlib.h>
using namespace std;
typedef int Elemtype;
typedef struct LinkNode
{
	Elemtype data;
	struct LinkNode* next;

}Linknode, * LinkStack;
void newstack(LinkStack &s)
{
	s = (Linknode*)malloc(sizeof(Linknode));
	s->next = NULL;
}
void push(LinkStack &s, Elemtype a)//入栈
{
	Linknode* p;
	p = (Linknode*)malloc(sizeof(Linknode));
	p->data = a;
	p->next = s->next;// 插入p结点作为开始结点
	s->next = p;
}
void look(LinkStack &s)//遍历栈
{
	printf("栈内元素目前有:");
	Linknode* p = s->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	printf("\n");
}
void pop(LinkStack &s)//出栈
{
	Linknode* p;
	int popnum;
	if (s->next == NULL)
	{
		exit(0);
	}
	p = s->next;//p指向开始结点
	 popnum= p->data;
	 cout << "目前出栈的栈顶元素是" << popnum << endl;
	s->next = p->next;//删除p结点
	free(p);
}
Elemtype gettop(LinkStack& s)
{
	if (s->next != NULL)
	{
		return s->next->data;
	}
}
void destroy(LinkStack& s)
{
	
	Linknode* p = s->next;

	while (p != NULL)
	{
			free(s);
		s = p;
		p = p->next;
	}
	free(s); // s指向尾结点,释放其空间
}
int main() {
	LinkStack s;
	Elemtype num;
	int size;
	newstack(s);//初始化
	cout << "请输入入栈的元素个数" << endl;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "插入的第" << i + 1 << "个元素是:";
		cin >> num;
		push(s, num);
	}
	look(s);
	cout << "栈顶元素是" << gettop(s) << endl;
	pop(s);
	destroy(s);
	cout << "栈已销毁" << endl;
}