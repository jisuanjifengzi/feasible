#include<iostream>
using namespace std;
#define MAXSIZE 10
typedef struct {
	int* base;	//ջ��ָ��
	int* top;	//ջ��ָ��
	int stacksize;	//ջ�����õ��������
}SqStack;
void InitStack(SqStack& S) {//����һ����ջ
	S.base = new int[MAXSIZE];//����һ���������
	S.top = S.base;
	S.stacksize = MAXSIZE;
	cout << "�������һ������" << endl;
}
//ѹջ
void Push(SqStack& S, int e) {
	if (S.top - S.base == S.stacksize) 
		cout << "ջ���޷���Ÿ���Ԫ��" << endl;
	*S.top++ = e;
}
//��ջ
int Pop(SqStack& S, int& a) {
	if (S.base == S.top) cout << "��ջ��" << endl;
	a = *--S.top;
	return a;
}
int GetTop(SqStack S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
}
//��ջ��
void GetLen(SqStack S) {
	int len = S.top - S.base;
	cout << "ջ�ĳ���Ϊ��" << len << endl;
}
void menu()
{
	cout << "**������ջ�밴1**" << endl;
	cout << "**�鿴�����밴2**" << endl;

}
void main() {
	int input;
	int num;
	SqStack S;	//����һ��ջ�ڵ�
	InitStack(S);	//����һ����ջ
	menu();
	cin>>num;
    if (num == 1)
	{
	cout << "���ѹ�����һ����ջ" << endl;
    cout << "��ȷ������Ԫ�صĸ���" << endl;
	cin >> num;
	cout << "�������ʼԪ��ֵ" << endl;
	cin >> input;
	for (int i = 0; i < num; i++) {
		int num = input + i;
		cout << "��" << i + 1 << "��Ԫ��" << num<< "�ѽ�ջ" << endl;
		Push(S, num);	//��ջ
	}
	cout << "ջ�ĳ�����" << S.top - S.base << endl;
    int output;
	for (int j = 0; j < num; j++) {
		cout << "��" << num - j << "��Ԫ��Ϊ��";
		int e = Pop(S, output);	//��ջ
		cout << e << endl;
	}
	}
	if (num == 2)
	{
		if (S.top - S.base == 0)
		{
			cout << "��ǰջ��û��Ԫ��" << endl;
			cout << "�Ƿ�����ѡ��(����1�Ǽ���������2Ϊֹͣ)" << endl;
			cin >> num;
			if (num == 1)
			{
				system("cls");
				menu();
				int num2 = 0;
				cin >> num2;
				if (num2 == 1)
				{
					cout << "���ѹ�����һ����ջ" << endl;
					cout << "��ȷ������Ԫ�صĸ���" << endl;
					cin >> num;
					cout << "�������ʼԪ��ֵ" << endl;
					cin >> input;
					for (int i = 0; i < num; i++) {
						int num = input + i;
						cout << "��" << i + 1 << "��Ԫ��" << num << "�ѽ�ջ" << endl;
						Push(S, num);	//��ջ
					}
					cout << "ջ�ĳ�����" << S.top - S.base << endl;
					int output;
					for (int j = 0; j < num; j++) {
						cout << "��" << num - j << "��Ԫ��Ϊ��";
						int e = Pop(S, output);	//��ջ
						cout << e << endl;
					}
				}
				else {
					cout << "��������" << endl;
				}
			}
		}
		else {
			int output;
			for (int j = 0; j < num; j++) {
				cout << "��" << num - j << "��Ԫ��Ϊ��";
				int e = Pop(S, output);	//��ջ
				cout << e << endl;
			}
		}
	}
}