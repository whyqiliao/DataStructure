#pragma once

#include<iostream>
using namespace std;
int main()
{
    int i,j,k;
    for(int n=100;n<1000;n++)
    {
        i=n/100;
        j=n/10-10*i;
        k=n%10;
        if (n==i*i*i+j*j*j+k*k*k)
        {
            cout<<n<<endl;
        }
    }
    return 0;
}
//110781201905065816
//1107842019070096