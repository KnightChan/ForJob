#include <iostream>
#include <stdio.h>

using namespace std;

int main1()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		if (n < 3)
			cout << "NO" << endl;
		char c0 = '0', c1 = '0', c2 = '0', c;
		bool flag = false;
		for (int i = 0; i < n; i++)
		{
			cin >> c;
			if (c2 == c) continue;
			if (c0 == '0')
			{
				c0 = c;
				continue;
			}
			if (c1 == '0')
			{
				c1 = c;
				continue;
			}
			if (c2 != '0' && c2 != c)
			{
				c0 = c1;
				c1 = c2;
			}
			c2 = c;
			if (c2 - c1 == 1 && c1 - c0 == 1)
				flag = true;
		}
		cout << (flag ? "YES" : "NO") << endl;
	}
	return 0;
}