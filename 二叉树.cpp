#include<iostream>
using namespace std;
struct secondtree {
    char data;
    secondtree* lchild, * rchild;
};
void creattree(secondtree** T) {
    char ch;
    cin >> ch;
    if (ch == '#')//�����#�ž�˵������ط�û�����ݣ�ֱ����һ����ָ�����Ϳ�����
        *T = NULL;
    else {
        *T = (secondtree*)malloc(sizeof(secondtree));
        (*T)->data = ch;
        creattree(&((*T)->lchild));//�ȴ��������ٴ����ҽ��
        creattree(&((*T)->rchild));
    }
}
//int allsizes(secondtree* root) {
//    if (root == NULL)  return 0;
//    int left = allsizes(root->lchild);
//    int right = allsizes(root->rchild);
//    return left + right + 1;
//}
//�������
void DAOXU(secondtree* BT) {
    if (BT) {
        DAOXU(BT->rchild);
        DAOXU(BT->lchild);
        cout << BT->data << "  ";
    }
}
int main()
{
    secondtree* root; \
    creattree(&root);
    //cout << allsizes(root);
    DAOXU(root);
    system("pause");
  
    return 0;
} 
////ǰ�����
//void PreOrderTraversal(BiNode* BT) {
//    if (BT) {
//        cout << BT->data << "  ";
//        //�������������֮��Ż����������
//        PreOrderTraversal(BT->lchild);
//        //��һ������һ�����ǲ��й�ϵ���������һ��ִ���꣬�Ż�������
//        //��Ȼ����Ȼ�ǵݹ飬��������������ʱ�����������ֻ�����������ڵ��������
//        PreOrderTraversal(BT->rchild);
//    }
//}
////�������
//void InOrderTraversal(BiNode* BT) {
//    if (BT) {
//        InOrderTraversal(BT->lchild);
//        cout << BT->data << "  ";
//        InOrderTraversal(BT->rchild);
//    }
//}
//
//�������

////���ʶ�����������Ҫ�ı���ʲô��ֱ�Ӵ�root��ȥ���ɡ�
//    //PreOrderTraversal(root);
//    cout << endl;
//   /* InOrderTraversal(root);*/
//    cout << endl;
//    //PostOrderTraversal(root);
//    cout << endl;