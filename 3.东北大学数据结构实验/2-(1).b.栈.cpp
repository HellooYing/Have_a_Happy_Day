#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;
#define InitSize 100
#define add 10
#define OVERFLOW -2
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
    while(1)
    {
        system("Cls");
        std::cout

        << "**********************" << std::endl

        << "*1 ��ʼ��ջ            *" << std::endl

        << "*2 ��ջ                *" << std::endl

        << "*3 ��ӡջ              *" << std::endl

        << "*4 �ж��Ƿ�Ϊ��ջ      *" << std::endl

        << "*5 ��ջ                *" << std::endl

        << "*6 ��ȡջ��Ԫ��        *" << std::endl

        << "*7 ��ȡջ��            *" << std::endl

        << "*8 ���ջ              *" << std::endl

        << "*9 ����ջ              *" << std::endl

        << "*0 ����                *" << std::endl

        << "**********************" << std::endl

        << std::endl;
        int input,i,n;
        Shed S;
        Elem e;
        cin >> input;
        switch(input)
        {
            case 1 :
                Init(&S);
                cout << "��ʼ���ɹ�!"<< endl;
                system("pause");
                break;
            case 2 :
                cout << "��ջԪ����Ŀ:" ;
                cin >> n;
                for(int j=0;j<n;j++)
                {
                    cout << "Ԫ��" << j+1 << ":";
                    cin >> e;
                    Push(&S,e);
                }
                system("pause");
                break;
            case 3 :
                cout << "��ӡջ:";
                Show(S);
                system("pause");
                break;
            case 4 :
                cout << "�ж��Ƿ�Ϊ��ջ:";
                if(ifEmpty(S))
                    cout <<"�ǿ�"<< endl;
                else
                    cout <<"��"<< endl;
                system("pause");
                break;
            case 5 :
                cout << "��ջ:";
                Pop(&S,&e);
                cout <<"��ջԪ��Ϊ:"<< e << endl;
                system("pause");
                break;
            case 6 :
                GetTop(S,&e);
                cout << "ջ��Ԫ��Ϊ:" << e << endl;
                system("pause");
                break;
            case 7 :
                i = Length(S);
                cout << "ջ��:"<< i << endl;
                system("pause");
                break;
            case 8 :
                Clear(&S);
                cout << "��ճɹ�!" << endl;
                system("pause");
                break;
            case 9 :
                Destroy(&S);
                cout << "���ٳɹ�!"<< endl;
                system("pause");
                break;
            case 10 :
                cout << "һ��չʾ..."<<endl;
                Init(&S);
                cout << "��ʼ���ɹ�!"<< endl;
                cout << "�Զ���ջ1,2,3,4:"<< endl;
                Push(&S,1);
                Push(&S,2);
                Push(&S,3);
                Push(&S,4);
                cout << "��ջ�ɹ�!��ӡջ:"<< endl;
                Show(S);
                cout << "�ж��Ƿ�Ϊ��ջ:";
                if(ifEmpty(S))
                    cout <<"�ǿ�"<< endl;
                else
                    cout <<"��"<< endl;
                cout << "��ջ:";
                Pop(&S,&e);
                cout <<"��ջԪ��Ϊ:"<< e << endl;
                cout << "��ӡջ:"<<endl;
                Show(S);
                GetTop(S,&e);
                cout << "ջ��Ԫ��Ϊ:" << e << endl;
                i = Length(S);
                cout << "ջ��:"<< i << endl;
                cout << "���ջ" << endl;
                Clear(&S);
                cout << "��ճɹ�!" << endl;
                i = Length(S);
                cout <<"��ʱջ��:"<< i << endl;
                cout << "����ջ"<< endl;
                Destroy(&S);
                cout << "���ٳɹ�!"<< endl;
                system("pause");
                break;
            case 0 :
                return 0;
        }
}

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
    //ջ��Ҫ׷��
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
