#include <cstdio>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
using namespace std;

#define MAXEDGE 20
#define MAXVEX 14
#define INFINITY 65535

typedef struct
{
    int vexs[MAXVEX];
    int arc[MAXVEX][MAXVEX];
    int numVertexes, numEdges;
} MGraph;

typedef struct EdgeNode //边表结点
{
    int adjvex;    //邻接点域，存储该顶点对应的下标
    int weight;     //用于存储权值，对于非网图可以不需要
    struct EdgeNode *next; // 链域，指向下一个邻接点
} EdgeNode;

typedef struct VertexNode // 顶点表结点
{
    int in; // 顶点入度
    int data; // 顶点域，存储顶点信息
    EdgeNode *firstedge;//边表头指针
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; //图中当前顶点数和边数
} graphAdjList, *GraphAdjList;

void CreateMGraph(MGraph *G)// 构建图
{
    int i, j;

    // printf("请输入边数和顶点数:");
    G->numEdges = MAXEDGE;
    G->numVertexes = MAXVEX;

    for (i = 0; i < G->numVertexes; i++)// 初始化图
    {
        G->vexs[i] = i;
    }

    for (i = 0; i < G->numVertexes; i++)//初始化图
    {
        for ( j = 0; j < G->numVertexes; j++)
        {
            G->arc[i][j] = 0;
        }
    }

    G->arc[0][4] = 1;
    G->arc[0][5] = 1;
    G->arc[0][11] = 1;
    G->arc[1][2] = 1;
    G->arc[1][4] = 1;
    G->arc[1][8] = 1;
    G->arc[2][5] = 1;
    G->arc[2][6] = 1;
    G->arc[2][9] = 1;
    G->arc[3][2] = 1;
    G->arc[3][13] = 1;
    G->arc[4][7] = 1;
    G->arc[5][8] = 1;
    G->arc[5][12] = 1;
    G->arc[6][5] = 1;
    G->arc[8][7] = 1;
    G->arc[9][10] = 1;
    G->arc[9][11] = 1;
    G->arc[10][13] = 1;
    G->arc[12][9] = 1;

}

void CreateALGraph(MGraph G, GraphAdjList *GL)
{
    int i, j;
    EdgeNode *e;

    *GL = (GraphAdjList)malloc(sizeof(graphAdjList));

    (*GL)->numVertexes = G.numVertexes;
    (*GL)->numEdges = G.numEdges;
    for(i = 0; i < G.numVertexes; i++) //读入顶点信息，建立顶点表
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstedge = NULL;     // 将边表置为空表
    }

    for(i = 0; i < G.numVertexes; i++) // 建立边表
    {
        for(j = 0; j < G.numVertexes; j++)
        {
            if (G.arc[i][j] == 1)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;                  // 邻接序号为j
                e->next = (*GL)->adjList[i].firstedge;  // 将当前顶点上的指向的结点指针赋值给e
                (*GL)->adjList[i].firstedge = e;        //将当前顶点的指针指向e
                (*GL)->adjList[j].in++; //注意这里是j

            }
        }
    }

}
//拓扑排序，若GL无回路，则输出拓扑排序序列并返回1，若有回路返回0
bool TopologicalSort(GraphAdjList GL)
{
    EdgeNode *pe;
    int i, k, gettop;
    int top = 0;// 用于栈指针下标
    int count = 0;// 用于统计输出顶点的个数
    // 建栈将入度为0的顶点入栈
    int *stack = (int *)malloc(sizeof(GL->numVertexes * sizeof(int)));

    for (i = 0; i < GL->numVertexes; i++)
        if (0 == GL->adjList[i].in)
            stack[++top] = i;// 将入度为0的顶点入栈

    while (top != 0)
    {
        gettop = stack[top--];
        cout << GL->adjList[gettop].data << " -> ";
        count++;  /* 输出i号顶点，并计数 */
        for (pe = GL->adjList[gettop].firstedge; pe; pe = pe->next)
        {
            k = pe->adjvex;
            //将i号顶点的邻接点的入度减1，如果减1后为0，则入栈
            if (!--GL->adjList[k].in)
                stack[++top] = k;
        }
    }
    cout << endl;
    if (count < GL->numVertexes)
        return false;
    else
        return true;
}

int main(void)
{
    MGraph MG;
    GraphAdjList GL;
    CreateMGraph(&MG);
    CreateALGraph(MG, &GL);
    if (TopologicalSort(GL))
        cout << "ok" << endl;
    else
        cout << "wrong" << endl;

    return 0;
}
