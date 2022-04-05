#include<iostream>
using namespace std;
#define MAXSIZE 10
typedef struct {
	int* base;	//栈底指针
	int* top;	//栈顶指针
	int stacksize;	//栈可以用的最大容量
}SqStack;
void InitStack(SqStack& S) {//创建一个空栈
	S.base = new int[MAXSIZE];//分配一个最大容量
	S.top = S.base;
	S.stacksize = MAXSIZE;
	cout << "请继续下一步操作" << endl;
}
//压栈
void Push(SqStack& S, int e) {
	if (S.top - S.base == S.stacksize) 
		cout << "栈内无法存放更多元素" << endl;
	*S.top++ = e;
}
//出栈
int Pop(SqStack& S, int& a) {
	if (S.base == S.top) cout << "空栈！" << endl;
	a = *--S.top;
	return a;
}
int GetTop(SqStack S) {
	if (S.top != S.base) {
		return *(S.top - 1);
	}
}
//求栈长
void GetLen(SqStack S) {
	int len = S.top - S.base;
	cout << "栈的长度为：" << len << endl;
}
void menu()
{
	cout << "**构建空栈请按1**" << endl;
	cout << "**查看内容请按2**" << endl;

}
void main() {
	int input;
	int num;
	SqStack S;	//声明一个栈节点
	InitStack(S);	//创建一个空栈
	menu();
	cin>>num;
    if (num == 1)
	{
	cout << "你已构建了一个空栈" << endl;
    cout << "请确定输入元素的个数" << endl;
	cin >> num;
	cout << "请输入初始元素值" << endl;
	cin >> input;
	for (int i = 0; i < num; i++) {
		int num = input + i;
		cout << "第" << i + 1 << "个元素" << num<< "已进栈" << endl;
		Push(S, num);	//入栈
	}
	cout << "栈的长度是" << S.top - S.base << endl;
    int output;
	for (int j = 0; j < num; j++) {
		cout << "第" << num - j << "个元素为：";
		int e = Pop(S, output);	//出栈
		cout << e << endl;
	}
	}
	if (num == 2)
	{
		if (S.top - S.base == 0)
		{
			cout << "当前栈中没有元素" << endl;
			cout << "是否重新选择(输入1是继续，输入2为停止)" << endl;
			cin >> num;
			if (num == 1)
			{
				system("cls");
				menu();
				int num2 = 0;
				cin >> num2;
				if (num2 == 1)
				{
					cout << "你已构建了一个空栈" << endl;
					cout << "请确定输入元素的个数" << endl;
					cin >> num;
					cout << "请输入初始元素值" << endl;
					cin >> input;
					for (int i = 0; i < num; i++) {
						int num = input + i;
						cout << "第" << i + 1 << "个元素" << num << "已进栈" << endl;
						Push(S, num);	//入栈
					}
					cout << "栈的长度是" << S.top - S.base << endl;
					int output;
					for (int j = 0; j < num; j++) {
						cout << "第" << num - j << "个元素为：";
						int e = Pop(S, output);	//出栈
						cout << e << endl;
					}
				}
				else {
					cout << "操作有误！" << endl;
				}
			}
		}
		else {
			int output;
			for (int j = 0; j < num; j++) {
				cout << "第" << num - j << "个元素为：";
				int e = Pop(S, output);	//出栈
				cout << e << endl;
			}
		}
	}
}