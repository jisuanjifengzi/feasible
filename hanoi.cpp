#include<iostream>
using namespace std;
void hanoi(int n,char X, char Y, char Z) {
	if (n == 1)
	{
		cout << "�ѵ�" << n << "����" << X << " -> " << Z << endl;  //ֱ���ƶ���Z 
	}
	else {
		hanoi(n-1,X, Z, Y);  //������n-1���Ƶ�Y
		cout <<"�ѵ�"<<n<<"����"<<X<<" -> "<<Z<< endl;  //���
		hanoi(n-1,Y, X, Z);  //��ʣ��n-1����Y�Ƶ�Z
	}
}
int main() {
	int n;
	cout << "������Բ������" << endl;
	cin >> n;
	hanoi(n,'X', 'Y', 'Z');
}