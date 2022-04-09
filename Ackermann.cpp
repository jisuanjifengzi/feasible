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
	while (!A.empty())//m不等于0的两个Ack算法
	{
		while (m != 0)
		{
			if (n == 0)//n等于0 就先让m减一进栈，再向B中进一个1.
			{
				m = m - 1;
				n = 1;
				A.push(m);
				B.push(n);
			}
			else//Ack函数的第三个算法，Ack函数中还套有一个Ack函数，这时候这一步的暂时不算，将用-1代替数进栈，n减一
			{
				n = n - 1;
				A.push(m - 1);
				B.push(-1);
			}
		}
		n = n + 1;//这一步是当m等于0之后，就将此时的n加一（最后算的结果其实就是n不断加1得到的）
		while ((!A.empty()) && (B.top() != -1))//算到中途某一次m=0后将此时两个栈顶的元素去除表明到这一步的运算已经有结果了
		{
			A.pop();
			B.pop();
		}
		if (!A.empty())//将栈顶的元素赋给M,算的n结果进入B，之后就是另一次Ack(m,n)的结果，以此类推
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
