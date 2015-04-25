#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void mapadd(unordered_map<int, int> &m, int x)
{
	if (m.find(x) == m.end())
		m[x] = 0;
	m[x] ++;
}

void mapdel(unordered_map<int, int> &m, int x)
{
	if (m.find(x) == m.end())
		return;
	if (m[x] == 1)
	{
		auto t = m.find(x);
		m.erase(t);
	}else m[x] --;
}

int main()
{
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; tt++)
	{
		int n;
		cin >> n;
		vector<unordered_map<int, int>> g(n + 1, unordered_map<int, int>(0));
		vector<vector<int>> neighbor(n + 1, vector<int>(0));
		vector<int> color(n + 1, 0);
		for (int i = 0; i < n - 1; i++)
		{
			int x, y;
			cin >> x >> y;
			mapadd(g[x], 0);
			mapadd(g[y], 0);
			neighbor[x].push_back(y);
			neighbor[y].push_back(x);
		}
		int ans = 1;
		int q;
		cin >> q;
		printf("Case #%d:\n", tt);
		for (int i = 0; i < q; i++)
		{
			int k;
			cin >> k;
			if (k == 1)
			{
				printf("%d\n", ans);
				continue;
			}
			else if (k == 2)
			{
				int x, y;
				cin >> x >> y;
				int old = color[x];
				if (old == y)
					continue;
				if (g[x].find(old) != g[x].end())
				{
					ans += g[x][old];
				}
				if (g[x].find(y) != g[x].end())
					ans -= g[x][y];
				for (int nei : neighbor[x])
				{
					mapdel(g[nei], old);
					mapadd(g[nei], y);
				}
				color[x] = y;
			}
		}
	}
	return 0;
}