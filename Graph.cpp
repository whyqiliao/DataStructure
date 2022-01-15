#pragma once

#include "Core.h";
#include "Stack/Stack.cpp";
#include "Queue/queue.cpp";

void Adjacent(ALGraph G, int x, int v, bool &isLink)
{
}
int FirstNeighbor(ALGraph G, int x)
{
    return 0;
}
int NextNeighbor(ALGraph G, int x, int y)
{
    return 0;
}

void DFS(ALGraph G, int v)
{
    int w, p;
    Sqstack s;
    InitStack(s);
    bool visted[MaxVertexNum] = {false};

    Push(s, v);
    visted[v] = true;
    while (!IsEmpty(s))
    {
        Pop(s, p);
        //visit(p);
        for (w = FirstNeighbor(G, p); w >= 0; w = NextNeighbor(G, p, w))
        {
            if (!visted[w])
            {
                Push(s, w);
                visted[w] = true;
            }
        }
    }
}

void BFS(ALGraph G, int v)
{
    int w, p;
    SqQueue q;
    InitQueue(q);
    bool visted[MaxVertexNum] = {false};

    EnQueue(q, v);
    while (!IsEmpty(q))
    {
        DeQueue(q, p);
        visted[p] = true;
        for (w = FirstNeighbor(G, p); w >= 0; w = NextNeighbor(G, p, w))
        {
            if(!visted[w])
            {
                EnQueue(q,w);
                //visit(v);
                visted[w]=true;
            }
        }
    }
}