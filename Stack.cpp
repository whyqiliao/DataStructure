#pragma once

#include "Core.h"
#include <iostream>

//初始化栈
void InitStack(Sqstack &s)
{
    s.top = -1;
}
//判断栈空
bool IsEmpty(Sqstack s)
{
    if (s.top == -1)
        return true;
    else
        return false;
}
//进栈
bool Push(Sqstack &s, int x)
{
    if (s.top == MaxSize - 1)
        return false;
    s.data[++s.top] = x;
    return true;
}
//出栈
bool Pop(Sqstack &s, int &x)
{
    if (s.top == -1)
        return false;
    x = s.data[s.top--];
    return true;
}
//读栈顶元素
bool GetTop(Sqstack s, int &x)
{
    if (s.top == -1)
        return false;
    x = s.data[s.top];
    return true;
}
//栈的括号匹配(简化版)
int match(char *exp)
{
    Sqstack s;
    InitStack(s);
    int p, i = 0;
    while (exp[i] != '\0')
    {
        switch (exp[i])
        {
        case '(':
        {
            Push(s, '(');
            break;
        }
        case '{':
        {
            Push(s, '{');
            break;
        }
        case '[':
        {
            Push(s, '[');
            break;
        }
        case ')':
        {
            if (!IsEmpty(s))
            {
                Pop(s, p);
                if (p != '(')
                {
                    return 0;
                    break;
                }
            }
        }
        case '}':
        {
            if (!IsEmpty(s))
            {
                Pop(s, p);
                if (p != '{')
                {
                    return 0;
                    break;
                }
            }
        }
        case ']':
        {
            if (!IsEmpty(s))
            {
                Pop(s, p);
                if (p != '[')
                {
                    return 0;
                    break;
                }
            }
        }
        }
        i++;
    }
    //完成循环后如果栈空则匹配成功
    if (IsEmpty(s))
    {
        printf("Match\n");
        return 1;
    }
    else
    {
        printf("MisMatch\n");
        return 0;
    }
}
