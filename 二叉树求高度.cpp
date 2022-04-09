#include<iostream> 
#include<stack> 
#include<queue> 
using namespace std;
typedef struct BiTNode {
    char data;
    struct BiTNode* lchild, * rchild;//孩子兄弟表示法
}BiTNode, * BiTree;
//typedef struct BiTNode双亲表示法
//{
//    int data;
//    int* parent;//指向双亲结点
//    char LRtip;//左右孩子标记
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
        if (!T)  cout << "生成结点错误！" << endl;
        T->data = ch;
        CreateTree(T->lchild);
        CreateTree(T->rchild);
    }
}

//法1：后序遍历，结点最大栈长即为树的高度 
int BT_high(BiTree T)
{
    BiTree p = T, r = NULL;
    int max = 0;                                     //树高 
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
                if (s.size() > max) max = s.size();//最大层次即为高度 
                r = p;
                s.pop();
                p = NULL;
            }
        }
    }
    return max;
}

//法2：层次遍历，层次即为高度 
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
            level++;               //层次+1 
        }
    }
    return level;
}

//法3：递归求树高1 
int max1 = 0;//树高 
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

//法3：递归求树高2 
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
    cout << "后序遍历求树高：" << endl;
    cout << BT_high(T) << endl;
    cout << "层次遍历求树高：" << endl;
    cout << BT_level_depth(T) << endl;
    cout << "递归求树高1：" << endl;
    BT_depth1(T, 1);
    cout << max1 << endl;
    cout << "递归求树高2：" << endl;
    cout << Height(T) << endl;
    return 0;
}