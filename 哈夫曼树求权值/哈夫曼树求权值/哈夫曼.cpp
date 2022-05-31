#include<iostream>
#include<stdlib.h>
using namespace std;
typedef int ElemType;
struct BTreeNode
{
	ElemType data;
	struct BTreeNode* left;
	struct BTreeNode* right;
};
//根据数组 a 中 n 个权值建立一棵哈夫曼树，返回树根指针
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
	int i, j;
	struct BTreeNode** b, * q=NULL;
	b = (BTreeNode**)malloc(n * sizeof(struct BTreeNode));
	for (i = 0; i < n; i++) //初始化b指针数组，使每个指针元素指向a数组中对应的元素结点
	{
		b[i] = (BTreeNode*)malloc(sizeof(struct BTreeNode));
		b[i]->data = a[i];
		b[i]->left = b[i]->right = NULL;
	}
	for (i = 1; i < n; i++)//进行 n-1 次循环建立哈夫曼树
	{
		//k1表示森林中具有最小权值的树根结点的下标，k2为次最小的下标
		int k1 = -1, k2;
		for (j = 0; j < n; j++)//让k1初始指向森林中第一棵树，k2指向第二棵
		{
			if (b[j] != NULL && k1 == -1)
			{
				k1 = j;
				continue;
			}
			if (b[j] != NULL)
			{
				k2 = j;
				break;
			}
		}
		for (j = k2; j < n; j++)//从当前森林中求出最小权值树和次最小
		{
			if (b[j] != NULL)
			{
				if (b[j]->data < b[k1]->data)
				{
					k2 = k1;
					k1 = j;
				}
				else if (b[j]->data < b[k2]->data)
					k2 = j;
			}
		}
		//由最小权值树和次最小权值树建立一棵新树，q指向树根结点
		q = (BTreeNode*)malloc(sizeof(struct BTreeNode));
		q->data = b[k1]->data + b[k2]->data;
		q->left = b[k1];
		q->right = b[k2];

		b[k1] = q;//将指向新树的指针赋给b指针数组中k1位置
		b[k2] = NULL;//k2位置为空
	}
	free(b); //删除动态建立的数组b
	return q; //返回整个哈夫曼树的树根指针
}

//3、求哈夫曼树的带权路径长度
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len初始为0
{
	if (FBT == NULL) //空树返回0
		return 0;
	else
	{
		if (FBT->left == NULL && FBT->right == NULL)//访问到叶子结点
			return FBT->data * len;
		else //访问到非叶子结点，进行递归调用，返回左右子树的带权路径长度之和，len递增
			return WeightPathLength(FBT->left, len + 1) + WeightPathLength(FBT->right, len + 1);
	}
}

//主函数
int main(void)
{
	int n, i;
	ElemType* a;
	struct BTreeNode* fbt;
	cout << "从键盘输入待构造的哈夫曼树中带权叶子结点数n：";
	cin >> n;
	a = (ElemType*)malloc(n * sizeof(ElemType));
	cout << "从键盘输入" << n << "个整数作为权值：";
	for (i = 0; i < n; i++)
		cin >> a[i];
	fbt = CreateHuffman(a, n);
	cout << "哈夫曼树的带权路径长度：";
	cout << WeightPathLength(fbt, 0) << endl;
}