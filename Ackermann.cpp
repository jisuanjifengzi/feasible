#include<iostream>
#include<stack>
#include<malloc.h>
using namespace std;
int all(int m, int n)
{
	stack<int> A;
	stack<int> B;
    A.push(m);
	B.push(n);
	while (!A.empty())//m������0������Ack�㷨
	{
		while (m != 0)
		{
			if (n == 0)//n����0 ������m��һ��ջ������B�н�һ��1.
			{
				m = m - 1;
				n = 1;
				A.push(m);
				B.push(n);
			}
			else//Ack�����ĵ������㷨��Ack�����л�����һ��Ack��������ʱ����һ������ʱ���㣬����-1��������ջ��n��һ
			{
				n = n - 1;
				A.push(m - 1);
				B.push(-1);
			}
		}
		n = n + 1;//��һ���ǵ�m����0֮�󣬾ͽ���ʱ��n��һ�������Ľ����ʵ����n���ϼ�1�õ��ģ�
		while ((!A.empty()) && (B.top() != -1))//�㵽��;ĳһ��m=0�󽫴�ʱ����ջ����Ԫ��ȥ����������һ���������Ѿ��н����
		{
			A.pop();
			B.pop();
		}
		if (!A.empty())//��ջ����Ԫ�ظ���M,���n�������B��֮�������һ��Ack(m,n)�Ľ�����Դ�����
		{
			m = A.top();
			B.pop();
			B.push(n);
		}
	}
	return n;
}
void main()
{
	cout << all(2, 1);
}
