#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int f[10001];
int c[101], v[101];

int beibao01(int n, int bot, int top, int *c, int *v)
{
	memset(f, 0, sizeof(f));
	for (int i = 0; i < n; i++)
	{
		for (int j = top; j >= c[i]; j--)
			f[j] = max(f[j], f[j - c[i]] + v[i]);
	}
	int ans = 0;
	for (int j = bot; j <= top; j++)
		if (f[j] > ans) ans = f[j];
	return ans;
}

int main_baidu2015internAdd1()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int stc, bot, top;
		int ans = 0;
		cin >> stc >> bot >> top;
		for (int k = 0; k < stc; k++)
		{
			int n;
			cin >> n;
			for (int i = 0; i < n; i++)
				cin >> c[i] >> v[i];
			ans = max(ans, beibao01(n, bot, top, c, v));
		}
		cout << ans << endl;
	}
	return 0;
}