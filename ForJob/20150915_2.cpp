#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;


namespace wangyi2016zhaopin_2 {

int dfs(string s)
{
	//cout << s << "::::*********" << endl;
	int count = 0;
	int last = 0;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			int l = s[i] - '0';
			while (s[i + 1] >= '0' && s[i + 1] <= '9')
			{
				l = l * 10 + s[i + 1] - '0';
				i++;
			}
			//cout << count << "bbbbb" << last << endl;
			count += last*l;
			last = 0;
		}
		else if (s[i] == '(')
		{
			int tmp = 1;
			for (int k = i + 1; k < s.length(); k++)
			{
				if (s[k] == '(') tmp++;
				if (s[k] == ')') tmp--;
				if (tmp == 0)
				{
					count += last;
					last = dfs(s.substr(i + 1, k - i - 1));
					i = k;
					break;
				}
			}
		}
		else
		{
			count += last;
			last=1;
		}
	}
	//cout << s << "::::" << count << ","<<last << endl;
	return count + last;
}

int main()
{
	int T;
	cin >> T;
	string s;
	for (int t = 0; t < T; t++)
	{
		cin >> s;
		cout << dfs(s) << endl;
	}
	return 0;
}
}