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

        << "*1 初始化栈            *" << std::endl

        << "*2 入栈                *" << std::endl

        << "*3 打印栈              *" << std::endl

        << "*4 判断是否为空栈      *" << std::endl

        << "*5 出栈                *" << std::endl

        << "*6 获取栈顶元素        *" << std::endl

        << "*7 获取栈长            *" << std::endl

        << "*8 清空栈              *" << std::endl

        << "*9 销毁栈              *" << std::endl

        << "*0 结束                *" << std::endl

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
                cout << "初始化成功!"<< endl;
                system("pause");
                break;
            case 2 :
                cout << "入栈元素数目:" ;
                cin >> n;
                for(int j=0;j<n;j++)
                {
                    cout << "元素" << j+1 << ":";
                    cin >> e;
                    Push(&S,e);
                }
                system("pause");
                break;
            case 3 :
                cout << "打印栈:";
                Show(S);
                system("pause");
                break;
            case 4 :
                cout << "判断是否为空栈:";
                if(ifEmpty(S))
                    cout <<"非空"<< endl;
                else
                    cout <<"空"<< endl;
                system("pause");
                break;
            case 5 :
                cout << "出栈:";
                Pop(&S,&e);
                cout <<"出栈元素为:"<< e << endl;
                system("pause");
                break;
            case 6 :
                GetTop(S,&e);
                cout << "栈顶元素为:" << e << endl;
                system("pause");
                break;
            case 7 :
                i = Length(S);
                cout << "栈长:"<< i << endl;
                system("pause");
                break;
            case 8 :
                Clear(&S);
                cout << "清空成功!" << endl;
                system("pause");
                break;
            case 9 :
                Destroy(&S);
                cout << "销毁成功!"<< endl;
                system("pause");
                break;
            case 10 :
                cout << "一键展示..."<<endl;
                Init(&S);
                cout << "初始化成功!"<< endl;
                cout << "自动入栈1,2,3,4:"<< endl;
                Push(&S,1);
                Push(&S,2);
                Push(&S,3);
                Push(&S,4);
                cout << "入栈成功!打印栈:"<< endl;
                Show(S);
                cout << "判断是否为空栈:";
                if(ifEmpty(S))
                    cout <<"非空"<< endl;
                else
                    cout <<"空"<< endl;
                cout << "出栈:";
                Pop(&S,&e);
                cout <<"出栈元素为:"<< e << endl;
                cout << "打印栈:"<<endl;
                Show(S);
                GetTop(S,&e);
                cout << "栈顶元素为:" << e << endl;
                i = Length(S);
                cout << "栈长:"<< i << endl;
                cout << "清空栈" << endl;
                Clear(&S);
                cout << "清空成功!" << endl;
                i = Length(S);
                cout <<"此时栈长:"<< i << endl;
                cout << "销毁栈"<< endl;
                Destroy(&S);
                cout << "销毁成功!"<< endl;
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
