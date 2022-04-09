#include<iostream> 
#include<stack> 
#include<queue> 
using namespace std;
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;//�����ֵܱ�ʾ��
}BiTNode, * BiTree;
//typedef struct BiTNode˫�ױ�ʾ��
//{
//    int data;
//    int* parent;//ָ��˫�׽��
//    char LRtip;//���Һ��ӱ��
//
//}bitNode;
void CreateTree(BiTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#') T = NULL;
    else
    {
        T = (BiTree)malloc(sizeof(BiTNode));
        if (!T)  cout << "���ɽ�����" << endl;
        T->data = ch;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

//��1�����������������ջ����Ϊ���ĸ߶� 
int BT_high(BiTree T)
{
    BiTree p = T, r = NULL;
    int max = 0;                                     //���� 
    stack<BiTree> s;
    while (p || !s.empty())
    {
        if (p != NULL)
        {
            s.push(p);
            p = p->lchild;
        }
        else
        {
            p = s.top();
            if (p->rchild != NULL && p->rchild != r)
                p = p->rchild;
            else
            {
                if (s.size() > max) max = s.size();//����μ�Ϊ�߶� 
                r = p;
                s.pop();
                p = NULL;
            }
        }
    }
    return max;
}

//��2����α�������μ�Ϊ�߶� 
int BT_level_depth(BiTree T)
{
    if (!T)  return 0;
    BiTree p = T, Q[100];
    int front = -1, rear = -1, last = 0, level = 0;
    Q[++rear] = p;
    while (front < rear)
    {
        p = Q[++front];
        if (p->lchild)
            Q[++rear] = p->lchild;
        if (p->rchild)
            Q[++rear] = p->rchild;
        if (front == last)
        {
            last = rear;
            level++;               //���+1 
        }
    }
    return level;
}

//��3���ݹ�������1 
int max1 = 0;//���� 
int BT_depth1(BiTree T, int depth)
{
    if (T)
    {
        if (T->lchild)
            BT_depth1(T->lchild, depth + 1);
        if (T->rchild)
            BT_depth1(T->rchild, depth + 1);
    }
    if (depth > max1)
        max1 = depth;
    return depth;
}

//��3���ݹ�������2 
int Height(BiTree T)
{
    if (T == NULL) return 0;
    else
    {
        int m = Height(T->lchild);
        int n = Height(T->rchild);
        return (m > n) ? (m + 1) : (n + 1);
    }
}

int main()
{
    BiTree T = NULL;
    CreateTree(T);
    cout << "������������ߣ�" << endl;
    cout << BT_high(T) << endl;
    cout << "��α��������ߣ�" << endl;
    cout << BT_level_depth(T) << endl;
    cout << "�ݹ�������1��" << endl;
    BT_depth1(T, 1);
    cout << max1 << endl;
    cout << "�ݹ�������2��" << endl;
    cout << Height(T) << endl;
    return 0;
}