#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int mainbaidu2015intern1()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int ans = 0;
		int last = 0, now, n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> now;
			ans += abs(now - last);
			last = now;
		}
		ans += last;
		cout << ans * 2 << endl;
	}
	return 0;
}