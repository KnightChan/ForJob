#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <unordered_map>

namespace zigesai_2{

using namespace std;

int f[1001][1001];
string s;
unordered_map<char, int> last_map;
int last[1001];
const int modi = 100007;
int main_zigesai2()
{
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		int ans = 0;
		cin >> s;
		int n = s.length();
		last_map.clear();
		memset(last, -1, sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
			auto x = last_map.find(s[i]);
			if (x != last_map.end())
			{
				last[i] = x->second;
			}
			last_map[s[i]] = i;
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				f[i][j] = 0;
		}
		for (int i = n - 1; i>=0; i--)
		{
			for (int j = i; j < n; j++)
			{
				f[i][j] += f[i + 1][j] + f[i][j - 1] - f[i + 1][j - 1];
				if (s[i] == s[j])
					f[i][j] += f[i + 1][j - 1] + 1;
				f[i][j] %= modi;
			}
		}
		printf("Case #%d: %d\n", tt, f[0][n - 1]);
		/*
		//on3
		int ans = 0;
		cin >> s;
		int n = s.length();
		last_map.clear();
		memset(last, -1, sizeof(int) * n);
		for (int i = 0; i < n; i++)
		{
		auto x = last_map.find(s[i]);
		if (x != last_map.end())
		{
		last[i] = x->second;
		}
		last_map[s[i]] = i;
		}
		for (int i = 0; i < n; i++)
		{
		for (int j = 0; j < n; j++)
		f[i][j] = 0;
		f[i][i] = 1;
		}

		for (int i = 1; i < n; i++)
		{
			for (int j = i - 1; j >= 0; j--)
			{
				int k = last[i];
				f[i][j] += f[i - 1][j] + 1;
				while (k >= j)
				{
					f[i][j] += (f[i - 1][k + 1] + 1) % modi;
					k = last[k];
				}
			}
		}
		
		
		printf("Case #%d: %d\n", tt, f[n - 1][0] % modi);
		*/
	}
	return 0;
}
}