#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

bool lower(char c)
{
	if (c >= 'a' && c <= 'z') return true;
	return false;
}

long long calc_v(char c, long long k)
{
	long long x = 0;
	if (lower(c)) x = c - 'a' + 1;
	else x = c - 'A' + 1;
	return k * k * x;
}

bool equal(char a, char b)
{
	if (!lower(a)) a = a - 'A' + 'a';
	if (!lower(b)) b = b - 'A' + 'a';
	return a == b;
}

int main_baidu2015intern2()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		long long ans = 0;
		string s;
		cin >> s;
		s.push_back('@');
		if (s.length() == 0)
		{
			cout << 0 << endl;
			continue;
		}
		char nowc = s[0];
		long long count = lower(nowc)?1:2;
		for (int i = 1; i < s.length(); i++)
		{
			if (!equal(s[i], nowc))
			{
				ans += calc_v(nowc, count);
				nowc = s[i];
				count = 0;
			}
			count++;
			if (!lower(s[i])) count++;
		}
		cout << ans << endl;
	}
	return 0;
}