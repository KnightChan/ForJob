#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
#include <string>

using namespace std;
struct cmp
{
	bool operator()(const pair<string, int> &a, const pair<string, int> &b)
	{
		return a.second > b.second;
	}
};

int main1086()
{
	int n, m;
	cin >> n >> m;
	priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
	unordered_map<string, int> count_map;
	int priority = 0, cache_count = 0;
	for (int i = 0; i < n; i++)
	{
		string name;
		cin >> name;
		pq.push(make_pair(name, priority++));
		bool findIt = false;

		if (count_map.find(name) == count_map.end())
			count_map[name] = 0;
		if (count_map[name] == 0)
		{
			++cache_count;
			while (cache_count > m)
			{
				count_map[pq.top().first] --;
				if (count_map[pq.top().first] == 0)
					--cache_count;
				pq.pop();
			}
		}
		else if (count_map[name] > 0)
			findIt = true;
		count_map[name] = count_map[name] + 1;
		cout << (findIt ? "Cache" : "Internet") << endl;
	}
	return 0;
}