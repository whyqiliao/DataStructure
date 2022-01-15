#pragma once

#include<iostream>
using namespace std;
int main()
{
	for (int m = 2; m < 1000; m++)
	{
		int s = 0;
		for (int i = 1; i < m; i++)
		{
			if (m%i == 0)
			{
				s = s + i;
				if (s == m)
				{
					cout << m << "是完数 " << endl;
					cout << "它的因子是";
					for (int j = 1; j < m; j++)
					{
						if (m%j == 0) cout << j << " ";
					}
					cout << endl;
				}
			}
		}

	}
	return 0;
}