#include <stdio.h>
#include<iostream>
using namespace std;
#include<queue>
#define MaxSize 100//矩阵中非零元素最多个数
#define N 5		//稀疏矩阵行数
#define M 5			//稀疏矩阵列数
typedef int elem;
typedef struct
{
	int r;//行数
	int c;//列数
	elem d;//数据元素
}threenode;//三元组定义

typedef struct
{
	int row;//行数值
	int cols;//列数值
	int nums;//非零元素个数
	threenode data[MaxSize];//存放数组
}thirdNode;	//三元组顺序表定义

//生成稀疏矩阵A三元组
void creat(thirdNode& t, int A[N][M])
{
	int i, j;
	t.row = N;//行数
	t.cols = M;//列数
	t.nums = 0;//非零元素数
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			if (A[i][j] != 0)//如果不是0那就把这个元素所在矩阵的行与列以及它的值存入
			{
				t.data[t.nums].r = i;		
				t.data[t.nums].c = j;		
				t.data[t.nums].d = A[i][j];	
				t.nums++;//非零元素个数加一
			}
		}
	}
}

void printzhu(thirdNode t)//输出三元组
{
	int i;
	if (t.nums <= 0)//判断是否有非零元素
		return;
	printf("\t%d\t%d\t%d\n", t.row, t.cols, t.nums);
	printf("-------------------------------------\n");
	for (i = 0; i < t.nums; i++)
		printf("\t%d\t%d\t%d\n", t.data[i].r, t.data[i].c, t.data[i].d);
}

void TranTat(thirdNode t, thirdNode& C,int B[5][5])//将原矩阵转置然后存入新的矩阵B中
{
	
	int p, q = 0, v;		//q为ta.data的下标,v进行计数，p为t.data的下标
	C.row = t.cols;		//总行列数互换
	C.cols = t.row;
	C.nums = t.nums;		//非零元素个数
	if (t.nums != 0)			
	{
		for (v = 0; v < t.cols; v++)
		{ 
			for (p = 0; p < C.nums; p++)
				if (t.data[p].c == v)//从原三元组的第一行开始找，找到了就将这一行的行列数互换存入新三元组中
				{
					C.data[q].r = t.data[p].c;//行列互换
					C.data[q].c = t.data[p].r;
					C.data[q].d = t.data[p].d;//矩阵值存入
	                B[C.data[q].r][C.data[q].c] = C.data[q].d;
					q++;						//预置下一个元素存放位置
				}
		}
	}
	else {
		cout << "此矩阵为零矩阵!" << endl;
	}	
}

void accle(int A[N][M])
{
	queue<int> P;//运用队列，每次将每列的非零元素个数存入队列中
	int Nozero = 0;
	int num[5];//表示矩阵A中某列的非零元素的个数
	int cpot[5]; //初始值表示矩阵A中某列的第一个非零元素在B中的位置
	cpot[0] = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (A[j][i] != 0)
			{
				if (Nozero == 0)
				{
					cout << "A中第"<<i+1<<"列" << "第一个非零元素将放入B中第" << i+1 << "行" << "第" << j+1 << "列" << endl;
				}
				if (Nozero == 0 && i != 0)
				{
					cpot[i] = cpot[i - 1] + num[i - 1];
				}
				Nozero++;
			}
		}
		num[i] = Nozero;
		P.push(Nozero);//存入队列中
		Nozero = 0;
	} 
	double all = 0;
	for (int i = 0; i < M; i++)
	{   
		
		cout << "第" << i + 1 << "列有" << P.front() << "个非零元素" << endl;//从队首开始依次输出每一列非零元素个数
		all = all = P.front();
		P.pop();
	}
	cout << "-----------------------" << endl;
	if ((all / 25) < 0.05)
	{
		cout << "该矩阵是稀疏矩阵!" << endl;
		cout << "-----------------------" << endl;
	}
}

int main()
{
	thirdNode t1, t2, t3;	//t1, t2为三元组,t3是转置后的新三元组
	int a[5][5] = {
		{0,0,0,0,0},
		{0,0,0,6,0},
		{0,0,0,0,0},
		{0,0,0,0,0},
	    {0,0,0,0,0}}; accle(a);//计算最开始矩阵每一列的非零元个数
	int b[5][5] = { 0 };
	creat(t1, a);			//生成a的三元组
	cout << "a的三元组是" << endl;
	printzhu(t1);					//输出三元组
	TranTat(t1, t3,b);				//三元组转置
	cout << "a转置后的三元组是" << endl;
	printzhu(t3);					
	cout << "最终转置后b的矩阵为：" << endl;
	for (int i = 0; i < 5; i++)//把转置后的新矩阵输出，每四个输出一行（按原矩阵行列数而定）
	{
		for (int j = 0; j < 5; j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
