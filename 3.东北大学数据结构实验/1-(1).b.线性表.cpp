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

Status Init(List *L);//创建线性表
Status InsertElem(List *L, int i, Element e);//插入元素
Status Show(List *L);//打印线性表
Status FindElem(List L, int i, Element *e);//查找元素
Status DeleteElem(List *L, int i, Element *e);//删除元素
void Clear(List *L);//清空线性表
void Destroy(List *L);//销毁线性表
int LocateElem(List L, Element e, Status(Compare)(Element,Element));//元素位序
int main()
{
    while(1)
    {
        system("Cls");
        std::cout

        << "**********************" << std::endl

        << "*1 初始化线性表      *" << std::endl

        << "*2 插入元素          *" << std::endl

        << "*3 打印线性表        *" << std::endl

        << "*4 查找第i个元素     *" << std::endl

        << "*5 删除第i个元素     *" << std::endl

        << "*6 清空线性表        *" << std::endl

        << "*7 销毁线性表        *" << std::endl

        << "*0 结束              *" << std::endl

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
                cout << "初始化成功!"<< endl;
                system("pause");
                break;
            case 2 :
                cout << "本次添加元素数目:" ;
                cin >> n;
                for(int j=0;j<n;j++)
                {
                    cout << "元素次序(按顺序)" << j+1<< ":";
                    cin >> i;
                    cout << "元素值" << j+1 << ":";
                    cin >> e;
                    InsertElem(&L,i,e);
                }
                system("pause");
                break;
            case 3 :
                cout << "打印线性表:";
                Show(&L);
                system("pause");
                break;
            case 4 :
                cout << "查找第i个元素,请输入i:";
                cin >> i;
                FindElem(L,i,&e);
                cout << e << endl;
                system("pause");
                break;
            case 5 :
                cout << "删除第i个元素,请输入i:";
                cin >> i;
                DeleteElem(&L,i,&e);
                cout << e << endl;
                system("pause");
                break;
            case 6 :
                Clear(&L);
                cout << "清空成功!" << endl;
                system("pause");
                break;
            case 7 :
                Destroy(&L);
                cout << "销毁成功!"<< endl;
                system("pause");
                break;
            case 8 :
                cout << "一键展示..."<<endl;
                Init(&L);
                cout << "初始化成功!"<< endl;
                cout << "自动插入元素1,2,3,4:"<< endl;
                InsertElem(&L,1,1);
                InsertElem(&L,2,2);
                InsertElem(&L,3,3);
                InsertElem(&L,4,4);
                cout << "插入成功!打印线性表:"<< endl;
                Show(&L);
                cout << "查找第2个元素,第二个元素为:";
                FindElem(L,2,&e);
                cout << e << endl;
                cout << "删除第3个元素:"<<endl;
                DeleteElem(&L,3,&e);
                cout << "删除成功!删除的元素为:"<<endl;
                cout << e << endl;
                cout << "打印线性表:"<<endl;
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







