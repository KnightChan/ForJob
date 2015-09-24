#include <iostream>
#include <cstdio>
using namespace std;

namespace baidu2016xiaozhao1{

long long sum[200002];
long long t;
int n, c;

int main()
{
	cin >> n >> t >> c;
	sum[0] = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}
	int ans = 0;
	for (int i = 1; i + c - 1 <= n; i++)
	{
		if (sum[i + c - 1] - sum[i - 1] <= t)
			ans++;
	}
	cout << ans << endl;
	return 0;
}
}