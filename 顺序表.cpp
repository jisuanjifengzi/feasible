//˳���Ԫ����Ϊ10�����ҵ������Ԫ��
#include<iostream>
#include<stdlib.h>
#include<stdio.h> 
using namespace std;
#define Elemtype int
#define MaxSize 10
typedef struct {
    Elemtype data[MaxSize];
    int length;
} SqList;
SqList* creat_sqlist(void)
{
    SqList* list = NULL;//��ʼ��Ϊ��
    list = (SqList*)malloc(sizeof(SqList));
    return list;
}
void CreateList(SqList*& L, Elemtype a[], int n)
{
    int i = 0, k = 0;
    L = (SqList*)malloc(sizeof(SqList));
    while (i<n)
    {
        L->data[k] = a[i];
        k++; i++;
    }
    L->length = k;
    cout << "˳����ܳ���Ϊ" << L->length << endl;;
}
void partiton2(SqList* L)
{ 
    int i = 0,j= L->length;  
    for (int n = 0; n <=j; n++)
    {
        Elemtype pivot = L->data[n];
        for (int d = 0; d <=j; d++)
        {
            if (pivot <= L->data[d])
            {
                i++;
            }
        }
    cout <<pivot<<"С�ˣ�" <<i <<"��" << endl;
    if (i == 3)
        {
            cout << pivot << "�ǵ������Ԫ��" << endl;
        }
    i = 0;
    }
   
}
int main()
{
 
   int arrs[10] = { 18,8,2,79,15,5,23,41,19,0,};
       SqList* s1 = creat_sqlist();
      CreateList(s1, arrs, 10);
      partiton2(s1);
    
       
} 
/*cout << j << endl;
    
    while (i < j)
    {
        while (j > i && L->data[j] > pivot)
        {
            j--;
        }
        L->data[i] = L->data[j];
        while (i < j && L->data[i] <= pivot)
        {
            i++;
        }
        L->data[j] = L->data[i];
    }
    L->data[i] = pivot;
    if (i == 3)
    {        cout << L->data[i] << "�ǵ���СԪ��!" << endl;
    }
    if (i > 3)
    {
        
        for (int b = 0; b < 10; b++)
    {
            cout << L->data[b] << endl;
    }
        cout << endl;
        cout << i << endl;
        partiton2(L, i);
    }
    if (i < 3)
    {
        SqList* s2 = creat_sqlist();

        for (int b = 0; b < 10; b++)
        {
            cout << L->data[b] << endl;
        }
        cout << endl;
        cout << i << endl;
        partiton2(L, i);
    }
    */