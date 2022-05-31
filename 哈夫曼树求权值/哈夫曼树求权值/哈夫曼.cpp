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
//�������� a �� n ��Ȩֵ����һ�ù�����������������ָ��
struct BTreeNode* CreateHuffman(ElemType a[], int n)
{
	int i, j;
	struct BTreeNode** b, * q=NULL;
	b = (BTreeNode**)malloc(n * sizeof(struct BTreeNode));
	for (i = 0; i < n; i++) //��ʼ��bָ�����飬ʹÿ��ָ��Ԫ��ָ��a�����ж�Ӧ��Ԫ�ؽ��
	{
		b[i] = (BTreeNode*)malloc(sizeof(struct BTreeNode));
		b[i]->data = a[i];
		b[i]->left = b[i]->right = NULL;
	}
	for (i = 1; i < n; i++)//���� n-1 ��ѭ��������������
	{
		//k1��ʾɭ���о�����СȨֵ�����������±꣬k2Ϊ����С���±�
		int k1 = -1, k2;
		for (j = 0; j < n; j++)//��k1��ʼָ��ɭ���е�һ������k2ָ��ڶ���
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
		for (j = k2; j < n; j++)//�ӵ�ǰɭ���������СȨֵ���ʹ���С
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
		//����СȨֵ���ʹ���СȨֵ������һ��������qָ���������
		q = (BTreeNode*)malloc(sizeof(struct BTreeNode));
		q->data = b[k1]->data + b[k2]->data;
		q->left = b[k1];
		q->right = b[k2];

		b[k1] = q;//��ָ��������ָ�븳��bָ��������k1λ��
		b[k2] = NULL;//k2λ��Ϊ��
	}
	free(b); //ɾ����̬����������b
	return q; //����������������������ָ��
}

//3������������Ĵ�Ȩ·������
ElemType WeightPathLength(struct BTreeNode* FBT, int len)//len��ʼΪ0
{
	if (FBT == NULL) //��������0
		return 0;
	else
	{
		if (FBT->left == NULL && FBT->right == NULL)//���ʵ�Ҷ�ӽ��
			return FBT->data * len;
		else //���ʵ���Ҷ�ӽ�㣬���еݹ���ã��������������Ĵ�Ȩ·������֮�ͣ�len����
			return WeightPathLength(FBT->left, len + 1) + WeightPathLength(FBT->right, len + 1);
	}
}

//������
int main(void)
{
	int n, i;
	ElemType* a;
	struct BTreeNode* fbt;
	cout << "�Ӽ������������Ĺ��������д�ȨҶ�ӽ����n��";
	cin >> n;
	a = (ElemType*)malloc(n * sizeof(ElemType));
	cout << "�Ӽ�������" << n << "��������ΪȨֵ��";
	for (i = 0; i < n; i++)
		cin >> a[i];
	fbt = CreateHuffman(a, n);
	cout << "���������Ĵ�Ȩ·�����ȣ�";
	cout << WeightPathLength(fbt, 0) << endl;
}