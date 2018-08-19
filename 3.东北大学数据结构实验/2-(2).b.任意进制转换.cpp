#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <math.h>
#include <string>
using namespace std;
#define InitSize 100
#define add 10
#define OK 1
#define ERROR 0
typedef int Elem;
typedef struct
{
    int Size;
    Elem *last;
    Elem *head;
}Shed;
int Init(Shed *S);
int Destroy(Shed *S);
int Clear(Shed *S);
int ifEmpty(Shed S);
int Length(Shed S);
int GetTop(Shed S,Elem *e);
int Push(Shed *S,Elem e);
int Pop(Shed *S,Elem *e);
int Show(Shed S);

int main()
{
    Shed S;
    Init(&S);
    Elem e;
    int n,m,a;
    int i=0;
    int j=0;
    int t=0;
    int b[50],c[50];
    char num[50];
    char base='0';
    cout << "由n进制转化为m进制,请输入n和m:";
    cin >> n >> m;
    cout << "请输入n进制数字:";
    cin >> num;
    a=strlen(num);
    for(i=0;i<a;i++)
    {
        b[i]=(Elem)num[i]-(Elem)base;
        e=(Elem)b[i];
        Push(&S,e);
    }
    while(ifEmpty(S))
    {
        Pop(&S,&e);
        t+=e*pow(n,j);
        j++;
    }
    cout << t<<endl;
    itoa(t,num,m);
    cout << num <<endl;

}

int Init(Shed *S)
{
    (*S).last = (Elem *)malloc(InitSize*sizeof(Elem));
    if(!(*S).last)
        exit(OVERFLOW);
    (*S).head = (*S).last;
    (*S).Size = InitSize;
    return OK;
}

int Destroy(Shed *S)
{
    free((*S).last);
    (*S).last = NULL;
    (*S).head = NULL;
    (*S).Size = 0;
    return OK;
}

int Clear(Shed *S)
{
    (*S).head = (*S).last;
    return OK;
}

int ifEmpty(Shed S)
{
    if(S.head==S.last)
        return 0;
    else return 1;
}

int Length(Shed S)
{
    return S.head-S.last;
}

int GetTop(Shed S,Elem *e)
{
    if(S.head==S.last)
        return ERROR;
    *e = *(S.head -1);
    return OK;

}

int Push(Shed *S,Elem e)
{
    //栈满要追加
    if((*S).head-(*S).last>=(*S).Size)
    {
        (*S).last = (Elem *)realloc((*S).last,((*S).Size+add)*sizeof(Elem));
        if(!(*S).last)
            exit(OVERFLOW);
        (*S).head = (*S).last + (*S).Size;
        (*S).Size = (*S).Size+add;
    }
    *(S->head) = e;
    (S->head)++;
    return OK;
}

int Pop(Shed *S,Elem *e)
{
    if((*S).head==(*S).last)
        return ERROR;
    (*S).head--;
    *e = *((*S).head);
    return OK;
}

int Show(Shed S)
{
    Elem *p = S.last;
    while(p<S.head)
        cout << *p++ << endl;
    return OK;
}

int residue(int res)
{
    if (res==10) res=0xa;
    if (res==11) res=0xb;
    if (res==12) res=0xc;
    if (res==13) res=0xd;
    if (res==14) res=0xe;
    if (res==15) res=0xf;
    return res;
}
