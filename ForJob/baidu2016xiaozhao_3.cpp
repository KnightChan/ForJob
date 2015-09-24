#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

namespace baidu2016xiaozhao3 {




int main()
{
	int n;
	cin >> n;
	int a, b, now = 0, ans = 0;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		now += b - a;
		ans = max(ans, now);
	}
	cout << ans << endl;
	return 0;
}
}