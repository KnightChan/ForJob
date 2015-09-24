#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>

namespace chusai2_my{

using namespace std;

struct TriAngle
{
	double left, right, value;
	TriAngle(int l, int r, int v):left(l), right(r), value(v){}
};

vector<TriAngle> a[1000];

int main_chusai2()
{
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		double ans = 0;
		int n;
		for (int i = 0; i < n; i++)
		{
			double x, y;
		}
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}
}