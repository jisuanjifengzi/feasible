#include<iostream>
using namespace std;
void hanoi(int n,char X, char Y, char Z) {
	if (n == 1)
	{
		cout << "把第" << n << "个从" << X << " -> " << Z << endl;  //直接移动到Z 
	}
	else {
		hanoi(n-1,X, Z, Y);  //把上面n-1个移到Y
		cout <<"把第"<<n<<"个从"<<X<<" -> "<<Z<< endl;  //输出
		hanoi(n-1,Y, X, Z);  //把剩下n-1个从Y移到Z
	}
}
int main() {
	int n;
	cout << "请输入圆盘数量" << endl;
	cin >> n;
	hanoi(n,'X', 'Y', 'Z');
}