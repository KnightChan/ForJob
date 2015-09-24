#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

namespace wangyi2016zhaopin_1{

const string s_t = "9706";
int start[4] = {0, 0, 0, 0};

int main()
{
	int T;
	cin >> T;
	string s;
	for (int t = 0; t < T; t++)
	{
		cin >> s;
		int count = 0;
		int now = 0;
		start[0] = 0;
		start[1] = 0;
		start[2] = 0;
		start[3] = 0;

		int i = 0;
		while (i < s.length())
		{
			if (s[i] == s_t[now])
			{
				start[now++] = i;
				if (now == s_t.length())
				{
					now = 0;
					count++;
				}
				i = start[now];
				if (now)
					i = max(i, start[now - 1]);
			}
			i++;
		}
		cout << count << endl;
	}
	return 0;
}
}