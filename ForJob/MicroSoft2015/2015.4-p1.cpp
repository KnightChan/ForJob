#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>

using namespace std;

bool check(int *t, int *c)
{
	int b[3];
	b[0] = abs(c[1] - c[0]);
	b[1] = abs(c[2] - c[0]);
	b[2] = abs(c[1] - c[2]);
	sort(b, b + 3);
	for (int i = 0; i < 3; i++)
		if (t[i] != b[i])
			return false;
	return true;
}

int main2015p1()
{
	int t[3];
	cin >> t[0] >> t[1] >> t[2];
	sort(t, t + 3);
	string s;
	cin >> s;
	int c[3] = { 0, 0, 0 };
	int ans = 0;
	for (auto ch : s)
	{
		if (ch == 'R')
			++c[0];
		else if (ch == 'B')
			++c[1];
		else if (ch == 'Y')
			++c[2];
		if (check(t, c))
		{
			ans = max(ans, c[0] + c[1] + c[2]);
			c[0] = 0;
			c[1] = 0;
			c[2] = 0;
		}
	}
	ans = max(ans, c[0] + c[1] + c[2]);
	cout << ans << endl;
	return 0;
}