#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <queue>


namespace wangyi2016zhaopin_4 {

using namespace std;

int main()
{
	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int n;
		cin >> n;
		priority_queue<int> qi;
		for (int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			qi.push(x);
		}
		int count = 0;
		while (qi.size() > 2)
		{
			int a = qi.top(); qi.pop();
			int b = qi.top(); qi.pop();
			int c = qi.top(); qi.pop();
			count += 1;
			if (--a) qi.push(a);
			if (--b) qi.push(b);
			if (--c) qi.push(c);
		}
		cout << count / 2 << endl;
	}
	return 0;
}
}