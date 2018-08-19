#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <string>
using namespace std;
#define OK 1
#define ERROR 0
typedef struct Node
{
    char data;
    struct Node* lc;
    struct Node* rc;
}Node;

typedef Node* Tree;

struct thisNode
{
    Tree left;
    Tree right;
    int n;
};

void Init(Tree *T);
void Clear(Tree *T);
bool ifEmpty(Tree T);
void CreateTree(Tree &T);
int Length(Tree T);
int Depth(Tree T);
int Root(Tree T,char *e);
char Value(Tree p);
void Insert(Tree p,char value);
void PreOrder(Tree T);
int main()
{
    while(1)
    {
        system("Cls");
        std::cout

        << "**********************" << std::endl

        << "*1 初始化并创建二叉树 *" << std::endl

        << "*2 二叉树根节点       *" << std::endl

        << "*3 打印先序二叉树序列 *" << std::endl

        << "*4 判断是否为空树     *" << std::endl

        << "*5 二叉树长度         *" << std::endl

        << "*6 二叉树深度         *" << std::endl

        << "*7 查看二叉树某点的值 *" << std::endl

        << "*8 修改二叉树某点的值 *" << std::endl

        << "*9 清空二叉树         *" << std::endl

        << "*0 结束               *" << std::endl

        << "**********************" << std::endl

        << std::endl;
        int input,i,n;
        Tree T;
        Tree p;
        char e;
        cin >> input;
        switch(input)
        {
            case 1 :
                Init(&T);
                cout << "请输入形如'ABDG^^^EH^^I^^CF^J^^^'的二叉树"<< endl;
                CreateTree(T);
                cout << "创建二叉树成功!"<< endl;
                system("pause");
                break;
            case 2 :
                Root(T,&e);
                cout << "根节点为:  " << e<<endl;
                system("pause");
                break;
            case 3 :
                cout << "先序二叉树序列:  "<<endl;
                PreOrder(T);
                system("pause");
                break;
            case 4 :
                cout << "是否为空树:  "<<endl;
                if(ifEmpty(T))
                    cout <<"非空"<< endl;
                else
                    cout <<"空"<< endl;
                system("pause");
                break;
            case 5 :
                cout << "二叉树长度为:  "<<Length(T)<<endl;
                system("pause");
                break;
            case 6 :
                cout << "二叉树深度为:  "<<Depth(T)<<endl;
                system("pause");
                break;
            case 7 :
                p=T->lc->rc->lc;
                cout << "查看根节点的左子节点的右子节点的左子节点的名称:  "<<Value(p)<< endl;
                system("pause");
                break;
            case 8 :
                p=T->lc->rc->lc;
                cout << "修改根节点的左子节点的右子节点的左子节点的名称为Q"<< endl;
                Insert(p,'Q');
                system("pause");
                break;
            case 9 :
                Clear(&T);
                cout << "清空成功!" << endl;
                system("pause");
                break;
            case 10 :
                cout << "一键展示..."<<endl;
                Init(&T);
                cout << "请输入形如'ABDG^^^EH^^I^^CF^J^^^'的二叉树"<< endl;
                CreateTree(T);
                cout << "创建二叉树成功!"<< endl;
                Root(T,&e);
                cout << "根节点为:  " << e;
                cout << "二叉树长度为:  "<<Length(T)<<endl;
                cout << "二叉树深度为:  "<<Depth(T)<<endl;
                p=T->lc->rc->lc;
                cout << "查看根节点的左子节点的右子节点的左子节点的名称:  "<<Value(p)<< endl;
                cout << "修改根节点的左子节点的右子节点的左子节点的名称为Q"<< endl;
                Insert(p,'Q');
                cout << "查看根节点的左子节点的右子节点的左子节点的名称:  "<<Value(p)<< endl;
                cout << "打印先序二叉树序列:  ";
                PreOrder(T);
                cout << "是否为空树:  ";
                if(ifEmpty(T))
                    cout <<"非空"<< endl;
                else
                    cout <<"空"<< endl;
                cout << "清空二叉树" << endl;
                Clear(&T);
                cout << "清空成功!" << endl;
                cout << "是否为空树:  ";
                if(ifEmpty(T))
                    cout <<"非空"<< endl;
                else
                    cout <<"空"<< endl;
                system("pause");
                break;
            case 0 :
                return 0;
        }
}
}

void Init(Tree *T)
{
    *T = NULL;
}

void Clear(Tree *T)
{
    if(*T)
    {
        if((*T)->lc)
            Clear(&((*T)->lc));
        if((*T)->rc)
            Clear(&((*T)->rc));
        free(*T);
        *T = NULL;
    }
}

bool ifEmpty(Tree T)
{
    return T==NULL?0:1;
}


void CreateTree(Tree &T)
{
    char c;
    cin >> c;
    if('^' == c)
        T = NULL;
    else
    {
        T = (Tree)malloc(sizeof(Node));
        T->data = c;
        CreateTree(T->lc);
        CreateTree(T->rc);
    }
}

int Length(Tree T)
{
    thisNode node[100];
    int i,len;
    i=len=0;
    if(T)
    {
        node[i].left = T->lc;
        node[i].right = T->rc;
        node[i].n = 1;
        if(node[i].n>len)
            len=node[i].n;
        while(i>=0)
        {
            while(node[i].left)
            {
                node[i+1].left=node[i].left->lc;
                node[i+1].right=node[i].left->rc;
                node[i+1].n=2*node[i].n;
                node[i].left=NULL;
                i++;
                if(node[i].n>len)
                    len=node[i].n;
            }
            if(node[i].right)
            {
                node[i+1].left=node[i].right->lc;
                node[i+1].right=node[i].right->rc;
                node[i+1].n=2*node[i].n+1;
                node[i].right=NULL;
                i++;
                if(node[i].n>len)
                    len=node[i].n;
            }
            if(node[i].left==NULL&&node[i].right==NULL)
                i--;
        }
    }
    return len;
}

int Depth(Tree T)
{
    int ld,rd;
    if(T==NULL)
        return 0;
    else
    {
        ld=Depth(T->lc);
        rd=Depth(T->rc);
        return (ld>=rd?ld:rd)+1;
    }
}

int Root(Tree T,char *e)
{
    if(!T)
        return ERROR;
    else
    {
        *e=T->data;
        return OK;
    }
}

char Value(Tree p)
{
    return p->data;
}

void Insert(Tree p,char value)
{
    p->data = value;
}

void PreOrder(Tree T)
{
    if(T!=NULL)
    {
        cout<<T->data<<" ";
        PreOrder(T->lc);
        PreOrder(T->rc);
    }
}




