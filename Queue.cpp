#pragma once

#include "Core.h"
#include <iostream>
//顺序队例子为循环队列
//初始化队
void InitQueue(SqQueue &q)
{
    q.rear = q.front = 0;
}
//判断队空
bool IsEmpty(SqQueue q)
{
    if (q.rear == q.front)
        return true;
    else
        return false;
}
//入队
bool EnQueue(SqQueue &q, int x)
{
    if (q.rear + 1 == q.front)
        return false;
    q.data[q.rear] = x;
    q.rear = (q.rear + 1) % MaxSize;
}
//出队
bool DeQueue(SqQueue &q, int &x)
{
    if (q.rear == q.front)
        return false;
    x = q.data[q.front];
    q.front = (q.front + 1) % MaxSize;
    return true;
}

//链队例子
//初始化队
void InitQueue(LinkQueue &q)
{
    q.front = q.rear = new LinkNode;
    q.front->next = nullptr;
}
//判断队空
bool IsEmpty(LinkQueue q)
{
    if (q.front = q.rear)
        return true;
    else
        return false;
}
//入队
void EnQueue(LinkQueue &q, int x)
{
    LinkNode *s=new LinkNode;
    s->data=x;s->next=nullptr;
    q.rear->next=s;
    q.rear=s;
}
//出队
bool DeQueue(LinkQueue &q,int x)
{
    if(q.front==q.rear) return false; //空队
    LinkNode *p=q.front->next;
    x=p->data;
    q.front->next=p->next;
    if(q.rear==p)
        q.rear=q.front;     //原队列中只有一个节点
    free(p);
    return true;
}

