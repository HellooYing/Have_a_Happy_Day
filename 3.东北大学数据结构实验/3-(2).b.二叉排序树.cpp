#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<windows.h>

using namespace std;
typedef struct Node
{
    int data;
    struct Node* lc;
    struct Node* rc;
}Node,*tree;

bool create1(Node* &p,int e)
{
    if(p==NULL)
    {
        p=new Node;
        p->data=e;
        p->lc=p->rc=NULL;
        return true;
    }
    if(e==p->data)
        return false;
    if(e<p->data)
        return create1(p->lc,e);
    return create1(p->rc,e);
}

void create2(Node* &T,int a[], int n)
{
    T=NULL;
    int i;
    for(i=0;i<n;i++)
    {
        create1(T,a[i]);
    }
}

void pre(tree T)
{
    if(T)
        {
            cout << T->data << " ";
            pre(T->lc);
            pre(T->rc);
        }
}

void in(tree T)
{
    if(T)
    {
        in(T->lc);
        cout<< T->data<<" ";
        in(T->rc);
    }
}

void bac(tree T)
{
    if(T)
    {
        bac(T->lc);
        bac(T->rc);
        cout<< T->data<<" ";
    }
}

int main()
{
    while(1)
    {
        system("Cls");
        std::cout

        << "************************" << std::endl

        << "*预设二叉树为:         *" << std::endl

        << "*4210^^^3^^5^976^^8^^^ *" << std::endl

        << "*1 先序遍历二叉树      *" << std::endl

        << "*2 中序遍历二叉树      *" << std::endl

        << "*3 后序遍历二叉树      *" << std::endl

        << "*0 结束                *" << std::endl

        << "************************" << std::endl

        << std::endl;
        int input;
        int a[10]={4,5,2,1,0,9,3,7,6,8};
        int n=10;
        tree T;
        create2(T,a,n);
        cin >> input;
        switch(input)
        {
            case 1 :
                pre(T);
                cout<<endl;
                system("pause");
                break;
            case 2 :
                in(T);
                cout<<endl;
                system("pause");
                break;
            case 3 :
                bac(T);
                cout<<endl;
                system("pause");
                break;
            case 4 :
                cout << "一键展示..."<<endl;
                cout << "先序:";
                pre(T);
                cout<<endl;
                cout << "中序:";
                in(T);
                cout<<endl;
                cout << "后序:";
                bac(T);
                cout<<endl;
                system("pause");
                break;
            case 0 :
                return 0;
        }
}
}

















