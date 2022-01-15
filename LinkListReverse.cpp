#pragma once

#include<iostream>
#include<list>
typedef struct mynode
{
    int data;
    struct mynode *next;
}mynode;
int main()
{
    std::list<mynode> mylist;
    mynode *p1=new mynode();
    mynode *p2=new mynode();
    p1->data=100;
    p2->data=0;
    mylist.empty();
    mylist.push_back(*p1);
    mylist.push_back(*p2);
    std::list<mynode>::iterator iter_mynode;
    for (iter_mynode=mylist.begin();iter_mynode!=mylist.end();iter_mynode++)
    {
        std::cout<<iter_mynode->data<<std::endl;
    }
    mylist.clear();
    std::cout<<p1<<std::endl;
    return 0;
}
