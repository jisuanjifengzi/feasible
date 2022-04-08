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
void push(LinkStack &s, Elemtype a)//��ջ
{
	Linknode* p;
	p = (Linknode*)malloc(sizeof(Linknode));
	p->data = a;
	p->next = s->next;// ����p�����Ϊ��ʼ���
	s->next = p;
}
void look(LinkStack &s)//����ջ
{
	printf("ջ��Ԫ��Ŀǰ��:");
	Linknode* p = s->next;
	while (p != NULL)
	{
		cout << p->data;
		p = p->next;
	}
	printf("\n");
}
void pop(LinkStack &s)//��ջ
{
	Linknode* p;
	int popnum;
	if (s->next == NULL)
	{
		exit(0);
	}
	p = s->next;//pָ��ʼ���
	 popnum= p->data;
	 cout << "Ŀǰ��ջ��ջ��Ԫ����" << popnum << endl;
	s->next = p->next;//ɾ��p���
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
	free(s); // sָ��β���,�ͷ���ռ�
}
int main() {
	LinkStack s;
	Elemtype num;
	int size;
	newstack(s);//��ʼ��
	cout << "��������ջ��Ԫ�ظ���" << endl;
	cin >> size;
	for (int i = 0; i < size; i++)
	{
		cout << "����ĵ�" << i + 1 << "��Ԫ����:";
		cin >> num;
		push(s, num);
	}
	look(s);
	cout << "ջ��Ԫ����" << gettop(s) << endl;
	pop(s);
	destroy(s);
	cout << "ջ������" << endl;
}