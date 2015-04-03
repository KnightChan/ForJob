#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <string>

using namespace std;

bool tryT(int t, int *d, int n)
{
	int count = 0, sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum = max(0, sum + t - d[i]);
		if (sum) ++count;
	}
	if (count * 2 > n)
		return true;
	return false;
}

int main()
{
	int N, K;
	cin >> N >> K;
	int *a = new int[N];
	for (int i = 0; i < N; i++)
		cin >> a[i];
	int l = 1, r = K + 1;
	while (l < r)
	{
		int mid = (l + r) / 2;
		if (tryT(mid, a, N))
			r = mid;
		else l = mid + 1;
	}
	cout << l << endl;
	delete[]a;
	return 0;
}