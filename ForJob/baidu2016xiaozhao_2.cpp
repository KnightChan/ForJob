#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

namespace baidu2016xiaozhao2 {


int m, n;
vector<int> map[1001][1001];

void big_add(vector<int> &a, vector<int> b)
{
	int lena = min(a.size(), b.size());
	for (int i = 0; i < lena; i++)
	{
		a[i] += b[i];
	}
	if (a.size() < b.size())
	{
		for (int i = lena; i < b.size(); i++)
			a.push_back(b[i]);
	}
	
	for (int i = 0; i < a.size() - 1; i++)
	if (a[i] > 9999999)
	{
		a[i + 1] ++;
		a[i] -= 10000000;
	}
	if (a[a.size() - 1] > 9999999)
	{
		a[a.size() - 1] -= 10000000;
		a.push_back(1);
	}
}

int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			int a = 1;
			cin >> a;
			map[i][j].push_back(a);
		}
	for (int i = m - 1; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j][0] == 0)
			{
				continue;
			}
			if (i == m - 1 && j == 0)
			{
				continue;
			}
			if (i == m - 1 && map[i][j][0])
			{
				map[i][j][0] = 0;
				big_add(map[i][j], map[i][j - 1]);
				continue;
			}
			if (j == 0 && map[i][j][0])
			{
				map[i][j][0] = 0;
				big_add(map[i][j], map[i + 1][j]);
				continue;
			}
			if (map[i][j][0])
			{
				map[i][j][0] = 0;
				big_add(map[i][j], map[i + 1][j]);
				big_add(map[i][j], map[i][j - 1]);
				big_add(map[i][j], map[i + 1][j - 1]);
			}
		}
	}
	cout << map[0][n - 1][map[0][n - 1].size() - 1];
	for (int i = map[0][n - 1].size() - 2; i >= 0; i--)
	{
		if (map[0][n - 1][i] < 1000000)
			cout << "0";
		if (map[0][n - 1][i] < 100000)
			cout << "0";
		if (map[0][n - 1][i] < 10000)
			cout << "0";
		if (map[0][n - 1][i] < 1000)
			cout << "0";
		if (map[0][n - 1][i] < 100)
			cout << "0";
		if (map[0][n - 1][i] < 10)
			cout << "0";
		cout << map[0][n - 1][i];
	}
	cout << endl;
	return 0;
}
}