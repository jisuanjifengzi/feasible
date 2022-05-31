#include<iostream>
using namespace std;
struct secondtree {
    char data;
    secondtree* lchild, * rchild;
};
void creattree(secondtree** T) {
    char ch;
    cin >> ch;
    if (ch == '#')//如果是#号就说明这个地方没有数据，直接用一个空指针代替就可以了
        *T = NULL;
    else {
        *T = (secondtree*)malloc(sizeof(secondtree));
        (*T)->data = ch;
        creattree(&((*T)->lchild));//先创建左结点再创建右结点
        creattree(&((*T)->rchild));
    }
}
//int allsizes(secondtree* root) {
//    if (root == NULL)  return 0;
//    int left = allsizes(root->lchild);
//    int right = allsizes(root->rchild);
//    return left + right + 1;
//}
//后序遍历
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
////前序遍历
//void PreOrderTraversal(BiNode* BT) {
//    if (BT) {
//        cout << BT->data << "  ";
//        //左子树遍历完成之后才会继续往下走
//        PreOrderTraversal(BT->lchild);
//        //这一步和上一步不是并列关系，必须等上一步执行完，才会往下走
//        //当然，既然是递归，在左子树遍历的时候，在那里面又会遍历左子树节点的右子树
//        PreOrderTraversal(BT->rchild);
//    }
//}
////中序遍历
//void InOrderTraversal(BiNode* BT) {
//    if (BT) {
//        InOrderTraversal(BT->lchild);
//        cout << BT->data << "  ";
//        InOrderTraversal(BT->rchild);
//    }
//}
//
//后序遍历

////访问二叉树，不需要改变它什么，直接传root进去即可。
//    //PreOrderTraversal(root);
//    cout << endl;
//   /* InOrderTraversal(root);*/
//    cout << endl;
//    //PostOrderTraversal(root);
//    cout << endl;