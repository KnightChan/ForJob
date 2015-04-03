#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <string>
#include <math.h>

using namespace std;

int main2015p2()
{
	int N, M, T;
	cin >> T;
	for (int ttt = 0; ttt < T;ttt ++)
	{
		cin >> N >> M;
		unordered_map<int, vector<int>> signals;
		vector<int> startCount;
		unordered_map<int, vector<int>> signalToIndexs;
		vector<int> startS;
		for (int i = 0; i < M; i++)
		{
			int a;
			cin >> a;
			startS.push_back(a);
		}
		for (int i = 0; i < N; i++)
		{
			int a, t;
			cin >> a >> t;
			for (int j = 0; j < t; j++)
			{
				int x;
				cin >> x;
				signals[a].push_back(x);
			}
			signalToIndexs[a].push_back(i);
			startCount.push_back(0);
		}
		queue<vector<int>> q;
		q.push(startS);
		while (!q.empty())
		{
			vector<int> v = q.front();
			q.pop();
			for (int s : v)
			{
				q.push(signals[s]);
				for (int m : signalToIndexs[s])
					startCount[m] = (startCount[m] + 1) % 142857;
			}
		}
		for (int i = 0; i < N - 1; i++)
		{
			cout << startCount[i] << " ";
		}
		cout << startCount[N - 1] << endl;
	}
	return 0;
}