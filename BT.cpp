#include <iostream>
#include "Core.h"
//省略顺序存储结构二叉树，这种储存结构只适合用于完全二叉树

//O(log2n)二叉排序树查找
void BinarySearchTreeInsert(BTNode *t, int x)
{
    BTNode *f,*p=t;
    while (p != nullptr)
    {
        if (p->data == x)
            break;
        f = p;
        if (p->data > x)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (!p)
    {
        p = new BTNode;
        p->data = x;
        p->lchild = nullptr;
        p->rchild = nullptr;
        if (f->data > x)
            f->lchild = p;
        else
            f->rchild = p;
    }
    else
    {
        //todo
    }
}

//对节点的访问操作
void Visit(BTNode *p)
{
    std::cout << p->data << std::endl;
}
//先序遍历
void preorder(BTNode *p)
{
    if (p != nullptr)
    {
        Visit(p);

        preorder(p->lchild);
        preorder(p->rchild);
    }
}
//中序遍历
void inorder(BTNode *p)
{
    if (p != nullptr)
    {
        inorder(p->lchild);
        Visit(p);
        inorder(p->rchild);
    }
}
//后序遍历
void postorder(BTNode *p)
{
    if (p != nullptr)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        Visit(p);
    }
}

//表达式求值 先求A表达式的值，然后求B表达式的值，最后进行对A,B表达式的处理（此处为乘法）
int op(int A, int B, char C)
{
    if (C == '*')
    {
        return A * B;
    }
    if (C == '+')
    {
        return A + B;
    }
    if (C == '-')
    {
        return A - B;
    }
    if (C == '/' && B != 0)
    {
        return A / B;
    }
    return -1;
}
int comp(BTNode *p)
{
    int A, B;
    if (p != nullptr)
    {
        if (p->lchild != nullptr && p->rchild != nullptr)
        {
            A = comp(p->lchild);
            B = comp(p->rchild);
            return A * B;
        }
        else
        {
            //如果当前节点的左右孩子都为空，则该节点是叶子节点，是数值，直接返回该节点的数值
            return p->data - '0';
        }
    }
    else
        return 0; //空树
}

//求二叉树深度
int getdepth(BTNode *p)
{
    int LD, RD;
    if (p == nullptr)
    {
        return 0; //空树
    }
    else
    {
        LD = getdepth(p->lchild);
        RD = getdepth(p->rchild);
        return (LD > RD ? LD : RD) + 1;
    }
}

//二叉树查找data域等于key的节点是否存在（返回第一个满足条件的节点）
//假设二叉树存在且指向根节点
//该方法含“剪枝操作”
void search(BTNode *p, BTNode *&q, int key)
{
    if (p != nullptr) //如果p是空树则什么都不做，q保持空值
    {
        if (p->data == key)
            q = p; //如果p所指的节点data域等于key，则将p赋值给q，q指向域值等于key的节点p
        else
        {
            search(p->lchild, q, key); //左子树中查找
            if (q == nullptr)
                search(p->rchild, q, key); //左子树中找不到才在右子树中查找
        }
    }
}

//只有前后遍历不能确定一颗二叉树，因为逆后续遍历是先序遍历中对左右子树遍历顺序交换后得到的结果

//层次遍历
void level(BTNode *p)
{
    int front = 0, rear = 0;
    BTNode *que[MaxSize];
    BTNode *q;
    if (p != nullptr)
    {
        rear = (rear + 1) % MaxSize;
        que[rear] = p;        //根节点入队列
        while (front != rear) //队列不为空才进行出入队循环
        {
            front = (front + 1) % MaxSize;
            q = que[front]; //队头节点出队
            Visit(q);

            //如果左/右子树不为空，则将左/右子树的根结点入队
            if (q->lchild != nullptr)
            {
                rear = (rear + 1) % MaxSize;
                que[rear] = q->lchild;
            }
            if (q->rchild != nullptr)
            {
                rear = (rear + 1) % MaxSize;
                que[rear] = q->rchild;
            }
        }
    }
}

//层次遍历求二叉树宽度

int MaxNode(BTNode *p)
{
    St que[MaxSize];
    int front = 0, rear = 0;
    int Lno = 0;
    BTNode *q;

    if (p != nullptr)
    {
        /*先层次遍历一次，求二叉树的层数*/
        ++rear;
        que[rear].p = p;   //树根入队
        que[rear].lno = 1; //根所在的层次号为1
        while (front != rear)
        {
            ++front;
            q = que[front].p;
            Lno = que[front].lno;
            if (q->lchild != nullptr)
            {
                ++rear;
                que[rear].p = q->lchild;
                que[rear].lno = Lno + 1;
            }
            if (q->rchild != nullptr)
            {
                ++rear;
                que[rear].p = q->rchild;
                que[rear].lno = Lno + 1;
            }
        } //循环结束时，Lno为该二叉树的层数

        /*找出含有节点最多的层，并算出其节点数*/
        int max = 0, n = 0;
        for (int i = 1; i <= Lno; i++)
        {
            for (int j = 0; j < rear; j++)
            {
                if (que[j].lno == i)
                    ++n;
                if (max < n)
                    max = n;
            }
        }
        return max;
    }
    else
        return 0; //空树返回0
}

//二叉树深度优先遍历算法的非递归实现
//先序遍历
void preorderNonrecursion(BTNode *bt)
{
    if (bt != nullptr)
    {
        BTNode *Stack[MaxSize];
        int top = -1;
        BTNode *p;
        Stack[++top] = bt;
        while (top != -1)
        {
            p = Stack[top--];
            Visit(p);
            //注意，由于栈结构先进后出，所以要右子树先入栈，才能实现左子树先出栈，即根左右
            if (p->rchild != nullptr)
            {
                Stack[++top] = p->rchild;
            }
            if (p->lchild != nullptr)
            {
                Stack[++top] = p->lchild;
            }
        }
    }
}
//中序遍历
void inorderNonrecursion(BTNode *bt)
{
    if (bt != nullptr)
    {
        BTNode *Stack[MaxSize];
        int top = -1;
        BTNode *p;
        p = bt;
        /*由于出栈过程中，根节点出栈，栈空，右子树还没加进来，遍历还没结束，所以需要添加p非空判定*/
        while (top != -1 || p != nullptr)
        {
            while (p != nullptr)
            {
                Stack[++top] = p;
                p = p->lchild;
            }
            if (top != -1)
            {
                p = Stack[top--];
                Visit(p);
                p = p->rchild;
            }
        }
    }
}

/*由逆后序遍历为先序遍历过程中对左右子树遍历顺序交换得到的结果得到后序遍历结果*/
/*用到两个栈，一个用来做逆后序遍历，另一个用来存出栈结果，出栈结果出栈得到后序遍历序列*/
void postorderNonrecursion(BTNode *bt)
{
    if (bt != nullptr)
    {
        BTNode *stack1[MaxSize], *stack2[MaxSize];
        int top1 = -1, top2 = -1;
        BTNode *p;

        stack1[++top1] = bt; //根节点入栈
        //左右子树遍历顺序变换后压stack2栈
        while (top1 != -1)
        {
            p = stack1[top1--];
            stack2[++top2] = p;
            if (p->lchild != nullptr)
            {
                stack2[++top2] = p->lchild;
            }
            if (p->rchild != nullptr)
            {
                stack2[++top2] = p->rchild;
            }
        }

        //stack2出栈
        while (top2 != -1)
        {
            p = stack2[top2--];
            Visit(p);
        }
    }
}

/*线索二叉树*/
/*二叉树被线索化之后近似于一个线性结构，分支结构的遍历操作就转化为了近似于线性结构的遍历操作，通过线索的辅助使得寻找当前节点前驱或者后继的平均销量大大提高*/

void Visit(TBTNode *p)
{
    std::cout << p->data << std::endl;
}
//二叉树中序线索化
void InThread(TBTNode *p, TBTNode *&pre)
{
    if (p != nullptr)
    {
        //递归，左子树线索化
        InThread(p->rchild, pre);
        if (p->lchild == nullptr)
        {
            p->lchild = pre;
            p->ltag = 1;
        }
        if (pre != nullptr && pre->rchild == nullptr)
        {
            pre->rchild = p;
            pre->rtag = 1;
        }
        //pre指向当前的p，作为p将要指向的下一个节点的前驱
        pre = p;
        //递归，右子树线索化
        InThread(p->rchild, pre);
    }
}

//通过中序遍历建立中序线索二叉树
void createInThread(TBTNode *root)
{
    TBTNode *pre = nullptr;
    if (root != nullptr)
    {
        InThread(root, pre);
        pre->rchild = nullptr;
        pre->rtag = 1;
    }
}

//遍历中序线索二叉树
//以p为根的中序线索二叉树中，中序序列下的第一个节点（最左下节点，但不一定是叶子节点）
TBTNode *First(TBTNode *p)
{
    while (p->ltag == 0)
    {
        p = p->lchild;
    }
    return p;
}
//求中序序列下最后一个节点
TBTNode *Last(TBTNode *p)
{
    while (p->rtag == 0)
    {
        p = p->rchild;
    }
    return p;
}
//在中序线索二叉树中，节点p在中序下的后继节点
TBTNode *Next(TBTNode *p)
{
    if (p->rtag == 0)
        return First(p->rchild);
    else
        return p->rchild; //rtag==1直接返回后继线索
}
//节点p在中序下的前驱节点
TBTNode *Prior(TBTNode *p)
{
    if (p->ltag == 0)
    {
        return Last(p->lchild);
    }
    else
    {
        return p->rchild;
    }
}

//中序线索二叉树执行中序遍历
void Inorder(TBTNode *root)
{
    for (TBTNode *p = First(root); p != nullptr; p = Next(p))
        Visit(p);
}