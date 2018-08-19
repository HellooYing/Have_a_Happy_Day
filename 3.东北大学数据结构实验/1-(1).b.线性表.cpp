#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

#define List_Init_Size 100
#define List_Increment 10
#define OK 1
#define ERROR 0
#define OVERFLOW -2

typedef int Status;
typedef int Element;

typedef struct
{
    Element *elem;
    int length;
    int listsize;
}List;

Status Init(List *L);//�������Ա�
Status InsertElem(List *L, int i, Element e);//����Ԫ��
Status Show(List *L);//��ӡ���Ա�
Status FindElem(List L, int i, Element *e);//����Ԫ��
Status DeleteElem(List *L, int i, Element *e);//ɾ��Ԫ��
void Clear(List *L);//������Ա�
void Destroy(List *L);//�������Ա�
int LocateElem(List L, Element e, Status(Compare)(Element,Element));//Ԫ��λ��
int main()
{
    while(1)
    {
        system("Cls");
        std::cout

        << "**********************" << std::endl

        << "*1 ��ʼ�����Ա�      *" << std::endl

        << "*2 ����Ԫ��          *" << std::endl

        << "*3 ��ӡ���Ա�        *" << std::endl

        << "*4 ���ҵ�i��Ԫ��     *" << std::endl

        << "*5 ɾ����i��Ԫ��     *" << std::endl

        << "*6 ������Ա�        *" << std::endl

        << "*7 �������Ա�        *" << std::endl

        << "*0 ����              *" << std::endl

        << "**********************" << std::endl

        << std::endl;
        int input,i,n;
        List L;
        Element e;
        cin >> input;
        switch(input)
        {
            case 1 :
                Init(&L);
                cout << "��ʼ���ɹ�!"<< endl;
                system("pause");
                break;
            case 2 :
                cout << "�������Ԫ����Ŀ:" ;
                cin >> n;
                for(int j=0;j<n;j++)
                {
                    cout << "Ԫ�ش���(��˳��)" << j+1<< ":";
                    cin >> i;
                    cout << "Ԫ��ֵ" << j+1 << ":";
                    cin >> e;
                    InsertElem(&L,i,e);
                }
                system("pause");
                break;
            case 3 :
                cout << "��ӡ���Ա�:";
                Show(&L);
                system("pause");
                break;
            case 4 :
                cout << "���ҵ�i��Ԫ��,������i:";
                cin >> i;
                FindElem(L,i,&e);
                cout << e << endl;
                system("pause");
                break;
            case 5 :
                cout << "ɾ����i��Ԫ��,������i:";
                cin >> i;
                DeleteElem(&L,i,&e);
                cout << e << endl;
                system("pause");
                break;
            case 6 :
                Clear(&L);
                cout << "��ճɹ�!" << endl;
                system("pause");
                break;
            case 7 :
                Destroy(&L);
                cout << "���ٳɹ�!"<< endl;
                system("pause");
                break;
            case 8 :
                cout << "һ��չʾ..."<<endl;
                Init(&L);
                cout << "��ʼ���ɹ�!"<< endl;
                cout << "�Զ�����Ԫ��1,2,3,4:"<< endl;
                InsertElem(&L,1,1);
                InsertElem(&L,2,2);
                InsertElem(&L,3,3);
                InsertElem(&L,4,4);
                cout << "����ɹ�!��ӡ���Ա�:"<< endl;
                Show(&L);
                cout << "���ҵ�2��Ԫ��,�ڶ���Ԫ��Ϊ:";
                FindElem(L,2,&e);
                cout << e << endl;
                cout << "ɾ����3��Ԫ��:"<<endl;
                DeleteElem(&L,3,&e);
                cout << "ɾ���ɹ�!ɾ����Ԫ��Ϊ:"<<endl;
                cout << e << endl;
                cout << "��ӡ���Ա�:"<<endl;
                Show(&L);
                system("pause");
                break;
            case 0 :
                return 0;
        }
}

}

Status Init(List *L)
{
    (*L).elem = (Element*)malloc(List_Init_Size*sizeof(Element));
    if(!(*L).elem)
        exit(OVERFLOW);
    (*L).length = 0;
    (*L).listsize = List_Init_Size;
    return OK;
}

Status Show(List *L)
{
    int i;
    for(i=0;i<(*L).length;i++)
        cout << (*L).elem[i]<<" ";
    cout<<endl;
}

void Clear(List *L)
{
    (*L).length = 0;
}

void Destroy(List *L)
{
    free((*L).elem);
    (*L).length = 0;
    (*L).listsize = 0;
}

Status FindElem(List L, int i, Element *e)
{
    if(i<1||i>L.length)
        return ERROR;
    else
        *e = L.elem[i-1];
    return OK;
}

int LocateElem(List L, Element e, Status(Compare)(Element,Element))
{
    int i = 1;
    while(i<=L.length&&!Compare(e,L.elem[i-1]))
        ++i;
    if(i<=L.length)
        return i;
    else
        return 0;
}

Status InsertElem(List *L, int i, Element e)
{
    Element *newbase;
    Element *p,*q;
    if(i<1||i>(*L).length+1)
        return ERROR;
    if((*L).length>=(*L).listsize)
    {
        newbase = (Element*)realloc((*L).elem, ((*L).listsize+List_Increment)*sizeof(Element));
        if(!newbase)
            exit(OVERFLOW);
        (*L).elem = newbase;
        (*L).listsize += List_Increment;
    }
    q = &(*L).elem[i-1];
    for(p = &(*L).elem[(*L).length-1];p>=q;--p)
        *(p+1) = *p;
    *q = e;
    (*L).length++;
    return OK;
}

Status DeleteElem(List *L, int i, Element *e)
{
    Element *p,*q;
    if(i<1||i>(*L).length)
        return ERROR;
    p=&(*L).elem[i-1];
    *e=*p;
    q=(*L).elem+(*L).length-1;
    for(++p;p<=q;++p)
        *(p-1)=*p;
    (*L).length--;
    return OK;
}







