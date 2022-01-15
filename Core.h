#pragma once

#define MaxSize 100
#define MaxVertexNum 100

#include <string>
#include <cstring>
using std::string;
//<string.h>是旧c标准
//<string>是c++标准，里面有std::string
//<cstring>是c++库里面包含的旧c标准，等同<string.h>
//要使用std::string则用<string>加<string.h>和<cstring>中二选一，并指定使用std命名空间下的string

//链式二叉树存储结构
typedef struct BTNode
{
    char data; //储存内容的默认类型
    struct BTNode *lchild;
    struct BTNode *rchild;
} BTNode;

//线索二叉树节点
typedef struct TBTNode
{
    char data;
    int ltag, rtag; //线索标记，0为指针，1为线索
    TBTNode *lchild;
    TBTNode *rchild;
} TBTNode;

//定义一个顺序非循环队列用于储存节点所在的层号
typedef struct
{
    BTNode *p; //节点指针
    int lno;   //节点所在层号
} St;

//顺序表
typedef struct SqList
{
    int data[MaxSize];
    int length;
} SqList;
//动态分配空间顺序表
typedef struct SeqList
{
    int *data;
    int maxsize, length;
} SeqList;

//单链表
typedef struct LNode
{
    int data;
    struct LNode *next;
} LNode, *LinkList;

//双链表
typedef struct DNode
{
    int data;
    struct DNode *prior, *next;
} DNode, *DLinkList;

//静态链表
typedef struct SLinkList
{
    int data;
    int next;
} SLinkList[MaxSize];

//顺序栈
typedef struct SqStack
{
    int data[MaxSize];
    int top;
} Sqstack;
//链栈
typedef struct LiStack
{
    int data;
    LinkNode *next;
} * LiStack;

//顺序队
typedef struct SqQueue
{
    int data[MaxSize];
    int front, rear;
} SqQueue;
//链队
typedef struct LinkNode
{
    int data;
    LinkNode *next;
} LinkNode;
typedef struct LinkQueue
{
    LinkNode *front, *rear;
} LinkQueue;

//图邻接矩阵
typedef char VertexType;
typedef int EdgeType;
typedef int InfoType;
typedef struct MGraph
{
    VertexType Vex[MaxVertexNum];
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
    int vexnum, arcnum;
} MGraph;

//图邻接表矩阵
typedef struct ArcNode
{
    int adjvex;
    struct ArcNode *next;
    InfoType info;
} ArcNode;
typedef struct Vnode
{
    VertexType data;
    ArcNode *first;
} Vnode, AdjList[MaxVertexNum];
typedef struct ALGraph
{
    AdjList vertices;
    int vexnum, arcnum;
} ALGraph;
