#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>

using namespace std;

int main_baiduintern2015add2()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		bool f[101];
		memset(f, false, sizeof(f));
		stack<int> st;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			int k;
			cin >> k;
			if (f[k])
			{
				while (st.top() != k)
				{
					f[st.top()] = false;
					st.pop();
				}
				st.pop();
			}
			st.push(k);
			f[k] = true;
		}
		while (st.size() > 1)
		{
			cout << st.top() << "->";
			st.pop();
		}
		cout << st.top() << endl;
	}
	return 0;
}