
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
    while (i < n)
    {
        L->data[k] = a[i];
        k++; i++;
    }
    L->length = k;
    cout << "顺序表总长度为" << L->length << endl;;
}
void outnum(SqList*p, int num)
{
    int i;
    if (p->length==0)
    {
        printf("里面的人已经全部出列，无法继续下去！\n");
        return;
    }
    for (i = num; i < p->length; i++)
    {
        p->data[i - 1] = p->data[i];
    }
    p->length--;
}
int tallnum(SqList* L, int num, int size)
{
    int choose; 
    int i;
    int w; 
    choose = num - 1;
    printf("出列的人员编号有：\n");
    for (i = L->length; i > 0; i--)
    {
        choose = (choose + size - 1) % L->length; 
        w = L->data[choose];
        cout << w + 1 << endl;
        outnum(L, choose + 1);
    }
    return 1;
}

int main()
{

    int m = 0, n = 0;
    cout << "请输入人数和对应的数字" << endl;
    cin >> n >> m;
    cout << "规定的人数是:" << n << "人" << endl;
    cout << "报数报到" << m << "出局" << endl;
    int arr[1000] = { 0 };
    for (int i = 0; i < n; i++)
    {
        arr[i] = i + 1;
    }
    SqList* s1 = creat_sqlist();
    CreateList(s1, arr, n);
    tallnum(s1, n, m);
}