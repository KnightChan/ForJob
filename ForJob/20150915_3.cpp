#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <stack>
#include <vector>

using namespace std;


namespace wangyi2016zhaopin_2 {
}

stack<pair<char, long long>> st;

string s;

int main()
{
	int T;
	cin >> T;
	getchar();
	for (int t = 0; t < T; t++)
	{
		getline(cin, s);
		//cout << s << endl;
		while (!st.empty()) st.pop();
		for (unsigned i = 0; i < s.length(); i++)
		{
			//cout << s[i] << "xxx" << endl;
			if (s[i] == ' ') continue;
			if (s[i] >= '0' && s[i] <= '9')
			{
				long long l = s[i] - '0';
				while (s[i + 1] >= '0' && s[i + 1] <= '9')
				{
					l = l * 10 + s[i + 1] - '0';
					i++;
				}
				st.push(make_pair('i', l));
			}else
			if (s[i] != ')')
			{
				st.push(make_pair(s[i], 0));
			}
			else//==)
			{
				stack<long long> ops;
				bool flag = false;
				long long ans = 0;
				while (!st.empty())
				{
					pair<char, long long> pa = st.top();
					st.pop();
					//cout << pa.first << pa.second << "---" << endl;
					if (pa.first == 'i')
					{
						ops.push(pa.second);
					}
					else if (pa.first == '(')
					{
						if (!flag) goto FIN;
						else st.push(make_pair('i', ans));
						flag = false;
						break;
					}
					else if (pa.first == '+')
					{
						if (ops.empty()) goto FIN;
						ans = 0;
						while (!ops.empty())
						{
							ans += ops.top();
							ops.pop();
						}
						flag = true;
					}
					else if (pa.first == '-')
					{
						if (ops.size() > 2) goto FIN;
						ans = 0;
						if (ops.size() == 1)
						{
							ans = -ops.top();
						}
						else
						{
							ans = ops.top();
							ops.pop();
							ans -= ops.top();
						}
						flag = true;
					}
					else if (pa.first == '*')
					{
						if (ops.size() < 2) goto FIN;
						ans = 1;
						while (!ops.empty())
						{
							ans *= ops.top();
							ops.pop();
						}
						flag = true;
					}
				}
			}
		}
		if (st.size() > 1 || st.empty())
		{
			goto FIN;
		}
		cout << st.top().second << endl;
		continue;
	FIN:
		cout << "invalid expression" << endl;
	}
	return 0;
}