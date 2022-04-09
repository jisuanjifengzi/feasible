#include<iostream>
using namespace std;
typedef struct Node {
    double coef;
    int exp;
    struct Node* next;
}Node;
void creatLink(Node*& p, int m)
{
    Node* r, * s;
    int i;
    p = (Node*)malloc(sizeof(Node));
    r = p;
    for (i = 0; i < m; i++)
    {
        s = (Node*)malloc(sizeof(Node));
        cout << "按顺序从下到大依次输出"<<m<<"个多项式的系数和指数：" << endl;
        cin >> s->coef >> s->exp;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}
void printLink(Node* p) {
    Node* s;
    s = p->next;
    while (s != NULL) {
        if (s->coef != 0)
        {
            cout << s->coef << "X" << "'" << s->exp;
            s = s->next;
              if (s != NULL) {
            if (s->coef >= 0) printf("+");
        }
          
        }
        else
        {
            s = s->next;
        }
       
      
    }
}
void del(Node*&q)
{
     
    Node* a = q->next;
    free(q);
    q = a;
}
Node* add(Node*& a, Node*& b) {
    Node* zhongduan, * p, * q, * t, * s;
    double temp;
    p = a->next;
    q = b->next;
    zhongduan = (Node*)malloc(sizeof(Node));
    t = zhongduan;
    while (p != NULL && q != NULL)
    {
        if (p->exp < q->exp) {
            s = (Node*)malloc(sizeof(Node));
            s->coef = p->coef;
            s->exp = p->exp;
            t->next = s;
            t = s;
            p = p->next;
        }
        else if (p->exp == q->exp){
            temp = p->coef+q->coef;
            if (temp != 0.0){
                s = (Node*)malloc(sizeof(Node));
                s->coef = temp;
                s->exp = p->exp;
                t->next = s;
                t = s;
                p = p->next;
            }
            else
            {
                p = p->next;
            }
            del(q);
        }
        else {
            s = (Node*)malloc(sizeof(Node));
            s->coef = q->coef;
            s->exp = q->exp;
            t->next = s;
            t = s;
            q = q->next;
        }
    }
    if (q != NULL) t->next = q;
    else t->next = p;
    return zhongduan;
}
int main() {
    Node* p1, * p2;
    p1 = (Node*)malloc(sizeof(Node));
    p2 = (Node*)malloc(sizeof(Node));
    int L1, L2;
    cout << "第一个多项式有几项" << endl;
    cin >> L1;
    creatLink(p1, L1);
    cout << "第二个多项式有几项" << endl;
    cin >> L2;
    creatLink(p2, L2);
    cout << "最终结果是" << endl;
    printLink(add(p1, p2));
    return 0;
}