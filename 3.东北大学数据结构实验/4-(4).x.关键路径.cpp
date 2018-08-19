#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

const int MAXN = 1010;
const int MAXM = 10010;

struct Edge
{
    int v, w;
    int id;
    int next;
}edge[MAXM];

int n, m;
int cnt;

int first[MAXN], topo[MAXN];
int ind[MAXN], outd[MAXN];
int tot;
int Ee[MAXN], El[MAXN], E[MAXN], L[MAXN];
//Ee表示事件最早可能发生时间，El表示事件最迟允许发生时间
//E表示活动最早可能发生时间，L表示活动最迟允许发生时间

void init()
{
    cnt = 0;
    tot = 0;
    memset(first, -1, sizeof(first));
    memset(ind, 0, sizeof(ind));
    memset(outd, 0, sizeof(outd));
    memset(Ee, 0, sizeof(Ee));
    memset(E, 0, sizeof(E));
    memset(L, 0, sizeof(L));
}

void read_graph(int u, int v, int w, int id)
{
    edge[cnt].v = v, edge[cnt].w = w, edge[cnt].id = id;
    edge[cnt].next = first[u], first[u] = cnt++;
}

void toposort() //拓扑排序
{
    queue<int> q;
    for(int i = 0; i < n; i++) if(!ind[i]) q.push(i);
    while(!q.empty())
    {
        int x = q.front(); q.pop();
        topo[++tot] = x;
        for(int e = first[x]; e != -1; e = edge[e].next)
        {
            int v = edge[e].v, w = edge[e].w;
            if(--ind[v] == 0) q.push(v);
            if(Ee[v] < Ee[x] + w) //求出各个顶点Ee值
            {
                Ee[v] = Ee[x] + w;
            }
        }
    }
}

void CriticalPath()
{
    toposort();
    int top = tot;
    int Max = 0;
    for(int i = 0; i < n; i++) Max = max(Max, Ee[i]); //注意，初始化时为Ee中的最大值，否则会报错。
    for(int i = 0; i < n; i++) El[i] = Max;
    while(top) //逆拓扑排序求顶点El的值
    {
        int x = topo[top--];
        for(int e = first[x]; e != -1; e = edge[e].next)
        {
            int v = edge[e].v, w = edge[e].w;
            if(El[x] > El[v] - w)
            {
                El[x] = El[v] - w;
            }
        }
    }
    for(int u = 0; u < n; u++) //求出E,L关键活动
    {
        for(int e = first[u]; e != -1; e = edge[e].next)
        {
            int v = edge[e].v, id = edge[e].id, w = edge[e].w; //id代表活动的标号
            E[id] = Ee[u], L[id] = El[v] - w;
            if(E[id] == L[id]) //相等一定是关键活动
            {
                printf("a%d : %d->%d\n", id, u, v);
            }
        }
    }
}

void read_case()
{
    init();
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        read_graph(u, v, w, i); //read_graph
        outd[u]++, ind[v]++;
    }
}

int main()
{
    while(~scanf("%d%d", &n, &m))
    {
        read_case();
        printf("\n关键路径为:\n");
        CriticalPath();
    }
    return 0;
}


/*
input :
9 11
0 1 6
0 2 4
0 3 5
1 4 1
2 4 5
3 5 2
4 6 9
4 7 7
5 7 4
6 8 2
7 8 4
*/

/*
output:
a2 : 0->2  //a1 : 0->1
a5 : 2->4 //a4 : 1->4
a8 : 4->7
a7 : 4->6
a10 : 6->8
a11 : 7->18
*/
