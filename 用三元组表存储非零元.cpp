#include <stdio.h>
#include<iostream>
using namespace std;
#include<queue>
#define MaxSize 100//�����з���Ԫ��������
#define N 5		//ϡ���������
#define M 5			//ϡ���������
typedef int elem;
typedef struct
{
	int r;//����
	int c;//����
	elem d;//����Ԫ��
}threenode;//��Ԫ�鶨��

typedef struct
{
	int row;//����ֵ
	int cols;//����ֵ
	int nums;//����Ԫ�ظ���
	threenode data[MaxSize];//�������
}thirdNode;	//��Ԫ��˳�����

//����ϡ�����A��Ԫ��
void creat(thirdNode& t, int A[N][M])
{
	int i, j;
	t.row = N;//����
	t.cols = M;//����
	t.nums = 0;//����Ԫ����
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (A[i][j] != 0)//�������0�ǾͰ����Ԫ�����ھ�����������Լ�����ֵ����
			{
				t.data[t.nums].r = i;		
				t.data[t.nums].c = j;		
				t.data[t.nums].d = A[i][j];	
				t.nums++;//����Ԫ�ظ�����һ
			}
		}
	}
}

void printzhu(thirdNode t)//�����Ԫ��
{
	int i;
	if (t.nums <= 0)//�ж��Ƿ��з���Ԫ��
		return;
	printf("\t%d\t%d\t%d\n", t.row, t.cols, t.nums);
	printf("-------------------------------------\n");
	for (i = 0; i < t.nums; i++)
		printf("\t%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].d);
}

void TranTat(thirdNode t, thirdNode& C,int B[5][5])//��ԭ����ת��Ȼ������µľ���B��
{
	
	int p, q = 0, v;		//qΪta.data���±�,v���м�����pΪt.data���±�
	C.row = t.cols;		//������������
	C.cols = t.row;
	C.nums = t.nums;		//����Ԫ�ظ���
	if (t.nums != 0)			
	{
		for (v = 0; v < t.cols; v++)
		{ 
			for (p = 0; p < C.nums; p++)
				if (t.data[p].c == v)//��ԭ��Ԫ��ĵ�һ�п�ʼ�ң��ҵ��˾ͽ���һ�е�������������������Ԫ����
				{
					C.data[q].r = t.data[p].c;//���л���
					C.data[q].c = t.data[p].r;
					C.data[q].d = t.data[p].d;//����ֵ����
	                B[C.data[q].r][C.data[q].c] = C.data[q].d;
					q++;						//Ԥ����һ��Ԫ�ش��λ��
				}
		}
	}
	else {
		cout << "�˾���Ϊ�����!" << endl;
	}	
}

void accle(int A[N][M])
{
	queue<int> P;//���ö��У�ÿ�ν�ÿ�еķ���Ԫ�ظ������������
	int Nozero = 0;
	int num[5];//��ʾ����A��ĳ�еķ���Ԫ�صĸ���
	int cpot[5]; //��ʼֵ��ʾ����A��ĳ�еĵ�һ������Ԫ����B�е�λ��
	cpot[0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[j][i] != 0)
			{
				if (Nozero == 0)
				{
					cout << "A�е�"<<i+1<<"��" << "��һ������Ԫ�ؽ�����B�е�" << i+1 << "��" << "��" << j+1 << "��" << endl;
				}
				if (Nozero == 0 && i != 0)
				{
					cpot[i] = cpot[i - 1] + num[i - 1];
				}
				Nozero++;
			}
		}
		num[i] = Nozero;
		P.push(Nozero);//���������
		Nozero = 0;
	} 
	double all = 0;
	for (int i = 0; i < M; i++)
	{   
		
		cout << "��" << i + 1 << "����" << P.front() << "������Ԫ��" << endl;//�Ӷ��׿�ʼ�������ÿһ�з���Ԫ�ظ���
		all = all = P.front();
		P.pop();
	}
	cout << "-----------------------" << endl;
	if ((all / 25) < 0.05)
	{
		cout << "�þ�����ϡ�����!" << endl;
		cout << "-----------------------" << endl;
	}
}

int main()
{
	thirdNode t1, t2, t3;	//t1, t2Ϊ��Ԫ��,t3��ת�ú������Ԫ��
	int a[5][5] = {
		{0,0,0,0,0},
		{0,0,0,6,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	    {0,0,0,0,0}}; accle(a);//�����ʼ����ÿһ�еķ���Ԫ����
	int b[5][5] = { 0 };
	creat(t1, a);			//����a����Ԫ��
	cout << "a����Ԫ����" << endl;
	printzhu(t1);					//�����Ԫ��
	TranTat(t1, t3,b);				//��Ԫ��ת��
	cout << "aת�ú����Ԫ����" << endl;
	printzhu(t3);					
	cout << "����ת�ú�b�ľ���Ϊ��" << endl;
	for (int i = 0; i < 5; i++)//��ת�ú���¾��������ÿ�ĸ����һ�У���ԭ����������������
	{
		for (int j = 0; j < 5; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
