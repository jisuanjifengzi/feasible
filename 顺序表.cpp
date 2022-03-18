//顺序表元素设为10个，找第三大的元素
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
    SqList* list = NULL;//初始化为空
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
    cout << "顺序表总长度为" << L->length << endl;;
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
    cout <<pivot<<"小了：" <<i <<"次" << endl;
    if (i == 3)
        {
            cout << pivot << "是第三大的元素" << endl;
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
    {        cout << L->data[i] << "是第三小元素!" << endl;
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