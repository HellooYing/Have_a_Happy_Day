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

typedef struct EdgeNode //�߱���
{
    int adjvex;    //�ڽӵ��򣬴洢�ö����Ӧ���±�
    int weight;     //���ڴ洢Ȩֵ�����ڷ���ͼ���Բ���Ҫ
    struct EdgeNode *next; // ����ָ����һ���ڽӵ�
} EdgeNode;

typedef struct VertexNode // �������
{
    int in; // �������
    int data; // �����򣬴洢������Ϣ
    EdgeNode *firstedge;//�߱�ͷָ��
} VertexNode, AdjList[MAXVEX];

typedef struct
{
    AdjList adjList;
    int numVertexes, numEdges; //ͼ�е�ǰ�������ͱ���
} graphAdjList, *GraphAdjList;

void CreateMGraph(MGraph *G)// ����ͼ
{
    int i, j;

    // printf("����������Ͷ�����:");
    G->numEdges = MAXEDGE;
    G->numVertexes = MAXVEX;

    for (i = 0; i < G->numVertexes; i++)// ��ʼ��ͼ
    {
        G->vexs[i] = i;
    }

    for (i = 0; i < G->numVertexes; i++)//��ʼ��ͼ
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
    for(i = 0; i < G.numVertexes; i++) //���붥����Ϣ�����������
    {
        (*GL)->adjList[i].in = 0;
        (*GL)->adjList[i].data = G.vexs[i];
        (*GL)->adjList[i].firstedge = NULL;     // ���߱���Ϊ�ձ�
    }

    for(i = 0; i < G.numVertexes; i++) // �����߱�
    {
        for(j = 0; j < G.numVertexes; j++)
        {
            if (G.arc[i][j] == 1)
            {
                e = (EdgeNode *)malloc(sizeof(EdgeNode));
                e->adjvex = j;                  // �ڽ����Ϊj
                e->next = (*GL)->adjList[i].firstedge;  // ����ǰ�����ϵ�ָ��Ľ��ָ�븳ֵ��e
                (*GL)->adjList[i].firstedge = e;        //����ǰ�����ָ��ָ��e
                (*GL)->adjList[j].in++; //ע��������j

            }
        }
    }

}
//����������GL�޻�·������������������в�����1�����л�·����0
bool TopologicalSort(GraphAdjList GL)
{
    EdgeNode *pe;
    int i, k, gettop;
    int top = 0;// ����ջָ���±�
    int count = 0;// ����ͳ���������ĸ���
    // ��ջ�����Ϊ0�Ķ�����ջ
    int *stack = (int *)malloc(sizeof(GL->numVertexes * sizeof(int)));

    for (i = 0; i < GL->numVertexes; i++)
        if (0 == GL->adjList[i].in)
            stack[++top] = i;// �����Ϊ0�Ķ�����ջ

    while (top != 0)
    {
        gettop = stack[top--];
        cout << GL->adjList[gettop].data << " -> ";
        count++;  /* ���i�Ŷ��㣬������ */
        for (pe = GL->adjList[gettop].firstedge; pe; pe = pe->next)
        {
            k = pe->adjvex;
            //��i�Ŷ�����ڽӵ����ȼ�1�������1��Ϊ0������ջ
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
