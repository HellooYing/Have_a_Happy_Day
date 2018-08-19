#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <windows.h>
#include <time.h>
using namespace std;
struct Node
{
    int id;
    Node *next;
};
void Insert();
void OneKeyInsert();
int main()
{
    cout << "有向图的邻接表储存" << endl;
    OneKeyInsert();
}
void Insert()
{
    Node Z[10],*p;
    int m,n,i,j,t;
    cout << "请输入顶点数:";
    cin >> n;
    cout << "请输入边数:";
    cin >> m;
    for(i=1;i<=n;i++)
    {
        p=&Z[i];
        for(j=1;j<=n;j++)
        {
            if(j==i) continue;
            cout << "顶点"<<i<<"是否有边指向顶点"<<j<<"?(1/0):"<<endl;
            cin >> t;
            if(t==1)
            {
                Node *s=(Node *)malloc(sizeof(Node));
                p->next=s;
                s->id=j;
                p=p->next;
            }
            p->next=NULL;
        }
    }
    for(i=1;i<=n;i++)
    {
        cout << i << "->";
        p=&Z[i];
        while(p->next!=NULL)
        {
            p=p->next;
            cout << p->id << "->";
        }
        cout << endl;
    }
}
void OneKeyInsert()
{
    Node Z[10];
    Node *p=(Node *)malloc(sizeof(Node));
    int n,i,j,t;
    srand((unsigned)time(NULL));
    cout << "请输入顶点数:";
    n=4;
    cout << n << endl;
    for(i=1;i<=n;i++)
    {
        p=&Z[i];
        p->id=i;
        for(j=1;j<=n;j++)
        {
            if(j==i) continue;
            cout << "顶点"<<i<<"是否有边指向顶点"<<j<<"?(1/0):"<<endl;
            t=rand()%2;
            cout << t <<endl;
            if(t==1)
            {
                Node *s=(Node *)malloc(sizeof(Node));
                s->id=j;
                p->next=s;
                p=p->next;
            }
        }
        p->next=NULL;
    }

    for(i=1;i<=n;i++)
    {
        cout << i << "->";
        p=&Z[i];
        while(p->next!=NULL)
        {
            p=p->next;
            cout << p->id << "->";
        }
        cout << endl;
    }
}
