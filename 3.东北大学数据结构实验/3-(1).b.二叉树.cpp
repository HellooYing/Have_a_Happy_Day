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

        << "*1 ��ʼ�������������� *" << std::endl

        << "*2 ���������ڵ�       *" << std::endl

        << "*3 ��ӡ������������� *" << std::endl

        << "*4 �ж��Ƿ�Ϊ����     *" << std::endl

        << "*5 ����������         *" << std::endl

        << "*6 ���������         *" << std::endl

        << "*7 �鿴������ĳ���ֵ *" << std::endl

        << "*8 �޸Ķ�����ĳ���ֵ *" << std::endl

        << "*9 ��ն�����         *" << std::endl

        << "*0 ����               *" << std::endl

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
                cout << "����������'ABDG^^^EH^^I^^CF^J^^^'�Ķ�����"<< endl;
                CreateTree(T);
                cout << "�����������ɹ�!"<< endl;
                system("pause");
                break;
            case 2 :
                Root(T,&e);
                cout << "���ڵ�Ϊ:  " << e<<endl;
                system("pause");
                break;
            case 3 :
                cout << "�������������:  "<<endl;
                PreOrder(T);
                system("pause");
                break;
            case 4 :
                cout << "�Ƿ�Ϊ����:  "<<endl;
                if(ifEmpty(T))
                    cout <<"�ǿ�"<< endl;
                else
                    cout <<"��"<< endl;
                system("pause");
                break;
            case 5 :
                cout << "����������Ϊ:  "<<Length(T)<<endl;
                system("pause");
                break;
            case 6 :
                cout << "���������Ϊ:  "<<Depth(T)<<endl;
                system("pause");
                break;
            case 7 :
                p=T->lc->rc->lc;
                cout << "�鿴���ڵ�����ӽڵ�����ӽڵ�����ӽڵ������:  "<<Value(p)<< endl;
                system("pause");
                break;
            case 8 :
                p=T->lc->rc->lc;
                cout << "�޸ĸ��ڵ�����ӽڵ�����ӽڵ�����ӽڵ������ΪQ"<< endl;
                Insert(p,'Q');
                system("pause");
                break;
            case 9 :
                Clear(&T);
                cout << "��ճɹ�!" << endl;
                system("pause");
                break;
            case 10 :
                cout << "һ��չʾ..."<<endl;
                Init(&T);
                cout << "����������'ABDG^^^EH^^I^^CF^J^^^'�Ķ�����"<< endl;
                CreateTree(T);
                cout << "�����������ɹ�!"<< endl;
                Root(T,&e);
                cout << "���ڵ�Ϊ:  " << e;
                cout << "����������Ϊ:  "<<Length(T)<<endl;
                cout << "���������Ϊ:  "<<Depth(T)<<endl;
                p=T->lc->rc->lc;
                cout << "�鿴���ڵ�����ӽڵ�����ӽڵ�����ӽڵ������:  "<<Value(p)<< endl;
                cout << "�޸ĸ��ڵ�����ӽڵ�����ӽڵ�����ӽڵ������ΪQ"<< endl;
                Insert(p,'Q');
                cout << "�鿴���ڵ�����ӽڵ�����ӽڵ�����ӽڵ������:  "<<Value(p)<< endl;
                cout << "��ӡ�������������:  ";
                PreOrder(T);
                cout << "�Ƿ�Ϊ����:  ";
                if(ifEmpty(T))
                    cout <<"�ǿ�"<< endl;
                else
                    cout <<"��"<< endl;
                cout << "��ն�����" << endl;
                Clear(&T);
                cout << "��ճɹ�!" << endl;
                cout << "�Ƿ�Ϊ����:  ";
                if(ifEmpty(T))
                    cout <<"�ǿ�"<< endl;
                else
                    cout <<"��"<< endl;
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




