#include <graphics.h>// ����ͼ�ο�ͷ�ļ�
#include <conio.h>//_getch()����ͷ�ļ�����ͣ����
#include <stack>
#include<iostream>
#include<cmath>//math����
using namespace std;
//_getch()����
//a ��һ��       97
//d ��һ��       100
//�ո�   ��ͣ    32S
//ESC    �˳�    27
int length, side = 15;//���������εı߳��͵�������ı߳�
int choose = 2;//�ж��Ƿ�ֲ�������ʾ��Ĭ��Ϊ�Զ�����
struct coord {//��¼��ǰT�͹��ơ�
	int _midline;
	int _midlist;
	int _area;
};
stack<coord>s1, s2;//s1�洢ÿһ����ȾT�͹��Ƶ�λ�ã�s2�洢��s1�е���������
void chessborder(int x1, int y1, int x2, int y2, int xp, int yp, int k);
void substep();
int main()
{
	int k;
	cout << "������k��ֵ:"; cin >> k;
	if (k <= 0)
	{
		cout << "��������ȷ����ֵ!" << endl;
		return 0;
	}
	cout << "��ѡ���ֶ����л����Զ�����" << endl;
	cout << "1.�ֶ�����   2.�Զ�����" << endl;
	cin >> choose;
	initgraph(500, 500);//��ʼ������̨ͼ�Σ���СΪ500*500.
	length = pow(2, k);//2��k�η�����
	setfillcolor(WHITE);//���õ�ǰ������ɫ����ɫ
	for (int i = 0; i < length; i++)
		for (int j = 0; j < length; j++)
			rectangle(side * j, side * i, side * (j + 1), side * (i + 1));//���趨�õķ�Χ���滭����
	srand((unsigned)time(NULL));//���ڸ�rand()�����趨���ӣ�����seed��rand()�����ӣ�������ʼ��rand()����ʼֵ
	int x = rand() % length * side;//���ⷽ��ĺ�������
	int y = rand() % length * side;//���ⷽ�����������
	setfillcolor(WHITE);//������ɫ��ɫ
	fillrectangle(x, y, x + side, y + side);// ��������(�б߿�)
	chessborder(0, 0, length * side, length * side, x, y, k);
	_getch();           // ��������ر�
	closegraph();          // �رջ�ͼ����
	return 0;
}
void substep();
void turnback()//������һ��
{
	if (s1.empty() || s1.size() == 1)
	{
		cout << "�����������һ�����Է��ء�" << endl;
		exit(0);
	}
	coord temp = s1.top();
	s1.pop(); s2.push(temp);
	temp = s1.top();
	setfillcolor(BLACK);
	switch (temp._area) {
	case 1:fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 2:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 3:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 4:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
	}
	substep();
}
void turnfront()
{
	coord temp = s1.top(); s1.push(s2.top());
	s2.pop();
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	switch (temp._area) {
	case 1: fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 2:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 3:fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline, temp._midlist, temp._midline + side, temp._midlist + side); break;
	case 4: fillrectangle(temp._midline - side, temp._midlist - side, temp._midline, temp._midlist);
		fillrectangle(temp._midline, temp._midlist - side, temp._midline + side, temp._midlist);
		fillrectangle(temp._midline - side, temp._midlist, temp._midline, temp._midlist + side);
	}
	substep();
}
void substep()//ѡ�����
{
	int temp = _getch();
	switch (temp) {
	case 97:if (!s2.empty())turnfront(); break;
	case 100:turnback(); break;
	case 27:exit(0);
	default:substep(); break;
	}
}
void chessborder(int x1, int y1, int x2, int y2, int xp, int yp, int k)
//x1��x2��y1��y2�ֱ�Ϊ��������ϡ��¡����ұ߽�������ͼ���е�λ��
//xp��ypΪ���ⷽ�����ڵ�λ��
//kΪ�жϵ�ǰ�����ĸ�С�����Ƿ񶼱�����
{
	if (k == 0)return;//�˳�������
	Sleep(100);        //�����ݹ���̣�����Խ��ͼ�α任Խ��
	int area;
	int midline = (x1 + x2) / 2, midlist = (y1 + y2) / 2;//��ȡ����λ��,midlineΪ�������ߣ�midlistΪ��������
	if (xp < midline)//�жϵ�ǰ����һ������.
		if (yp < midlist)area = 1;
		else area = 3;
	else if (yp < midlist)area = 2;
	else area = 4;
	coord c_temp;
	c_temp._midline = midline;
	c_temp._midlist = midlist;
	c_temp._area = area;
	s1.push(c_temp);
	setfillcolor(RGB(rand() % 255, rand() % 255, rand() % 255));
	switch (area)
	{
	case 1://��һ����ʱ�����еĲ���
		if (choose == 1)substep();// �������������һ��������
		//���T�͹���
		fillrectangle(midline, midlist - side, midline + side, midlist);
		fillrectangle(midline - side, midlist, midline, midlist + side);
		fillrectangle(midline, midlist, midline + side, midlist + side);
		//����
		chessborder(x1, y1, midline, midlist, xp, yp, k - 1);//��һ����
		chessborder(midline, y1, x2, midlist, midline, midlist - side, k - 1);//�ڶ�����
		chessborder(x1, midlist, midline, y2, midline - side, midlist, k - 1);//��������
		chessborder(midline, midlist, x2, y2, midline, midlist, k - 1);//��������
		break;
	case 2://�ڶ�����ʱ�����еĲ���
		if (choose == 1)substep();
		//���T�͹���
		fillrectangle(midline - side, midlist - side, midline, midlist);
		fillrectangle(midline - side, midlist, midline, midlist + side);
		fillrectangle(midline, midlist, midline + side, midlist + side);
		//����
		chessborder(x1, y1, midline, midlist, midline - side, midlist - side, k - 1);//��һ����
		chessborder(midline, y1, x2, midlist, xp, yp, k - 1);//�ڶ�����
		chessborder(x1, midlist, midline, y2, midline - side, midlist, k - 1);//��������
		chessborder(midline, midlist, x2, y2, midline, midlist, k - 1);//��������
		break;
	case 3://��������ʱ�����еĲ���
		if (choose == 1)substep();
		//���T�͹���
		fillrectangle(midline - side, midlist - side, midline, midlist);
		fillrectangle(midline, midlist - side, midline + side, midlist);
		fillrectangle(midline, midlist, midline + side, midlist + side);
		//����
		chessborder(x1, y1, midline, midlist, midline - side, midlist - side, k - 1);	//��һ����
		chessborder(midline, y1, x2, midlist, midline, midlist - side, k - 1);//�ڶ�����
		chessborder(x1, midlist, midline, y2, xp, yp, k - 1);//��������
		chessborder(midline, midlist, x2, y2, midline, midlist, k - 1);//��������
		break;
	case 4://��������ʱ�����еĲ���
		if (choose == 1)substep();
		//���T�͹���
		fillrectangle(midline - side, midlist - side, midline, midlist);
		fillrectangle(midline, midlist - side, midline + side, midlist);
		fillrectangle(midline - side, midlist, midline, midlist + side);
		//����
		chessborder(x1, y1, midline, midlist, midline - side, midlist - side, k - 1);	//��һ����
		chessborder(midline, y1, x2, midlist, midline, midlist - side, k - 1);//�ڶ�����
		chessborder(x1, midlist, midline, y2, midline - side, midlist, k - 1);//��������
		chessborder(midline, midlist, x2, y2, xp, yp, k - 1);//��������
		break;
	default:
		break;
	}
}