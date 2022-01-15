#pragma once

#include "Core.h"

//O(n)顺序表插入 平均移动结点n/2次
bool ListInsert(SeqList &L, int i, int e)
{
    if (i < 1 || i > L.length + 1)
        return false;
    if (L.length >= MaxSize)
        return false;
    for (int j = L.length; j >= i; j--)
    {
        L.data[j] = L.data[j - 1];
    }
    L.data[i - 1] = e;
    L.length++;
    return true;
}

//O(n)顺序表删除 平均移动结点(n-1)/2次
bool ListDelete(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length)
    {
        return false;
    }
    e = L.data[i - 1];
    for (int j = i; j < L.length; j++)
    {
        L.data[j - 1] = L.data[j];
    }
    L.length--;
    return true;
}
//O(n)顺序表查找 平均比较结点(n+1)/2次
int LocateElem(SqList L, int e)
{
    int i;
    for (i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
        {
            return i + 1;
        }
    }
    return 0;
}

//链表原地逆置(头插法)
LinkList Reverse_1(LinkList L)
{
    LNode *p, *r;
    p = L->next;
    L->next = nullptr;
    while (p != nullptr)
    {
        r = p->next;
        p->next = L->next;
        L->next = p;
        p = r;
    }
    return L;
}

LinkList Reverse_2(LinkList L)
{
    LNode *pre, *p, *r;
    p = L->next;
    r = p->next;
    p->next = nullptr;
    while (r != nullptr)
    {
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

//求并集
void MergeList(LinkList &La, LinkList &Lb)
{
    LNode *pa = La->next;
    LNode *pb = Lb->next;
    LNode *q;
    La->next = nullptr;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            q = pa->next;
            pa->next = La->next;
            La->next = pa;
            pa = q;
        }
        else
        {
            q = pb->next;
            pb->next = La->next;
            La->next = pb;
            pb = q;
        }
    }
    if (pa)
        pb = pa;
    while (pb)
    {
        q = pb->next;
        pb->next = La->next;
        La->next = pb;
        pb = q;
    }
    delete (Lb);
}

//求交集
LinkList UnionList(LinkList &La, LinkList &Lb)
{
    LNode *pa=La->next;
    LNode *pb=Lb->next;
    LNode *r=La,*q;
    while (pa&&pb)
    {
        if(pa->data==pb->data){
            r->next=pa;
            r=pa;
            pa=pa->next;

            q=pb;
            pb=pb->next;
            delete(q);
        }
        else if (pa->data>pb->data)
        {
            q=pb;
            pb=pb->next;
            delete(q);
        }
        else{
            q=pa;
            pa=pa->next;
            delete(q);
        }
        while (pa)
        {
            q=pa;
            pa=pa->next;
            delete(q);
        }
        while (pb)
        {
            q=pb;
            pb=pb->next;
            delete(q);
        }
        r->next=nullptr;
        delete(Lb);
        return La;
    }
    
}

//二分查找 -1查找失败
int BinarySearch(SeqList L, int key)
{
    int low = 0, mid, high = L.length - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (L.data[mid] == key)
            return mid;
        else if (L.data[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

//串简单模式匹配
int Index(string S, string T)
{
    int i = 1, j = 1;
    while (i <= S.length() && j <= T.length())
    {
        if (S[i] == T[j])
            ++i, ++j;
        else
            i = i - j + 2;
        j = 1;
    }
    if (j > T.length())
        return i - T.length();
    else
        return 0;
}